#include "qtdroidadapterview_p.h"
#include "qtdroidbaseadapter_p.h"
#include "qtdroidfunctions_p.h"

QtDroidAdapterView::QtDroidAdapterView(QtDroidView *parent) : QtDroidViewGroup(parent), m_adapter(0)
{
}

QtDroidBaseAdapter *QtDroidAdapterView::adapter() const
{
    return m_adapter;
}

void QtDroidAdapterView::setAdapter(QtDroidBaseAdapter *adapter)
{
    if (m_adapter != adapter) {
        m_adapter = adapter;
        emit adapterChanged();
    }
}

void QtDroidAdapterView::setSelection(int position)
{
    QtDroid::callIntMethod(instance(), "setSelection", position);
}

QAndroidJniObject QtDroidAdapterView::construct()
{
    return QAndroidJniObject("android/widget/AdapterView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidAdapterView::inflate()
{
    QAndroidJniObject view = instance();
    m_listener = QAndroidJniObject("qtdroid/widget/QtAdapterViewListener",
                                   "(Landroid/widget/AdapterView;J)V",
                                   view.object(),
                                   reinterpret_cast<jlong>(this));

    if (m_adapter)
        m_adapter->setup(this);

    QtDroidViewGroup::inflate();

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QtDroidAdapterView::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onItemClick", "(JI)V", reinterpret_cast<void *>(onItemClick)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtDroidAdapterView::onItemClick(JNIEnv *env, jobject object, jlong instance, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidAdapterView *view = reinterpret_cast<QtDroidAdapterView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection, Q_ARG(int, position));
}
