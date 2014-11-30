#include "qtdroidview_p.h"
#include "qtdroidcontext_p.h"
#include "qtdroidlayoutparams_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qhash.h>

QtDroidView::QtDroidView(QObject *parent) : QtDroidObject(parent),
    m_context(0), m_layoutParamsDirty(false), m_layoutParams(0), m_x(0), m_y(0), m_width(0), m_height(0)
{
}

QtDroidContext *QtDroidView::context() const
{
    return m_context;
}

void QtDroidView::setContext(QtDroidContext *context)
{
    if (m_context != context) {
        m_context = context;
        emit contextChanged();
    }
}

bool QtDroidView::hasFocus() const
{
    if (m_focus.isNull())
        return false;
    return m_focus.value();
}

static void callSetFocus(const QAndroidJniObject& view, bool focus)
{
    if (view.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            view.callMethod<jboolean>("requestFocus", "()Z", focus);
        });
    }
}

void QtDroidView::setFocus(bool focus)
{
    if (updateFocus(focus))
        callSetFocus(instance(), focus);
}

bool QtDroidView::updateFocus(bool arg)
{
    if (arg != hasFocus()) {
        m_focus = arg;
        emit focusChanged();
        return true;
    }
    return false;
}

qreal QtDroidView::x() const
{
    return m_x;
    //return jniObject().callMethod<jfloat>("getX");
}

void QtDroidView::setX(qreal x)
{
    if (m_x != x) {
        m_x = x;
        //jniObject().callMethod<jfloat>("setX", "(F)V", x);
    }
}

qreal QtDroidView::y() const
{
    return m_y;
    //return jniObject().callMethod<jfloat>("getY");
}

void QtDroidView::setY(qreal y)
{
    if (m_y != y) {
        m_y = y;
        //jniObject().callMethod<jfloat>("setX", "(F)V", y);
    }
}

qreal QtDroidView::width() const
{
    return m_width;
    //return jniObject().callMethod<jfloat>("getWidth");
}

void QtDroidView::setWidth(qreal width)
{
    if (m_width != width) {
        m_width = width;
        //jniObject().callMethod<jfloat>("setWidth", "(F)V", width);
    }
}

qreal QtDroidView::height() const
{
    return m_height;
    //return jniObject().callMethod<jfloat>("getHeight");
}

void QtDroidView::setHeight(qreal height)
{
    if (m_height != height) {
        m_height = height;
        //jniObject().callMethod<jfloat>("setHeight", "(F)V", height);
    }
}

QAndroidJniObject QtDroidView::construct(jobject context)
{
    return QAndroidJniObject("android/view/View",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidView::inflate(jobject context)
{
    Q_UNUSED(context)
    QAndroidJniObject view = instance();
    m_listener = QAndroidJniObject("qtdroid/view/QtViewListener",
                                   "(Landroid/view/View;J)V",
                                   view.object(),
                                   reinterpret_cast<jlong>(this));

    view.callMethod<void>("setId", "(I)V", qHash(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    if (!m_focus.isNull())
        callSetFocus(instance(), m_focus.value());

    invalidateLayoutParams();
}

void QtDroidView::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onClick", "(J)V", reinterpret_cast<void *>(onClick)},
                               {"onFocusChange", "(JZ)V", reinterpret_cast<void *>(onFocusChange)},
                               {"onLayoutChange", "(JIIII)V", reinterpret_cast<void *>(onLayoutChange)}
                               /*{"onLongClick", "(J)V", reinterpret_cast<void *>(onLongClick)}*/};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtDroidView::onClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidView *view = reinterpret_cast<QtDroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection);
}

void QtDroidView::onFocusChange(JNIEnv *env, jobject object, jlong instance, jboolean hasFocus)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidView *view = reinterpret_cast<QtDroidView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "updateFocus", Qt::QueuedConnection, Q_ARG(bool, hasFocus));
}

#include <QtDebug>
void QtDroidView::onLayoutChange(JNIEnv *env, jobject object, jlong instance, jint top, jint left, jint right, jint bottom)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidView *view = reinterpret_cast<QtDroidView *>(instance);
    if (view) {
        //qDebug() << "onLayoutChange:" << view << top << left << right << bottom;
    }
}

bool QtDroidView::onLongClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidView *view = reinterpret_cast<QtDroidView *>(instance);
    if (view) {
        //qDebug() << "onLongClick:" << view;
        QMetaObject::invokeMethod(view, "longClick", Qt::QueuedConnection);
    }
    return true; // TODO: accept
}

void QtDroidView::customEvent(QEvent *event)
{
    if (m_layoutParamsDirty && m_layoutParams && instance().isValid()) {
        QtDroidObject::callUiMethod([=]() {
            QAndroidJniObject params = m_layoutParams->instance();
            if (!params.isValid()) {
                params = m_layoutParams->construct();
                m_layoutParams->setInstance(params);
            }
            m_layoutParams->applyParams(params);
            instance().callMethod<void>("setLayoutParams",
                                        "(Landroid/view/ViewGroup$LayoutParams;)V",
                                        params.object());
        });
        m_layoutParamsDirty = false;
    }
}

void QtDroidView::invalidateLayoutParams()
{
    if (!m_layoutParamsDirty && m_layoutParams && instance().isValid()) {
        m_layoutParamsDirty = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::User));
    }
}

void QtDroidView::setLayoutParams(QtDroidLayoutParams *params)
{
    if (m_layoutParams != params) {
        m_layoutParams = params;
        invalidateLayoutParams();
    }
}
