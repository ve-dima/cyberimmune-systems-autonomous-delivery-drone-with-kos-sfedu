import requests
from utils import read_mission, encode_mission, sign, verify, generate_keys, save_keys, save_public_key, get_key

from PySide6.QtCore import Slot, QObject, Signal

MCC_IP = 'http://192.168.1.78'

class UtilsHandler(QObject):
    missionSent = Signal(str)
    
    def __init__(self):
        super().__init__()
    
    @Slot(str, str)
    def send_mission(self, id, mission_path):
        if mission_path[:4] == 'file':
            mission_path = mission_path[8:]
        n, e = get_key('mp', private=False)
        n, e = list(map(hex, (n, e)))

        url = f'{MCC_IP}/key_exchange?id={id}&group=mp&n={n}&e={e}'
        x = requests.get(url)
        x = x.text
        _, mcc_n, mcc_e = x.split(' ')
        mcc_n, mcc_e = list(map(lambda k: f'0x{k}', (mcc_n, mcc_e)))
        save_public_key(mcc_n, mcc_e, 'mcc')

        mission_list = read_mission(mission_path)
        if len(mission_list) != 0:
            mission = encode_mission(mission_list)
            
            signature = sign(f'{id}_{mission}', key_group='mp')

            str_to_send = f'{id}_{mission}#{hex(signature)}'

            url = f'{MCC_IP}/fmission_mp'

            x = requests.post(url, data=str_to_send.encode())
            x = x.text
            body, signature = x.split('#')
            is_answer_safe = verify(body, int('0x' + signature, 16), key_group='mcc')
            print(f'Верификация ответа = {is_answer_safe}')
            if is_answer_safe:
                self.missionSent.emit(body)