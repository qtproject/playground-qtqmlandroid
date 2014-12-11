#include "qtdroidtogglebutton_p.h"
#include "qtdroidfunctions_p.h"

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

QAndroidJniObject QtAndroidToggleButton::construct()
{
    return QAndroidJniObject("android/widget/ToggleButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidToggleButton::inflate()
{
    QtAndroidCompoundButton::inflate();

    if (!m_textOn.isNull())
        QtAndroid::callTextMethod(instance(), "setTextOn", m_textOn);
    if (!m_textOff.isNull())
        QtAndroid::callTextMethod(instance(), "setTextOff", m_textOff);
}
