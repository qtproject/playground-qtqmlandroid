#include "qtdroidtabspec_p.h"
#include "qtdroidview_p.h"
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
        emit labelChanged();
    }
}

void QtDroidTabSpec::applyParams(QAndroidJniObject &spec)
{
    if (!m_label.isNull()) {
        spec.callObjectMethod("setIndicator",
                             "(Ljava/lang/CharSequence;)Landroid/widget/TabHost$TabSpec;",
                             QAndroidJniObject::fromString(m_label).object());
    }
    QtDroidView *content = qobject_cast<QtDroidView *>(parent());
    if (content) {
        spec.callObjectMethod("setContent",
                             "(I)Landroid/widget/TabHost$TabSpec;",
                             content->identifier());
    }
}
