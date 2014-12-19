#include "qtqmlandroidrecycleradapter_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroidview_p.h"
#include <QtQml/qqmlcomponent.h>
#include <QtQml/qqmlcontext.h>

QT_BEGIN_NAMESPACE

QtQmlAndroidRecyclerAdapter::QtQmlAndroidRecyclerAdapter(QObject *parent) :
    QtQmlAndroidContextual(parent), m_count(0), m_delegate(0)
{
}

int QtQmlAndroidRecyclerAdapter::count() const
{
    return m_count;
}

void QtQmlAndroidRecyclerAdapter::setCount(int count)
{
    if (m_count != count) {
        m_count = count;
        QtQmlAndroid::callIntMethod(instance(), "setItemCount", count);
        emit countChanged();
    }
}

QQmlComponent *QtQmlAndroidRecyclerAdapter::delegate() const
{
    return m_delegate;
}

void QtQmlAndroidRecyclerAdapter::setDelegate(QQmlComponent *delegate)
{
    if (m_delegate != delegate) {
        m_delegate = delegate;
        QtQmlAndroid::callVoidMethod(instance(), "notifyDataSetChanged");
        emit delegateChanged();
    }
}

QAndroidJniObject QtQmlAndroidRecyclerAdapter::onCreate()
{
    return QAndroidJniObject("qt/android/support/v7/widget/QtRecyclerAdapter",
                             "(IJ)V",
                             m_count,
                             reinterpret_cast<jlong>(this));
}

void QtQmlAndroidRecyclerAdapter::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidContextual::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }

    if (m_count > 0)
        instance.callMethod<void>("setItemCount", "(I)V", m_count);
}

void QtQmlAndroidRecyclerAdapter::onRegisterNativeMethods(jobject adapter)
{
    JNINativeMethod methods[] {{"onCreateViewHolder", "(JLandroid/view/ViewGroup;I)Lqt/android/support/v7/widget/QtRecyclerAdapter$ViewHolder;", reinterpret_cast<void *>(onCreateViewHolder)},
                               {"onBindViewHolder", "(JLqt/android/support/v7/widget/QtRecyclerAdapter$ViewHolder;I)V", reinterpret_cast<void *>(onBindViewHolder)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(adapter);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

jobject QtQmlAndroidRecyclerAdapter::onCreateViewHolder(JNIEnv *env, jobject object, jlong instance, jobject parent, jint viewType)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    Q_UNUSED(parent);
    Q_UNUSED(viewType);
    QtQmlAndroidRecyclerAdapter *adapter = reinterpret_cast<QtQmlAndroidRecyclerAdapter *>(instance);
    if (adapter) {
        QtQmlAndroidView *item = 0;
        QMetaObject::invokeMethod(adapter, "createItem", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QtQmlAndroidView *, item));
        item->construct();
        adapter->m_holders += QAndroidJniObject("qt/android/support/v7/widget/QtRecyclerAdapter$ViewHolder",
                                                "(Landroid/view/View;J)V",
                                                item->instance().object(),
                                                reinterpret_cast<jlong>(item));
        return adapter->m_holders.last().object();
    }
    return 0;
}

void QtQmlAndroidRecyclerAdapter::onBindViewHolder(JNIEnv *env, jobject object, jlong instance, jobject holder, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidRecyclerAdapter *adapter = reinterpret_cast<QtQmlAndroidRecyclerAdapter *>(instance);
    if (adapter) {
        jlong vi = QAndroidJniObject(holder).callMethod<jlong>("getInstance");
        QtQmlAndroidView *item = reinterpret_cast<QtQmlAndroidView *>(vi);
        if (item)
            QMetaObject::invokeMethod(adapter, "setItemPosition", Qt::BlockingQueuedConnection, Q_ARG(QtQmlAndroidView *, item), Q_ARG(int, position));
    }
}

QtQmlAndroidView *QtQmlAndroidRecyclerAdapter::createItem()
{
    QtQmlAndroidView *item = 0;
    if (m_delegate) {
        QQmlContext *creationContext = m_delegate->creationContext();
        QQmlContext *context = new QQmlContext(creationContext ? creationContext : qmlContext(this));
        QObject *object = m_delegate->beginCreate(context);
        if (object) {
            context->setParent(object);
            item = qobject_cast<QtQmlAndroidView *>(object);
            if (!item)
                delete object;
        } else {
            delete context;
        }
    } else {
        item = new QtQmlAndroidView;
    }
    if (item) {
        item->setContext(context());
        item->setParentView(qobject_cast<QtQmlAndroidView *>(parent())); // TODO
        setItemPosition(item, -1);
    }
    if (m_delegate)
        m_delegate->completeCreate();
    return item;
}

void QtQmlAndroidRecyclerAdapter::setItemPosition(QtQmlAndroidView *item, int position)
{
    QQmlContext *context = qmlContext(item);
    if (context)
        context = context->parentContext();
    if (context)
        context->setContextProperty("position", position);
}

QT_END_NAMESPACE
