#include "qqmlandroidlayoutparams_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidLayoutParams::QQmlAndroidLayoutParams(QQmlAndroidView *view) :
    QQmlAndroidObject(view), m_dirty(false), m_view(view)
{
    m_view->setLayoutParams(this);
}

QQmlAndroidLayoutParams *QQmlAndroidLayoutParams::qmlAttachedProperties(QObject *object)
{
    QQmlAndroidView *view = qobject_cast<QQmlAndroidView*>(object);
    if (view)
        return new QQmlAndroidLayoutParams(view);
    return 0;
}

int QQmlAndroidLayoutParams::width() const
{
    if (m_width.isNull())
        return MATCH_PARENT;
    return m_width.value();
}

void QQmlAndroidLayoutParams::setWidth(int value)
{
    if (value != width()) {
        m_width = value;
        invalidate();
        emit widthChanged();
    }
}

int QQmlAndroidLayoutParams::height() const
{
    if (m_height.isNull())
        return MATCH_PARENT;
    return m_height.value();
}

void QQmlAndroidLayoutParams::setHeight(int value)
{
    if (value != height()) {
        m_height = value;
        invalidate();
        emit heightChanged();
    }
}

void QQmlAndroidLayoutParams::invalidate()
{
    if (!m_dirty && isValid()) {
        m_dirty = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::LayoutRequest));
    }
}

QAndroidJniObject QQmlAndroidLayoutParams::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QQmlAndroidLayoutParams::onInflate(QAndroidJniObject &instance)
{
    if (!m_width.isNull())
        instance.setField<int>("width", m_width.value());
    if (!m_height.isNull())
        instance.setField<int>("height", m_height.value());
}

bool QQmlAndroidLayoutParams::event(QEvent *event)
{
    if (event->type() == QEvent::LayoutRequest) {
        if (m_dirty && isValid()) {
            construct();
            m_dirty = false;
        }
    }
    return QQmlAndroidObject::event(event);
}

QT_END_NAMESPACE
