import QtQuick 2.0
import QtLocation 5.12
import QtPositioning 5.12
import "../../Component"
import "../../Component/Common"

QRec{

    id: mapScreen

    color: CONST.COLOR_BACK_GROUND

    property MapQuickItem item

    PositionSource{
        id: src
        updateInterval: 1000
        active: false

        onPositionChanged: {
            var coord = src.position.coordinate

            map.center = coord
            item.coordinate = coord
        }
    }

    Plugin{
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        zoomLevel: 14
        minimumZoomLevel: 6
        maximumZoomLevel: 18
        copyrightsVisible: false
        gesture.enabled: true
        gesture.acceptedGestures: MapGestureArea.PinchGesture | MapGestureArea.PanGesture
    }

    Component.onCompleted: {
        map.center = QtPositioning.coordinate(21.037754272248186, 105.78183516295135)
        map.zoomLevel = 12

        var component = Qt.createComponent("marker.qml")
        item = component.createObject(mapScreen, { coordinate: QtPositioning.coordinate(21.037754272248186, 105.78183516295135) })
        map.addMapItem(item)

        src.active = true
    }
}
