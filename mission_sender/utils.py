from hashlib import sha256
from Crypto import Random
from Crypto.PublicKey import RSA

PATH_TO_KEYS = './keys'

def read_mission(aFileName: str) -> list:
    
    print("\nReading mission from file: %s" % aFileName)
    missionlist=[]
    with open(aFileName) as f:
        for i, line in enumerate(f):
            if i==0:
                if not line.startswith('QGC WPL 110'):
                    raise Exception('File is not supported WP version')
            else:
                linearray=line.split('\t')
                ln_index=int(linearray[0])
                ln_currentwp=int(linearray[1])
                ln_frame=int(linearray[2])
                ln_command=int(linearray[3])
                ln_param1=float(linearray[4])
                ln_param2=float(linearray[5])
                #ln_param3=float(linearray[6])
                #ln_param4=float(linearray[7])
                ln_param5=float(linearray[8])
                ln_param6=float(linearray[9])
                ln_param7=float(linearray[10])
                #ln_autocontinue=int(linearray[11].strip())
                
                if ln_index == 0 and ln_currentwp == 1 and ln_frame == 0:
                    cmd = home_handler(lat=ln_param5, lon=ln_param6, alt=ln_param7)
                elif ln_command == 22:
                    cmd = takeoff_handler(alt=ln_param7)
                elif ln_command == 16:
                    cmd = waypoint_handler(hold=ln_param1, lat=ln_param5, lon=ln_param6, alt=ln_param7)
                elif ln_command == 183:
                    cmd = servo_handler(number=ln_param1, pwm=ln_param2)
                elif ln_command == 21:
                    if len(missionlist) != 0 and missionlist[0][0] == 'H':
                        drone_home = missionlist[0]
                    else:
                        drone_home = None
                    cmd = land_handler(lat=ln_param5, lon=ln_param6, alt=ln_param7, home=drone_home)
                else:
                    print('Ошибка: использована неизвестная команда. Список разрешенных команд: 16, 21, 22, 183.')
                    missionlist = []
                    break
                
                missionlist.append(cmd)
    return missionlist

def home_handler(lat: float, lon: float, alt: float) -> list:
    return ['H', str(lat), str(lon), str(alt)]

def takeoff_handler(alt: float) -> list:
    return ['T', str(alt)]

def waypoint_handler(hold: float, lat: float, lon: float, alt: float) -> list:
    return ['W', str(hold), str(lat), str(lon), str(alt)]

def servo_handler(number: float, pwm: float) -> list:
    return ['S', str(number), str(pwm)]

def land_handler(lat: float, lon: float, alt: float, home: list = None) -> list:
    if home == None:
        ret_lat = str(lat)
        ret_lon = str(lon)
        ret_alt = str(alt)
    else:
        ret_lat = home[1] if lat == 0. else str(lat)
        ret_lon = home[2] if lon == 0. else str(lon)
        ret_alt = home[3] if alt == 0. else str(alt)
    
    return ['L', ret_lat, ret_lon, ret_alt]

def encode_mission(mission_list: list) -> str:
    for idx, cmd in enumerate(mission_list):
        mission_list[idx] = f'{cmd[0]}' + '_'.join(cmd[1:])
    mission = '&'.join(mission_list)
    
    return mission


def sign(message: str, key_group: str) -> int:
    n, d = get_key(key_group, private=True)
    msg_bytes = message.encode()
    hash = int.from_bytes(sha256(msg_bytes).digest(), byteorder='big', signed=False)
    signature = pow(hash, d, n)
    
    return signature

def verify(message: str, signature: int, key_group: str) -> bool:
    n, e = get_key(key_group, private=False)
    msg_bytes = message.encode()
    hash = int.from_bytes(sha256(msg_bytes).digest(), byteorder='big', signed=False)
    hashFromSignature = pow(signature, e, n)
    return hash == hashFromSignature

def get_key(key_group: str, private: bool) -> list:
    path = f'{PATH_TO_KEYS}/{key_group}.txt'
    with open(path, 'r') as kf:
        data = kf.read()
        keys = data.split('\n')
        keys = list(map(lambda k: int(k, 16), keys))
    if len(keys) == 3 and private:
        return keys[0], keys[2]
    else:
        return keys[:2]

def generate_keys(keysize: int) -> list:
    random_generator = Random.new().read
    key = RSA.generate(keysize, random_generator)
    private, public = key, key.publickey()
    return public, private

def save_keys(public: RSA.RsaKey, private: RSA.RsaKey, key_group: str) -> None:
    path = f'{PATH_TO_KEYS}/{key_group}.txt'
    lines_to_write = list(map(hex, [public.n, public.e, private.d]))
    with open(path, 'w') as kf:
        kf.write("\n".join(lines_to_write))
        
def save_public_key(n: str, e: str, key_group: str) -> None:
    path = f'{PATH_TO_KEYS}/{key_group}.txt'
    lines_to_write = [n, e]
    with open(path, 'w') as kf:
        kf.write("\n".join(lines_to_write))