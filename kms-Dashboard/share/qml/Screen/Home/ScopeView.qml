import QtQuick 2.0
import QtCharts 2.1
import QmlCustomItem 1.0

ChartView {
    id: chartView
    animationOptions: ChartView.NoAnimation
    theme: ChartView.ChartThemeDark
    property bool openGL: true
    property bool openGLSupported: true

    Component.onCompleted: {
        if (!series("signal 1").useOpenGL) {
            openGLSupported = false
            openGL = false
        }
    }

    ValueAxis {
        id: axisY1
        min: -1
        max: 4
    }

    ValueAxis {
        id: axisY2
        min: -10
        max: 5
    }

    ValueAxis {
        id: axisX
        min: 0
        max: 1024
    }

    LineSeries {
        id: lineSeries1
        name: "Temperature"
        axisX: axisX
        axisY: axisY1
        useOpenGL: chartView.openGL
    }
    LineSeries {
        id: lineSeries2
        name: "Humidity"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }

    Connections {
        target: AppModel
        onSensorMessChanged: updateData(AppModel.sensorMess)
    }

    function updateData(msg) {
        temp = msg;
        console.log(temp);
        dataSource.update(chartView.series(Math.random()));
        dataSource.update(chartView.series(Math.random()));
    }

}
