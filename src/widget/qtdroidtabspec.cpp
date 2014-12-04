#include "qtdroidtabspec_p.h"
#include "qtdroidtabhost_p.h"
#include "qtdroidview_p.h"
#include "qtdroidfunctions_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QtDroidTabSpec::QtDroidTabSpec(QtDroidView *view) : QObject(view)
{
    QtDroidView *parent = qobject_cast<QtDroidView *>(view->parent());
    if (parent)
        parent->setIdentifier(16908305); // TODO: android.R.id.tabcontent
}

QtDroidTabSpec *QtDroidTabSpec::qmlAttachedProperties(QObject *object)
{
    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidTabSpec(view);
    return 0;
}

QString QtDroidTabSpec::label() const
{
    return m_label;
}

void QtDroidTabSpec::setLabel(const QString &label)
{
    if (m_label != label) {
        m_label = label;
        // TODO: invalidate
        emit labelChanged();
    }
}

void QtDroidTabSpec::setup(QtDroidTabHost *h, int index)
{
    QAndroidJniObject host = h->instance();

    int id = -1;
    QtDroidView *content = qobject_cast<QtDroidView *>(parent());
    if (content)
        id = content->identifier();

    QtDroid::callFunction([=]() {
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
