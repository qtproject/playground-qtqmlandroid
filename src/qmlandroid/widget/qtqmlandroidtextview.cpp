#include "qtqmlandroidtextview_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroidcolor_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidTextView::QtQmlAndroidTextView(QtQmlAndroidView *parent) :
    QtQmlAndroidView(parent), m_singleLine(false)
{
}

QString QtQmlAndroidTextView::text() const
{
    return m_text;
}

void QtQmlAndroidTextView::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        QtQmlAndroid::callTextMethod(instance(), "setText", text);
        emit textChanged();
    }
}

int QtQmlAndroidTextView::textColor() const
{
    if (m_textColor.isNull())
        return QtQmlAndroidColor::BLACK; // TODO
    return m_textColor.value();
}

void QtQmlAndroidTextView::setTextColor(int color)
{
    if (color != textColor()) {
        m_textColor = color;
        QtQmlAndroid::callIntMethod(instance(), "setTextColor", color);
        emit textColorChanged();
    }
}

qreal QtQmlAndroidTextView::textSize() const
{
    if (m_textSize.isNull())
        return -1;
    return m_textSize.value();
}

void QtQmlAndroidTextView::setTextSize(qreal size)
{
    if (size != textSize()) {
        m_textSize = size;
        QtQmlAndroid::callRealMethod(instance(), "setTextSize", size);
        emit textSizeChanged();
    }
}

QString QtQmlAndroidTextView::hint() const
{
    return m_hint;
}

void QtQmlAndroidTextView::setHint(const QString &hint)
{
    if (m_hint != hint) {
        m_hint = hint;
        QtQmlAndroid::callTextMethod(instance(), "setHint", hint);
        emit hintChanged();
    }
}

bool QtQmlAndroidTextView::isSingleLine() const
{
    return m_singleLine;
}

void QtQmlAndroidTextView::setSingleLine(bool singleLine)
{
    if (m_singleLine != singleLine) {
        m_singleLine = singleLine;
        QtQmlAndroid::callBoolMethod(instance(), "setSingleLine", singleLine);
        emit singleLineChanged();
    }
}

int QtQmlAndroidTextView::inputType() const
{
    if (m_inputType.isNull())
        return 0; // TODO
    return m_inputType.value();
}

void QtQmlAndroidTextView::setInputType(int type)
{
    if (m_inputType.isNull() || m_inputType.value() != type) {
        m_inputType = type;
        QtQmlAndroid::callIntMethod(instance(), "setInputType", type);
        emit inputTypeChanged();
    }
}

QAndroidJniObject QtQmlAndroidTextView::onCreate()
{
    return QAndroidJniObject("android/widget/TextView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidTextView::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidView::onInflate(instance);

    if (!m_text.isNull())
        instance.callMethod<void>("setText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_text).object());
    if (!m_textColor.isNull())
        instance.callMethod<void>("setTextColor", "(I)V", m_textColor.value());
    if (!m_textSize.isNull())
        instance.callMethod<void>("setTextSize", "(F)V", m_textSize.value());
    if (!m_hint.isNull())
        instance.callMethod<void>("setHint", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_hint).object());
    if (m_singleLine)
        instance.callMethod<void>("setSingleLine");
    if (!m_inputType.isNull())
        instance.callMethod<void>("setInputType", "(I)V", m_inputType.value());
}

QT_END_NAMESPACE
