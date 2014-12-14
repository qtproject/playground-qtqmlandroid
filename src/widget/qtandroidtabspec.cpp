#include "qtandroidtabspec_p.h"
#include "qtandroidtabhost_p.h"
#include "qtandroidview_p.h"
#include "qtandroidfunctions_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QtAndroidTabSpec::QtAndroidTabSpec(QtAndroidView *view) : QObject(view)
{
    QtAndroidView *parent = qobject_cast<QtAndroidView *>(view->parent());
    if (parent)
        parent->setIdentifier(16908305); // TODO: android.R.id.tabcontent
}

QtAndroidTabSpec *QtAndroidTabSpec::qmlAttachedProperties(QObject *object)
{
    QtAndroidView *view = qobject_cast<QtAndroidView*>(object);
    if (view)
        return new QtAndroidTabSpec(view);
    return 0;
}

QString QtAndroidTabSpec::label() const
{
    return m_label;
}

void QtAndroidTabSpec::setLabel(const QString &label)
{
    if (m_label != label) {
        m_label = label;
        // TODO: invalidate
        emit labelChanged();
    }
}

void QtAndroidTabSpec::setup(QAndroidJniObject &host, int index)
{
    int id = -1;
    QtAndroidView *content = qobject_cast<QtAndroidView *>(parent());
    if (content)
        id = content->identifier();

    QtAndroid::callFunction([=]() {
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
