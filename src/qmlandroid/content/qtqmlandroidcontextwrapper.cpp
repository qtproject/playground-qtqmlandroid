#include "qtqmlandroidcontextwrapper_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidContextWrapper::QtQmlAndroidContextWrapper(QObject *parent) :
    QtQmlAndroidContext(parent)
{
}

QtQmlAndroidContextWrapper::QtQmlAndroidContextWrapper(QtQmlAndroidContext *context, QObject *parent) :
    QtQmlAndroidContext(context, parent)
{
}

QT_END_NAMESPACE
