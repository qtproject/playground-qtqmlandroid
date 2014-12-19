#include "qtqmlandroidtogglebutton_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidToggleButton::QtQmlAndroidToggleButton(QtQmlAndroidView *parent) :
    QtQmlAndroidCompoundButton(parent)
{
}

QString QtQmlAndroidToggleButton::textOn() const
{
    return m_textOn;
}

void QtQmlAndroidToggleButton::setTextOn(const QString &text)
{
    if (m_textOn != text) {
        m_textOn = text;
        QtQmlAndroid::callTextMethod(instance(), "setTextOn", text);
        emit textOnChanged();
    }
}

QString QtQmlAndroidToggleButton::textOff() const
{
    return m_textOff;
}

void QtQmlAndroidToggleButton::setTextOff(const QString &text)
{
    if (m_textOff != text) {
        m_textOff = text;
        QtQmlAndroid::callTextMethod(instance(), "setTextOff", text);
        emit textOffChanged();
    }
}

QAndroidJniObject QtQmlAndroidToggleButton::onCreate()
{
    return QAndroidJniObject("android/widget/ToggleButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidToggleButton::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidCompoundButton::onInflate(instance);

    if (!m_textOn.isNull())
        instance.callMethod<void>("setTextOn", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_textOn).object());
    if (!m_textOff.isNull())
        instance.callMethod<void>("setTextOff", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_textOff).object());
}

QT_END_NAMESPACE
