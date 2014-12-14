#include "qtandroidtogglebutton_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidToggleButton::QtAndroidToggleButton(QtAndroidView *parent) : QtAndroidCompoundButton(parent)
{
}

QString QtAndroidToggleButton::textOn() const
{
    return m_textOn;
}

void QtAndroidToggleButton::setTextOn(const QString &text)
{
    if (m_textOn != text) {
        m_textOn = text;
        QtAndroid::callTextMethod(instance(), "setTextOn", text);
        emit textOnChanged();
    }
}

QString QtAndroidToggleButton::textOff() const
{
    return m_textOff;
}

void QtAndroidToggleButton::setTextOff(const QString &text)
{
    if (m_textOff != text) {
        m_textOff = text;
        QtAndroid::callTextMethod(instance(), "setTextOff", text);
        emit textOffChanged();
    }
}

QAndroidJniObject QtAndroidToggleButton::onCreate()
{
    return QAndroidJniObject("android/widget/ToggleButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidToggleButton::onInflate(QAndroidJniObject &instance)
{
    QtAndroidCompoundButton::onInflate(instance);

    if (!m_textOn.isNull())
        instance.callMethod<void>("setTextOn", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_textOn).object());
    if (!m_textOff.isNull())
        instance.callMethod<void>("setTextOff", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_textOff).object());
}
