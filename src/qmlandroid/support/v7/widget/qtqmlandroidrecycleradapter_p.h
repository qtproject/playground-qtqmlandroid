#ifndef QTQMLANDROIDRECYCLERADAPTER_P_H
#define QTQMLANDROIDRECYCLERADAPTER_P_H

#include "qtqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QQmlComponent;
class QtQmlAndroidView;

class QtQmlAndroidRecyclerAdapter : public QtQmlAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(QQmlComponent *delegate READ delegate WRITE setDelegate NOTIFY delegateChanged)

public:
    explicit QtQmlAndroidRecyclerAdapter(QObject *parent = 0);

    int count() const;
    void setCount(int count);

    QQmlComponent *delegate() const;
    void setDelegate(QQmlComponent *delegate);

Q_SIGNALS:
    void countChanged();
    void delegateChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject adapter);
    static jobject onCreateViewHolder(JNIEnv *env, jobject object, jlong instance, jobject parent, jint viewType);
    static void onBindViewHolder(JNIEnv *env, jobject object, jlong instance, jobject holder, jint position);

private Q_SLOTS:
    QtQmlAndroidView *createItem();
    void setItemPosition(QtQmlAndroidView *item, int position);

private:
    int m_count;
    QQmlComponent *m_delegate;
    QList<QAndroidJniObject> m_holders;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDRECYCLERADAPTER_P_H
