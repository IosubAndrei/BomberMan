QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomb.cpp \
    bombpowerup.cpp \
    destroyableblock.cpp \
    explosion.cpp \
    explosionpowerup.cpp \
    field.cpp \
    healthpowerup.cpp \
    main.cpp \
    bomberman_dialog.cpp \
    player.cpp \
    playingground.cpp \
    registerwindow.cpp \
    showingplayers.cpp \
    undestroyableblock.cpp

HEADERS += \
    block.h \
    bomb.h \
    bomberman_dialog.h \
    bombpowerup.h \
    destroyableblock.h \
    explosion.h \
    explosionpowerup.h \
    field.h \
    healthpowerup.h \
    player.h \
    playingground.h \
    powerup.h \
    registerwindow.h \
    settings.h \
    showingplayers.h \
    undestroyableblock.h

FORMS += \
    bomberman_dialog.ui \
    registerwindow.ui \
    showingplayers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resurse.qrc
