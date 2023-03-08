import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtCharts 2.1

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

QRec {
    id: homeScreen
    color: CONST.COLOR_BACK_GROUND

    ChartView {
        id: chartView

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        height: homeScreen.height - 10

        animationOptions: ChartView.NoAnimation
        theme: ChartView.ChartThemeDark
        property bool openGL: false
        property bool openGLSupported: false

        property int tempSamples : 0
        property bool firstTemp : true
        property int humtySamples : 0
        property bool firstHumty: true

        x: 8
        y: 9

        function tempMessage(payload)
        {
            if (tempSamples <= 100){
                if (firstTemp){
                    timeAxis.min = new Date()
                    firstTemp = false
                }
                timeAxis.max = new Date()
                if (payload >= axisY.max){
                    axisY.max = payload + 5
                }
                if (payload < axisY.min){
                    axisY.min= payload - 5
                }

                tempSeries.append(new Date(),payload)
                tempSamples++
            }else{
                tempSeries.remove(0)
                timeAxis.min = new Date(tempSeries.at(0).x)
                if (payload >= axisY.max){
                    axisY.max = payload + 5
                }
                if (payload < axisY.min){
                    axisY.min= payload - 5
                }
                tempSeries.append(new Date(),payload)
            }
        }
        function humtyMessage(payload)
        {
            if (humtySamples <= 100){
                if (firstHumty){
                    timeAxis.min = new Date()
                    firstHumty = false
                }
                timeAxis.max = new Date()
                humtySeries.append(new Date(),payload)
                humtySamples++
            }else{
                humtySeries.remove(0)
                timeAxis.min = new Date(humtySeries.at(0).x)
                timeAxis.max = new Date()
                humtySeries.append(new Date(),payload)
            }

        }

        ValueAxis {
            id: axisY1
            min: 0
            max: 100
        }

        ValueAxis {
            id: axisY2
            min: 0
            max: 100
        }

        DateTimeAxis {
            id: timeAxis
            format: "hh:mm"
            //min: startDate
            //max: startDate
                        }
        SplineSeries {
            name: "Temperature"
            id: tempSeries
            useOpenGL: true
            axisY: axisY1
            //axisX: axisX
            axisX: timeAxis
        }
        SplineSeries {
            name: "Humidity"
            id: humtySeries
            useOpenGL: true
            axisYRight: axisY2
            //axisX: axisX
            axisX: timeAxis
        }

        Connections {
            target: AppModel
            function onSensorMessChanged(msg) {
                var temp = msg;
                console.log(temp);
                // TODO: Extract data to chart view
                chartView.tempMessage(Math.floor(Math.random()*30 + 15))
                chartView.humtyMessage(Math.floor(Math.random()*90 + 40))
            }
        }
    }
}
