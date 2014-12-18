#ifndef QTANDROIDSUPPORTMODULE_P_H
#define QTANDROIDSUPPORTMODULE_P_H

#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid
{
    void registerSupportV4WidgetModule(const char *uri);
    void registerSupportV7AppModule(const char *uri);
    void registerSupportV7WidgetModule(const char *uri);
}

QT_END_NAMESPACE

#endif // QTANDROIDSUPPORTMODULE_P_H
