#include "qtqmlandroidcontext_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidContext::QtQmlAndroidContext(QObject *parent) :
    QtQmlAndroidContextual(this, parent)
{
}

QtQmlAndroidContext::QtQmlAndroidContext(QtQmlAndroidContext *context, QObject *parent) :
    QtQmlAndroidContextual(context, parent)
{
}

QT_END_NAMESPACE
