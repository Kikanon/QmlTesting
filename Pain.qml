import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.2
import "."


Window {
    id: screen
    title:"MainWindow"
    width: 720; height: 720

    SystemPalette { id: activePalette }

    Item {
        width: parent.width
        anchors { top: parent.top; bottom: toolBar.top }
    }

    Rectangle {
        id: toolBar
        x: 0
        y: 0
        width: 238
        height: 720
        color: activePalette.window
        anchors.bottom: screen.bottom
        anchors.bottomMargin: 0

        Button {
            width: 139
            height: 42
            anchors { left: parent.left; verticalCenter: parent.verticalCenter }
            text: "Test"
            anchors.verticalCenterOffset: -331
            anchors.leftMargin: 8
            onClicked: console.log("This doesn't do anything yet...")//signal ki ga posle gumb
        }


        Button {
            width: 139
            height: 42
            anchors { left: parent.left; verticalCenter: parent.verticalCenter }
            text: "Datoteke"
            anchors.verticalCenterOffset: -283
            anchors.leftMargin: 8
            onClicked: fileDialog.open()
        }

        FileDialog{//okno za datoteke ko ga drugace ne vidimo
                id: fileDialog
                title: "Kraja datotek"
                selectMultiple: true
                selectFolder: false
                nameFilters: "*.pdf , *"
                onAccepted:{
                    selectMultiple ?
                    console.log(this.fileUrls)
                              :
                    t.text = this.fileUrl
                }

            }
    }
}

