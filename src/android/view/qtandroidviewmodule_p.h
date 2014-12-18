#ifndef QTANDROIDVIEWMODULE_P_H
#define QTANDROIDVIEWMODULE_P_H

#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid
{
    void registerViewModule(const char *uri);
    void registerAnimationModule(const char *uri);
}

QT_END_NAMESPACE

#endif // QTANDROIDVIEWMODULE_P_H
