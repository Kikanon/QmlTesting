import QtQuick 2.0

Item {//kocka z slikico
    id: block

    Image {
        id: img
        anchors.fill: parent
        source: "pics/redDot.png"
    }
}
