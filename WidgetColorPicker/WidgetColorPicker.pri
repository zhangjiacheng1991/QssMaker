include(../common.pri)
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

WidgetColorPicker-uselib:!WidgetColorPicker-buildlib {
    LIBS += -L$$WIDGETCOLORPICKER_LIBDIR -l$$WIDGETCOLORPICKER_LIBNAME
} else {
    SOURCES += $$PWD/WidgetColorPicker.cpp
    HEADERS += $$PWD/WidgetColorPicker.h
    FORMS += $$PWD/WidgetColorPicker.ui
}

win32 {
    contains(TEMPLATE, lib):contains(CONFIG, shared):DEFINES += WIDGETCOLORPICKER_EXPORT
    else:WidgetCOLORPICKER-uselib:DEFINES += WIDGETCOLORPICKER_IMPORT
}

FORMS +=

HEADERS +=

SOURCES +=

