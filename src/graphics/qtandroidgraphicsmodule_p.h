#ifndef QTANDROIDGRAPHICSMODULE_P_H
#define QTANDROIDGRAPHICSMODULE_P_H

#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid
{
    void registerGraphicsModule(const char *uri);
    void registerDrawableModule(const char *uri);
}

QT_END_NAMESPACE

#endif // QTANDROIDGRAPHICSMODULE_P_H
