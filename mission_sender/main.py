
import sys

from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine, qmlRegisterSingletonInstance
from utils import read_mission, encode_mission, sign, verify, generate_keys, save_keys, save_public_key, get_key
from utilshandler import UtilsHandler

KEY_SIZE = 1024

def main():
    public, private = generate_keys(KEY_SIZE)
    save_keys(public, private, 'mp')
    
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()
    
    utilsHandler = UtilsHandler()
    qmlRegisterSingletonInstance(UtilsHandler, 'G.UtilsHandler', 1, 0, 'UtilsHandler', utilsHandler)
    
    engine.load('./QML/Main.qml')
    if not engine.rootObjects():
        sys.exit(-1)
    app.exec()

if __name__ == '__main__':
    main()


