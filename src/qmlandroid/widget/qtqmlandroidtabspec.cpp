#include "qtqmlandroidtabspec_p.h"
#include "qtqmlandroidtabhost_p.h"
#include "qtqmlandroidview_p.h"
#include "qtqmlandroidfunctions_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

QQmlAndroidTabSpec::QQmlAndroidTabSpec(QQmlAndroidView *view) :
    QObject(view)
{
    QQmlAndroidView *parent = qobject_cast<QQmlAndroidView *>(view->parent());
    if (parent)
        parent->setIdentifier(16908305); // TODO: android.R.id.tabcontent
}

QQmlAndroidTabSpec *QQmlAndroidTabSpec::qmlAttachedProperties(QObject *object)
{
    QQmlAndroidView *view = qobject_cast<QQmlAndroidView*>(object);
    if (view)
        return new QQmlAndroidTabSpec(view);
    return 0;
}

QString QQmlAndroidTabSpec::label() const
{
    return m_label;
}

void QQmlAndroidTabSpec::setLabel(const QString &label)
{
    if (m_label != label) {
        m_label = label;
        // TODO: invalidate
        emit labelChanged();
    }
}

void QQmlAndroidTabSpec::setup(QAndroidJniObject &host, int index)
{
    int id = -1;
    QQmlAndroidView *content = qobject_cast<QQmlAndroidView *>(parent());
    if (content)
        id = content->identifier();

    QtQmlAndroid::callFunction([=]() {
        QAndroidJniObject spec = host.callObjectMethod("newTabSpec",
                                                       "(Ljava/lang/String;)Landroid/widget/TabHost$TabSpec;",
                                                       QAndroidJniObject::fromString(QString::number(index)).object());

        spec.callObjectMethod("setIndicator",
                             "(Ljava/lang/CharSequence;)Landroid/widget/TabHost$TabSpec;",
                             QAndroidJniObject::fromString(m_label).object());

        if (id != -1) {
            spec.callObjectMethod("setContent",
                                  "(I)Landroid/widget/TabHost$TabSpec;",
                                  id);
        }

        host.callMethod<void>("addTab", "(Landroid/widget/TabHost$TabSpec;)V", spec.object());
    });
}

QT_END_NAMESPACE
