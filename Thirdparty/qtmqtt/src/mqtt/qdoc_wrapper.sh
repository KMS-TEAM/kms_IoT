#!/bin/sh
QT_VERSION=5.15.2
export QT_VERSION
QT_VER=5.15
export QT_VER
QT_VERSION_TAG=5152
export QT_VERSION_TAG
QT_INSTALL_DOCS=/home/lacie/Qt/Docs/Qt-5.15.2
export QT_INSTALL_DOCS
BUILDDIR=/home/lacie/Github/kms_IoT/Thirdparty/qtmqtt/src/mqtt
export BUILDDIR
exec /home/lacie/Qt/5.15.2/gcc_64/bin/qdoc "$@"
