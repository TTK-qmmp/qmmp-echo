include($$PWD/../../plugins.pri)

TARGET = $$PLUGINS_PREFIX/Effect/echo

HEADERS += echoplugin.h \
           effectechofactory.h \
           settingsdialog.h

SOURCES += echoplugin.cpp \
           effectechofactory.cpp \
           settingsdialog.cpp

FORMS += settingsdialog.ui

unix{
    target.path = $$PLUGIN_DIR/Effect
    INSTALLS += target
}
