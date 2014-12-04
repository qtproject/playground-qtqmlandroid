#include "qtdroidtogglebutton_p.h"
#include "qtdroidfunctions_p.h"

QtDroidToggleButton::QtDroidToggleButton(QtDroidView *parent) : QtDroidCompoundButton(parent)
{
}

QString QtDroidToggleButton::textOn() const
{
    return m_textOn;
}

void QtDroidToggleButton::setTextOn(const QString &text)
{
    if (m_textOn != text) {
        m_textOn = text;
        QtDroid::callTextMethod(instance(), "setTextOn", text);
        emit textOnChanged();
    }
}

QString QtDroidToggleButton::textOff() const
{
    return m_textOff;
}

void QtDroidToggleButton::setTextOff(const QString &text)
{
    if (m_textOff != text) {
        m_textOff = text;
        QtDroid::callTextMethod(instance(), "setTextOff", text);
        emit textOffChanged();
    }
}

QAndroidJniObject QtDroidToggleButton::construct()
{
    return QAndroidJniObject("android/widget/ToggleButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidToggleButton::inflate()
{
    QtDroidCompoundButton::inflate();

    if (!m_textOn.isNull())
        QtDroid::callTextMethod(instance(), "setTextOn", m_textOn);
    if (!m_textOff.isNull())
        QtDroid::callTextMethod(instance(), "setTextOff", m_textOff);
}
