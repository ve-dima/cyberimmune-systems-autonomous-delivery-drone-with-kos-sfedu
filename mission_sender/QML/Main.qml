import QtQuick 6.6
import QtQuick.Controls 6.6
import QtQuick.Layouts 6.6
import QtCore 6.6
import QtQuick.Controls.Material 6.6
import QtQuick.Dialogs 6.6
import G.UtilsHandler 1.0

ApplicationWindow {
    id: window
    width: 640
    height: 320
    title: qsTr('Mission sender')
    visible: true

    property variant mission_path: ''

    ColumnLayout {
        id: main_panel
        spacing: 0
        width: parent.width
        // Image {
        //     id: k_logo
        //     Layout.alignment: Qt.AlignHCenter
        //     scale: 0.7
        //     Layout.preferredHeight: 80
        //     fillMode: Image.PreserveAspectFit; clip: true
        //     source: "../resources/Kaspersky_logo.svg"
        // }

        GridLayout {
            Layout.alignment: Qt.AlignHCenter
            columns: 2
            Text {
                id: label1
                text: qsTr("ID:")
            }
            TextField {
                id: input1
                text: qsTr("")
            }
            Text {
                id: label2
                text: qsTr("Путь к миссии:")
            }
            Button {
                id: fileDialogButton
                text: qsTr("&Задать...")
                onClicked: {
                    fileDialog.open()
                }
            }
        }
        Text {
            Layout.alignment: Qt.AlignHCenter
            id: label3
            text: mission_path
        }
        Button {
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 12
            id: missionSendButton
            enabled: false
            text: qsTr("&Отправить миссию")
            onClicked: {
                if (input1.text != '') {
                    UtilsHandler.send_mission(input1.text, mission_path)
                }
            }
        }
    }

    FileDialog {
        id: fileDialog
        currentFolder: StandardPaths.standardLocations(StandardPaths.DesktopLocation)[0]
        onAccepted: {
            mission_path = String(selectedFile)
            missionSendButton.enabled = true
        }
    }

    MessageDialog {
        id: messageDialog
        title: "Информация"
        text: "Миссия отправлена"
        buttons: MessageDialog.Ok
        onAccepted: messageDialog.visible = false
    }

    Connections {
        target: UtilsHandler
        function onMissionSent(response) {
            messageDialog.visible = true
        }
    }

}