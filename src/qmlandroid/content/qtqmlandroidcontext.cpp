#include "qtqmlandroidcontext_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidContext::QQmlAndroidContext(QObject *parent) :
    QQmlAndroidContextual(this, parent)
{
}

QQmlAndroidContext::QQmlAndroidContext(QQmlAndroidContext *context, QObject *parent) :
    QQmlAndroidContextual(context, parent)
{
}

QT_END_NAMESPACE
