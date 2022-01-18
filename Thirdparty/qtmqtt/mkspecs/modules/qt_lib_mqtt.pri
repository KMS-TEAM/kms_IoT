QT_MODULE_BIN_BASE = /home/lacie/Github/kms_IoT/Thirdparty/qtmqtt/bin
QT_MODULE_INCLUDE_BASE = /home/lacie/Github/kms_IoT/Thirdparty/qtmqtt/include
QT_MODULE_LIB_BASE = /home/lacie/Github/kms_IoT/Thirdparty/qtmqtt/lib
QT_MODULE_HOST_LIB_BASE = /home/lacie/Github/kms_IoT/Thirdparty/qtmqtt/lib
include(/home/lacie/Github/kms_IoT/Thirdparty/qtmqtt/mkspecs/modules-inst/qt_lib_mqtt.pri)
QT.mqtt.priority = 1
include(/home/lacie/Github/kms_IoT/Thirdparty/qtmqtt/mkspecs/modules-inst/qt_lib_mqtt_private.pri)
QT.mqtt_private.priority = 1
