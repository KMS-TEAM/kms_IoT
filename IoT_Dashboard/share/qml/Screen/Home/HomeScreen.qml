import QtQuick 2.0
import "../../Component"
import "../../Component/Common"
import QmlCustomItem 1.0

QRec {
    id: homeScreen
    color: CONST.COLOR_BACK_GROUND

    QSwitchButton {
        id: swipeTab
        width: 50
        height: 50
        radius: 20
        anchors.top: parent
        anchors.topMargin: 10
        anchors.rightMargin: 10
    }
}
