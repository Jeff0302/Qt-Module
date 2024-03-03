# QXlsx.pro

contains(QT_ARCH, i386){        # 使用32位编译器
DESTDIR = $$PWD/bin             # 程序输出路径
}else{
message("64bit")                # 使用64位编译器
DESTDIR = $$PWD/bin64
}
win32:CONFIG(release, debug|release): TARGET = QXlsx        # 生成release版本静态库名称
else:win32:CONFIG(debug, debug|release): TARGET = QXlsxd    # 生成debug版本静态库名称

#TARGET = QXlsx
TEMPLATE = lib
CONFIG += staticlib
QT += core
QT += gui-private

#####################################################################
# set debug/release build environment
#
# CONFIG += debug_and_release
# release: DESTDIR = lib-release
# debug: DESTDIR = lib-debug

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QXLSX_PARENTPATH=$$PWD/
QXLSX_HEADERPATH=$$PWD/header/
QXLSX_SOURCEPATH=$$PWD/source/
include($$PWD/QXlsx.pri)


