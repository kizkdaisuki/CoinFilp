QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chooselevelsence.cpp \
    dataconfig.cpp \
    main.cpp \
    mainsence.cpp \
    mycoin.cpp \
    mypushbutton.cpp \
    palysence.cpp

HEADERS += \
    chooselevelsence.h \
    dataconfig.h \
    mainsence.h \
    mycoin.h \
    mypushbutton.h \
    palysence.h

FORMS += \
    chooselevelsence.ui \
    mainsence.ui \
    palysence.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    res/BackButton.png \
    res/BackButtonSelected.png \
    res/BackButtonSound.wav \
    res/BoardNode.png \
    res/Coin0001.png \
    res/Coin0002.png \
    res/Coin0003.png \
    res/Coin0004.png \
    res/Coin0005.png \
    res/Coin0006.png \
    res/Coin0007.png \
    res/Coin0008.png \
    res/ConFlipSound.wav \
    res/LevelCompletedDialogBg.png \
    res/LevelIcon.png \
    res/LevelWinSound.wav \
    res/MenuSceneBg.png \
    res/MenuSceneStartButton.png \
    res/OtherSceneBg.png \
    res/PlayLevelSceneBg.png \
    res/TapButtonSound.wav \
    res/Title.png \
    res/myDouDZ.wav
