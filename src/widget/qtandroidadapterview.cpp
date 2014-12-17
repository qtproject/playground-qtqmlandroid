#include "qtandroidadapterview_p.h"
#include "qtandroidbaseadapter_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidAdapterView::QtAndroidAdapterView(QtAndroidView *parent) :
    QtAndroidViewGroup(parent), m_adapter(0)
{
}

QtAndroidBaseAdapter *QtAndroidAdapterView::adapter() const
{
    return m_adapter;
}

void QtAndroidAdapterView::setAdapter(QtAndroidBaseAdapter *adapter)
{
    if (m_adapter != adapter) {
        if (m_adapter) {
            m_adapter->setContext(0);
            disconnect(m_adapter, &QtAndroidObject::instanceChanged, this, &QtAndroidAdapterView::updateAdapter);
            m_adapter->destruct();
        }
        m_adapter = adapter;
        if (m_adapter) {
            m_adapter->setContext(context());
            connect(m_adapter, &QtAndroidObject::instanceChanged, this, &QtAndroidAdapterView::updateAdapter);
            if (isValid())
                m_adapter->construct();
        }
        emit adapterChanged();
    }
}

void QtAndroidAdapterView::setSelection(int position)
{
    QtAndroid::callIntMethod(instance(), "setSelection", position);
}

QAndroidJniObject QtAndroidAdapterView::onCreate()
{
    return QAndroidJniObject("android/widget/AdapterView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidAdapterView::onInflate(QAndroidJniObject &instance)
{
    m_listener = QAndroidJniObject("qt/android/widget/QtAdapterViewListener",
                                   "(Landroid/widget/AdapterView;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    QtAndroidViewGroup::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QtAndroidAdapterView::onRegisterNativeMethods(jobject listener)
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

void QtAndroidAdapterView::objectChange(ObjectChange change)
{
    QtAndroidViewGroup::objectChange(change);
    if (change == InstanceChange)
        updateAdapter();
}

void QtAndroidAdapterView::updateAdapter()
{
    if (!isValid())
        return;

    QAndroidJniObject adapter;
    if (m_adapter)
        adapter = m_adapter->instance();

    QAndroidJniObject view = instance();
    QtAndroid::callFunction([=]() {
        view.callMethod<void>("setAdapter", "(Landroid/widget/Adapter;)V", adapter.object());
    });
}
