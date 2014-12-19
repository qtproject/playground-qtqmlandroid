#include "qtqmlandroidtabspec_p.h"
#include "qtqmlandroidtabhost_p.h"
#include "qtqmlandroidview_p.h"
#include "qtqmlandroidfunctions_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

QtQmlAndroidTabSpec::QtQmlAndroidTabSpec(QtQmlAndroidView *view) :
    QObject(view)
{
    QtQmlAndroidView *parent = qobject_cast<QtQmlAndroidView *>(view->parent());
    if (parent)
        parent->setIdentifier(16908305); // TODO: android.R.id.tabcontent
}

QtQmlAndroidTabSpec *QtQmlAndroidTabSpec::qmlAttachedProperties(QObject *object)
{
    QtQmlAndroidView *view = qobject_cast<QtQmlAndroidView*>(object);
    if (view)
        return new QtQmlAndroidTabSpec(view);
    return 0;
}

QString QtQmlAndroidTabSpec::label() const
{
    return m_label;
}

void QtQmlAndroidTabSpec::setLabel(const QString &label)
{
    if (m_label != label) {
        m_label = label;
        // TODO: invalidate
        emit labelChanged();
    }
}

void QtQmlAndroidTabSpec::setup(QAndroidJniObject &host, int index)
{
    int id = -1;
    QtQmlAndroidView *content = qobject_cast<QtQmlAndroidView *>(parent());
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
