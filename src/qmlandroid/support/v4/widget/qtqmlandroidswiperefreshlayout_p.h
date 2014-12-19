#ifndef QQMLANDROIDSWIPEREFRESHLAYOUT_P_H
#define QQMLANDROIDSWIPEREFRESHLAYOUT_P_H

#include "qtqmlandroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidSwipeRefreshLayout : public QQmlAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(bool refreshing READ isRefreshing WRITE setRefreshing NOTIFY refreshingChanged)

public:
    explicit QQmlAndroidSwipeRefreshLayout(QQmlAndroidView *parent = 0);

    bool isRefreshing() const;
    void setRefreshing(bool refreshing);

Q_SIGNALS:
    void refreshingChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject listener);
    static void onRefresh(JNIEnv *env, jobject object, jlong instance);

private Q_SLOTS:
    bool updateRefreshing(bool refreshing);

private:
    bool m_refreshing;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDSWIPEREFRESHLAYOUT_P_H
