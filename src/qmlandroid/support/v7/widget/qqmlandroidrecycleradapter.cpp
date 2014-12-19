#include "qqmlandroidrecycleradapter_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qqmlandroidview_p.h"
#include <QtQml/qqmlcomponent.h>
#include <QtQml/qqmlcontext.h>

QT_BEGIN_NAMESPACE

QQmlAndroidRecyclerAdapter::QQmlAndroidRecyclerAdapter(QObject *parent) :
    QQmlAndroidContextual(parent), m_count(0), m_delegate(0)
{
}

int QQmlAndroidRecyclerAdapter::count() const
{
    return m_count;
}

void QQmlAndroidRecyclerAdapter::setCount(int count)
{
    if (m_count != count) {
        m_count = count;
        QtQmlAndroid::callIntMethod(instance(), "setItemCount", count);
        emit countChanged();
    }
}

QQmlComponent *QQmlAndroidRecyclerAdapter::delegate() const
{
    return m_delegate;
}

void QQmlAndroidRecyclerAdapter::setDelegate(QQmlComponent *delegate)
{
    if (m_delegate != delegate) {
        m_delegate = delegate;
        QtQmlAndroid::callVoidMethod(instance(), "notifyDataSetChanged");
        emit delegateChanged();
    }
}

QAndroidJniObject QQmlAndroidRecyclerAdapter::onCreate()
{
    return QAndroidJniObject("qt/android/support/v7/widget/QtRecyclerAdapter",
                             "(IJ)V",
                             m_count,
                             reinterpret_cast<jlong>(this));
}

void QQmlAndroidRecyclerAdapter::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidContextual::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }

    if (m_count > 0)
        instance.callMethod<void>("setItemCount", "(I)V", m_count);
}

void QQmlAndroidRecyclerAdapter::onRegisterNativeMethods(jobject adapter)
{
    JNINativeMethod methods[] {{"onCreateViewHolder", "(JLandroid/view/ViewGroup;I)Lqt/android/support/v7/widget/QtRecyclerAdapter$ViewHolder;", reinterpret_cast<void *>(onCreateViewHolder)},
                               {"onBindViewHolder", "(JLqt/android/support/v7/widget/QtRecyclerAdapter$ViewHolder;I)V", reinterpret_cast<void *>(onBindViewHolder)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(adapter);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

jobject QQmlAndroidRecyclerAdapter::onCreateViewHolder(JNIEnv *env, jobject object, jlong instance, jobject parent, jint viewType)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    Q_UNUSED(parent);
    Q_UNUSED(viewType);
    QQmlAndroidRecyclerAdapter *adapter = reinterpret_cast<QQmlAndroidRecyclerAdapter *>(instance);
    if (adapter) {
        QQmlAndroidView *item = 0;
        QMetaObject::invokeMethod(adapter, "createItem", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QQmlAndroidView *, item));
        item->construct();
        adapter->m_holders += QAndroidJniObject("qt/android/support/v7/widget/QtRecyclerAdapter$ViewHolder",
                                                "(Landroid/view/View;J)V",
                                                item->instance().object(),
                                                reinterpret_cast<jlong>(item));
        return adapter->m_holders.last().object();
    }
    return 0;
}

void QQmlAndroidRecyclerAdapter::onBindViewHolder(JNIEnv *env, jobject object, jlong instance, jobject holder, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidRecyclerAdapter *adapter = reinterpret_cast<QQmlAndroidRecyclerAdapter *>(instance);
    if (adapter) {
        jlong vi = QAndroidJniObject(holder).callMethod<jlong>("getInstance");
        QQmlAndroidView *item = reinterpret_cast<QQmlAndroidView *>(vi);
        if (item)
            QMetaObject::invokeMethod(adapter, "setItemPosition", Qt::BlockingQueuedConnection, Q_ARG(QQmlAndroidView *, item), Q_ARG(int, position));
    }
}

QQmlAndroidView *QQmlAndroidRecyclerAdapter::createItem()
{
    QQmlAndroidView *item = 0;
    if (m_delegate) {
        QQmlContext *creationContext = m_delegate->creationContext();
        QQmlContext *context = new QQmlContext(creationContext ? creationContext : qmlContext(this));
        QObject *object = m_delegate->beginCreate(context);
        if (object) {
            context->setParent(object);
            item = qobject_cast<QQmlAndroidView *>(object);
            if (!item)
                delete object;
        } else {
            delete context;
        }
    } else {
        item = new QQmlAndroidView;
    }
    if (item) {
        item->setContext(context());
        item->setParentView(qobject_cast<QQmlAndroidView *>(parent())); // TODO
        setItemPosition(item, -1);
    }
    if (m_delegate)
        m_delegate->completeCreate();
    return item;
}

void QQmlAndroidRecyclerAdapter::setItemPosition(QQmlAndroidView *item, int position)
{
    QQmlContext *context = qmlContext(item);
    if (context)
        context = context->parentContext();
    if (context)
        context->setContextProperty("position", position);
}

QT_END_NAMESPACE
