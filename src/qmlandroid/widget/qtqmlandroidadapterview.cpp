#include "qtqmlandroidadapterview_p.h"
#include "qtqmlandroidbaseadapter_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidAdapterView::QtQmlAndroidAdapterView(QtQmlAndroidView *parent) :
    QtQmlAndroidViewGroup(parent), m_adapter(0)
{
}

QtQmlAndroidBaseAdapter *QtQmlAndroidAdapterView::adapter() const
{
    return m_adapter;
}

void QtQmlAndroidAdapterView::setAdapter(QtQmlAndroidBaseAdapter *adapter)
{
    if (m_adapter != adapter) {
        if (m_adapter) {
            m_adapter->setContext(0);
            disconnect(m_adapter, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidAdapterView::updateAdapter);
            m_adapter->destruct();
        }
        m_adapter = adapter;
        if (m_adapter) {
            m_adapter->setContext(context());
            connect(m_adapter, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidAdapterView::updateAdapter);
            if (isValid())
                m_adapter->construct();
        }
        emit adapterChanged();
    }
}

void QtQmlAndroidAdapterView::setSelection(int position)
{
    QtQmlAndroid::callIntMethod(instance(), "setSelection", position);
}

QAndroidJniObject QtQmlAndroidAdapterView::onCreate()
{
    return QAndroidJniObject("android/widget/AdapterView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidAdapterView::onInflate(QAndroidJniObject &instance)
{
    m_listener = QAndroidJniObject("qt/android/widget/QtAdapterViewListener",
                                   "(Landroid/widget/AdapterView;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    QtQmlAndroidViewGroup::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QtQmlAndroidAdapterView::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onItemClick", "(JI)V", reinterpret_cast<void *>(onItemClick)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtQmlAndroidAdapterView::onItemClick(JNIEnv *env, jobject object, jlong instance, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidAdapterView *view = reinterpret_cast<QtQmlAndroidAdapterView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection, Q_ARG(int, position));
}

void QtQmlAndroidAdapterView::objectChange(ObjectChange change)
{
    QtQmlAndroidViewGroup::objectChange(change);
    if (change == InstanceChange)
        updateAdapter();
}

void QtQmlAndroidAdapterView::updateAdapter()
{
    if (!isValid())
        return;

    QAndroidJniObject adapter;
    if (m_adapter)
        adapter = m_adapter->instance();

    QAndroidJniObject view = instance();
    QtQmlAndroid::callFunction([=]() {
        view.callMethod<void>("setAdapter", "(Landroid/widget/Adapter;)V", adapter.object());
    });
}

QT_END_NAMESPACE
