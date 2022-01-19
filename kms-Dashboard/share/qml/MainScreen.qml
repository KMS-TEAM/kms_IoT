import QtQuick 2.0
import QtQuick.Window 2.12

Window {

    id: root

    visible: true
    width: 500
    height: 500

    Rectangle {
        anchors.fill: parent
        Text {
            id: textLabel
            text: "Main Screen"
            color: "purple"
            font.pointSize: 20
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
