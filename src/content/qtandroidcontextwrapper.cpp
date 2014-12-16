#include "qtandroidcontextwrapper_p.h"

QtAndroidContextWrapper::QtAndroidContextWrapper(QObject *parent) :
    QtAndroidContext(parent)
{
}

QtAndroidContextWrapper::QtAndroidContextWrapper(QtAndroidContext *context, QObject *parent) :
    QtAndroidContext(context, parent)
{
}
