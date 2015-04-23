#include "qqmlandroidadapterview_p.h"
#include "qqmlandroidbaseadapter_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAdapterView::QQmlAndroidAdapterView(QQmlAndroidView *parent) :
    QQmlAndroidViewGroup(parent), m_adapter(0)
{
}

QQmlAndroidBaseAdapter *QQmlAndroidAdapterView::adapter() const
{
    return m_adapter;
}

void QQmlAndroidAdapterView::setAdapter(QQmlAndroidBaseAdapter *adapter)
{
    if (m_adapter != adapter) {
        if (m_adapter) {
            m_adapter->setContext(0);
            disconnect(m_adapter, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidAdapterView::updateAdapter);
            m_adapter->destruct();
        }
        m_adapter = adapter;
        if (m_adapter) {
            m_adapter->setContext(context());
            connect(m_adapter, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidAdapterView::updateAdapter);
            if (isValid())
                m_adapter->construct();
        }
        emit adapterChanged();
    }
}

void QQmlAndroidAdapterView::setSelection(int position)
{
    QtQmlAndroid::callIntMethod(instance(), "setSelection", position);
}

QAndroidJniObject QQmlAndroidAdapterView::onCreate()
{
    return QAndroidJniObject("android/widget/AdapterView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidAdapterView::onInflate(QAndroidJniObject &instance)
{
    m_listener = QAndroidJniObject("qt/android/widget/QmlAdapterViewListener",
                                   "(Landroid/widget/AdapterView;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    QQmlAndroidViewGroup::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QQmlAndroidAdapterView::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onItemClick", "(JI)V", reinterpret_cast<void *>(onItemClick)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidAdapterView::onItemClick(JNIEnv *env, jobject object, jlong instance, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidAdapterView *view = reinterpret_cast<QQmlAndroidAdapterView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection, Q_ARG(int, position));
}

void QQmlAndroidAdapterView::objectChange(ObjectChange change)
{
    QQmlAndroidViewGroup::objectChange(change);
    if (change == InstanceChange)
        updateAdapter();
}

void QQmlAndroidAdapterView::updateAdapter()
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
