import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import MqttClient 1.0
import "../../Component/Common"
import "../../Component"
import QmlCustomItem 1.0

//QRec {
//    visible: true
//    id: root
//    color: CONST.COLOR_BACK_GROUND

//    Text {
//        id: sensorMessage
//        anchors.centerIn: root
//        text: qsTr(AppModel.sensorMess)
//    }
//}

//![1]
QRec {
    id: homeScreen
    width: 600
    height: 400

    color: CONST.COLOR_BACK_GROUND


    ScopeView {
        id: scopeView
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: controlPanel.right
        height: main.height

        onOpenGLSupportedChanged: {
            if (!openGLSupported) {
                controlPanel.openGLButton.enabled = false
                controlPanel.openGLButton.currentSelection = 0
            }
        }
    }

}
