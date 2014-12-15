#ifndef QTANDROIDGLOBAL_P_H
#define QTANDROIDGLOBAL_P_H

#include <QtCore/qglobal.h>
#include <QtCore/qthread.h>
#include <QtCore/qcoreapplication.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid {
    static inline bool isMainQtThread()
    {
        return QThread::currentThread() == qApp->thread();
    }
}

QT_END_NAMESPACE

#endif // QTANDROIDGLOBAL_P_H
