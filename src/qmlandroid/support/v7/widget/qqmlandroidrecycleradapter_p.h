#ifndef QQMLANDROIDRECYCLERADAPTER_P_H
#define QQMLANDROIDRECYCLERADAPTER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QQmlComponent;
class QQmlAndroidView;

class QQmlAndroidRecyclerAdapter : public QQmlAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(QQmlComponent *delegate READ delegate WRITE setDelegate NOTIFY delegateChanged)

public:
    explicit QQmlAndroidRecyclerAdapter(QObject *parent = 0);

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
    QQmlAndroidView *createItem();
    void setItemPosition(QQmlAndroidView *item, int position);

private:
    int m_count;
    QQmlComponent *m_delegate;
    QList<QAndroidJniObject> m_holders;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDRECYCLERADAPTER_P_H
