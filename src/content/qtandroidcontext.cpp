#include "qtandroidcontext_p.h"

QtAndroidContext::QtAndroidContext(QObject *parent) :
    QtAndroidContextual(this, parent)
{
}

QtAndroidContext::QtAndroidContext(QtAndroidContext *context, QObject *parent) :
    QtAndroidContextual(context, parent)
{
}
