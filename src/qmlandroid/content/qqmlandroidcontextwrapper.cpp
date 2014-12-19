#include "qqmlandroidcontextwrapper_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidContextWrapper::QQmlAndroidContextWrapper(QObject *parent) :
    QQmlAndroidContext(parent)
{
}

QQmlAndroidContextWrapper::QQmlAndroidContextWrapper(QQmlAndroidContext *context, QObject *parent) :
    QQmlAndroidContext(context, parent)
{
}

QT_END_NAMESPACE
