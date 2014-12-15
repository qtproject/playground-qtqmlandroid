#include "qtandroidlayoutparams_p.h"
#include "qtandroidfunctions_p.h"
#include "qtandroidview_p.h"

QtAndroidLayoutParams::QtAndroidLayoutParams(QtAndroidView *view) :
    QtAndroidObject(view), m_dirty(false), m_view(view)
{
    m_view->setLayoutParams(this);
}

QtAndroidLayoutParams *QtAndroidLayoutParams::qmlAttachedProperties(QObject *object)
{
    QtAndroidView *view = qobject_cast<QtAndroidView*>(object);
    if (view)
        return new QtAndroidLayoutParams(view);
    return 0;
}

int QtAndroidLayoutParams::width() const
{
    if (m_width.isNull())
        return MATCH_PARENT;
    return m_width.value();
}

void QtAndroidLayoutParams::setWidth(int value)
{
    if (value != width()) {
        m_width = value;
        invalidate();
        emit widthChanged();
    }
}

int QtAndroidLayoutParams::height() const
{
    if (m_height.isNull())
        return MATCH_PARENT;
    return m_height.value();
}

void QtAndroidLayoutParams::setHeight(int value)
{
    if (value != height()) {
        m_height = value;
        invalidate();
        emit heightChanged();
    }
}

void QtAndroidLayoutParams::invalidate()
{
    if (!m_dirty && isValid()) {
        m_dirty = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::LayoutRequest));
    }
}

QAndroidJniObject QtAndroidLayoutParams::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtAndroidLayoutParams::onInflate(QAndroidJniObject &instance)
{
    if (!m_width.isNull())
        instance.setField<int>("width", m_width.value());
    if (!m_height.isNull())
        instance.setField<int>("height", m_height.value());
}

bool QtAndroidLayoutParams::event(QEvent *event)
{
    if (event->type() == QEvent::LayoutRequest) {
        if (m_dirty && isValid()) {
            construct();
            m_dirty = false;
        }
    }
    return QtAndroidObject::event(event);
}
