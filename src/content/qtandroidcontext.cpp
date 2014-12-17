#include "qtandroidcontext_p.h"

QT_BEGIN_NAMESPACE

QtAndroidContext::QtAndroidContext(QObject *parent) :
    QtAndroidContextual(this, parent)
{
}

QtAndroidContext::QtAndroidContext(QtAndroidContext *context, QObject *parent) :
    QtAndroidContextual(context, parent)
{
}

QT_END_NAMESPACE
