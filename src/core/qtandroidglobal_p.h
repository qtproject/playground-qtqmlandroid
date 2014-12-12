#ifndef QTANDROIDGLOBAL_P_H
#define QTANDROIDGLOBAL_P_H

#include <QtCore/qglobal.h>
#include <QtCore/qthread.h>
#include <QtCore/qcoreapplication.h>

QT_BEGIN_NAMESPACE

#define QTANDROID_ASSERT_QT_THREAD() \
    Q_ASSERT(QThread::currentThread() == qApp->thread())

#define QTANDROID_ASSERT_ANDROID_THREAD() \
    Q_ASSERT(QThread::currentThread() != qApp->thread())

QT_END_NAMESPACE

#endif // QTANDROIDGLOBAL_P_H
