#include "qtandroidcontextwrapper_p.h"

QT_BEGIN_NAMESPACE

QtAndroidContextWrapper::QtAndroidContextWrapper(QObject *parent) :
    QtAndroidContext(parent)
{
}

QtAndroidContextWrapper::QtAndroidContextWrapper(QtAndroidContext *context, QObject *parent) :
    QtAndroidContext(context, parent)
{
}

QT_END_NAMESPACE
