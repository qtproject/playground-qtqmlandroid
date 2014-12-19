#include "qqmlandroidtextview_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qqmlandroidcolor_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidTextView::QQmlAndroidTextView(QQmlAndroidView *parent) :
    QQmlAndroidView(parent), m_singleLine(false)
{
}

QString QQmlAndroidTextView::text() const
{
    return m_text;
}

void QQmlAndroidTextView::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        QtQmlAndroid::callTextMethod(instance(), "setText", text);
        emit textChanged();
    }
}

int QQmlAndroidTextView::textColor() const
{
    if (m_textColor.isNull())
        return QQmlAndroidColor::BLACK; // TODO
    return m_textColor.value();
}

void QQmlAndroidTextView::setTextColor(int color)
{
    if (color != textColor()) {
        m_textColor = color;
        QtQmlAndroid::callIntMethod(instance(), "setTextColor", color);
        emit textColorChanged();
    }
}

qreal QQmlAndroidTextView::textSize() const
{
    if (m_textSize.isNull())
        return -1;
    return m_textSize.value();
}

void QQmlAndroidTextView::setTextSize(qreal size)
{
    if (size != textSize()) {
        m_textSize = size;
        QtQmlAndroid::callRealMethod(instance(), "setTextSize", size);
        emit textSizeChanged();
    }
}

QString QQmlAndroidTextView::hint() const
{
    return m_hint;
}

void QQmlAndroidTextView::setHint(const QString &hint)
{
    if (m_hint != hint) {
        m_hint = hint;
        QtQmlAndroid::callTextMethod(instance(), "setHint", hint);
        emit hintChanged();
    }
}

bool QQmlAndroidTextView::isSingleLine() const
{
    return m_singleLine;
}

void QQmlAndroidTextView::setSingleLine(bool singleLine)
{
    if (m_singleLine != singleLine) {
        m_singleLine = singleLine;
        QtQmlAndroid::callBoolMethod(instance(), "setSingleLine", singleLine);
        emit singleLineChanged();
    }
}

int QQmlAndroidTextView::inputType() const
{
    if (m_inputType.isNull())
        return 0; // TODO
    return m_inputType.value();
}

void QQmlAndroidTextView::setInputType(int type)
{
    if (m_inputType.isNull() || m_inputType.value() != type) {
        m_inputType = type;
        QtQmlAndroid::callIntMethod(instance(), "setInputType", type);
        emit inputTypeChanged();
    }
}

QAndroidJniObject QQmlAndroidTextView::onCreate()
{
    return QAndroidJniObject("android/widget/TextView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidTextView::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidView::onInflate(instance);

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
