#include "qtandroidrecycleradapter_p.h"
#include "qtandroidfunctions_p.h"
#include "qtandroidview_p.h"
#include <QtQml/qqmlcomponent.h>
#include <QtQml/qqmlcontext.h>

QtAndroidRecyclerAdapter::QtAndroidRecyclerAdapter(QObject *parent) :
    QtAndroidContextual(parent), m_count(0), m_delegate(0)
{
}

int QtAndroidRecyclerAdapter::count() const
{
    return m_count;
}

void QtAndroidRecyclerAdapter::setCount(int count)
{
    if (m_count != count) {
        m_count = count;
        QtAndroid::callIntMethod(instance(), "setItemCount", count);
        emit countChanged();
    }
}

QQmlComponent *QtAndroidRecyclerAdapter::delegate() const
{
    return m_delegate;
}

void QtAndroidRecyclerAdapter::setDelegate(QQmlComponent *delegate)
{
    if (m_delegate != delegate) {
        m_delegate = delegate;
        QtAndroid::callVoidMethod(instance(), "notifyDataSetChanged");
        emit delegateChanged();
    }
}

QAndroidJniObject QtAndroidRecyclerAdapter::onCreate()
{
    return QAndroidJniObject("qt/android/support/v7/widget/QtRecyclerAdapter",
                             "(IJ)V",
                             m_count,
                             reinterpret_cast<jlong>(this));
}

void QtAndroidRecyclerAdapter::onInflate(QAndroidJniObject &instance)
{
    QtAndroidContextual::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }

    if (m_count > 0)
        instance.callMethod<void>("setItemCount", "(I)V", m_count);
}

void QtAndroidRecyclerAdapter::registerNativeMethods(jobject adapter)
{
    JNINativeMethod methods[] {{"onCreateViewHolder", "(JLandroid/view/ViewGroup;I)Lqt/android/support/v7/widget/QtRecyclerAdapter$ViewHolder;", reinterpret_cast<void *>(onCreateViewHolder)},
                               {"onBindViewHolder", "(JLqt/android/support/v7/widget/QtRecyclerAdapter$ViewHolder;I)V", reinterpret_cast<void *>(onBindViewHolder)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(adapter);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

jobject QtAndroidRecyclerAdapter::onCreateViewHolder(JNIEnv *env, jobject object, jlong instance, jobject parent, jint viewType)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    Q_UNUSED(parent);
    Q_UNUSED(viewType);
    QtAndroidRecyclerAdapter *adapter = reinterpret_cast<QtAndroidRecyclerAdapter *>(instance);
    if (adapter) {
        QtAndroidView *item = 0;
        QMetaObject::invokeMethod(adapter, "createItem", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QtAndroidView *, item));
        QAndroidJniObject it = item->onCreate();
        item->onInflate(it);
        item->setInstance(it);
        adapter->m_holders += QAndroidJniObject("qt/android/support/v7/widget/QtRecyclerAdapter$ViewHolder",
                                                "(Landroid/view/View;J)V",
                                                it.object(),
                                                reinterpret_cast<jlong>(item));
        return adapter->m_holders.last().object();
    }
    return 0;
}

void QtAndroidRecyclerAdapter::onBindViewHolder(JNIEnv *env, jobject object, jlong instance, jobject holder, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidRecyclerAdapter *adapter = reinterpret_cast<QtAndroidRecyclerAdapter *>(instance);
    if (adapter) {
        jlong vi = QAndroidJniObject(holder).callMethod<jlong>("getInstance");
        QtAndroidView *item = reinterpret_cast<QtAndroidView *>(vi);
        if (item)
            QMetaObject::invokeMethod(adapter, "setItemPosition", Qt::BlockingQueuedConnection, Q_ARG(QtAndroidView *, item), Q_ARG(int, position));
    }
}

QtAndroidView *QtAndroidRecyclerAdapter::createItem()
{
    QtAndroidView *item = 0;
    if (m_delegate) {
        QQmlContext *creationContext = m_delegate->creationContext();
        QQmlContext *context = new QQmlContext(creationContext ? creationContext : qmlContext(this));
        QObject *object = m_delegate->beginCreate(context);
        if (object) {
            context->setParent(object);
            item = qobject_cast<QtAndroidView *>(object);
            if (!item)
                delete object;
        } else {
            delete context;
        }
    } else {
        item = new QtAndroidView;
    }
    if (item) {
        item->setContext(context());
        item->setParentView(qobject_cast<QtAndroidView *>(parent())); // TODO
        setItemPosition(item, -1);
    }
    if (m_delegate)
        m_delegate->completeCreate();
    return item;
}

void QtAndroidRecyclerAdapter::setItemPosition(QtAndroidView *item, int position)
{
    QQmlContext *context = qmlContext(item);
    if (context)
        context = context->parentContext();
    if (context)
        context->setContextProperty("position", position);
}
