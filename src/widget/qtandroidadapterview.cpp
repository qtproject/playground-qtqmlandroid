#include "qtandroidadapterview_p.h"
#include "qtandroidbaseadapter_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidAdapterView::QtAndroidAdapterView(QtAndroidView *parent) : QtAndroidViewGroup(parent), m_adapter(0)
{
}

QtAndroidBaseAdapter *QtAndroidAdapterView::adapter() const
{
    return m_adapter;
}

void QtAndroidAdapterView::setAdapter(QtAndroidBaseAdapter *adapter)
{
    if (m_adapter != adapter) {
        m_adapter = adapter;
        emit adapterChanged();
    }
}

void QtAndroidAdapterView::setSelection(int position)
{
    QtAndroid::callIntMethod(instance(), "setSelection", position);
}

QAndroidJniObject QtAndroidAdapterView::construct()
{
    return QAndroidJniObject("android/widget/AdapterView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidAdapterView::inflate()
{
    QAndroidJniObject view = instance();
    m_listener = QAndroidJniObject("qtandroid/widget/QtAdapterViewListener",
                                   "(Landroid/widget/AdapterView;J)V",
                                   view.object(),
                                   reinterpret_cast<jlong>(this));

    if (m_adapter)
        m_adapter->setup(this);

    QtAndroidViewGroup::inflate();

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QtAndroidAdapterView::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onItemClick", "(JI)V", reinterpret_cast<void *>(onItemClick)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidAdapterView::onItemClick(JNIEnv *env, jobject object, jlong instance, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidAdapterView *view = reinterpret_cast<QtAndroidAdapterView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection, Q_ARG(int, position));
}
