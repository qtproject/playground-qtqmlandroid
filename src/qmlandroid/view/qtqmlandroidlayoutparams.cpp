#include "qtqmlandroidlayoutparams_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidLayoutParams::QtQmlAndroidLayoutParams(QtQmlAndroidView *view) :
    QtQmlAndroidObject(view), m_dirty(false), m_view(view)
{
    m_view->setLayoutParams(this);
}

QtQmlAndroidLayoutParams *QtQmlAndroidLayoutParams::qmlAttachedProperties(QObject *object)
{
    QtQmlAndroidView *view = qobject_cast<QtQmlAndroidView*>(object);
    if (view)
        return new QtQmlAndroidLayoutParams(view);
    return 0;
}

int QtQmlAndroidLayoutParams::width() const
{
    if (m_width.isNull())
        return MATCH_PARENT;
    return m_width.value();
}

void QtQmlAndroidLayoutParams::setWidth(int value)
{
    if (value != width()) {
        m_width = value;
        invalidate();
        emit widthChanged();
    }
}

int QtQmlAndroidLayoutParams::height() const
{
    if (m_height.isNull())
        return MATCH_PARENT;
    return m_height.value();
}

void QtQmlAndroidLayoutParams::setHeight(int value)
{
    if (value != height()) {
        m_height = value;
        invalidate();
        emit heightChanged();
    }
}

void QtQmlAndroidLayoutParams::invalidate()
{
    if (!m_dirty && isValid()) {
        m_dirty = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::LayoutRequest));
    }
}

QAndroidJniObject QtQmlAndroidLayoutParams::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtQmlAndroidLayoutParams::onInflate(QAndroidJniObject &instance)
{
    if (!m_width.isNull())
        instance.setField<int>("width", m_width.value());
    if (!m_height.isNull())
        instance.setField<int>("height", m_height.value());
}

bool QtQmlAndroidLayoutParams::event(QEvent *event)
{
    if (event->type() == QEvent::LayoutRequest) {
        if (m_dirty && isValid()) {
            construct();
            m_dirty = false;
        }
    }
    return QtQmlAndroidObject::event(event);
}

QT_END_NAMESPACE
