QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

TRANSLATIONS += \
    FTDI_example_zh_TW.ts
CONFIG += lrelease
CONFIG += embed_translations


win32: LIBS += -L$$PWD/lib/ -lftd2xx

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
