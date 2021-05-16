#QT foloseste 2 librarii principale: core si gui
QT       += core gui
#realizez o aplicatie widget care sa functioneze cu versiuni de qt mai mari de 4
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bomberman
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS



CONFIG += c++11

#aici se adauga toate sursele cand le creez
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    player.cpp \
    bomb.cpp \
    field.cpp \
    destroyableblock.cpp \
    undestroyableblock.cpp \
    explosion.cpp \
    bombpowerup.cpp \
    healthpowerup.cpp \
    explosionpowerup.cpp

HEADERS += \
        mainwindow.h \
    player.h \
    bomb.h \
    field.h \
    block.h \
    destroyableblock.h \
    undestroyableblock.h \
    explosion.h \
    settings.h \
    powerup.h \
    bombpowerup.h \
    healthpowerup.h \
    explosionpowerup.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
