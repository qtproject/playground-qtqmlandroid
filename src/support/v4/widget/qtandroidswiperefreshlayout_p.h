#ifndef QTANDROIDSWIPEREFRESHLAYOUT_P_H
#define QTANDROIDSWIPEREFRESHLAYOUT_P_H

#include "qtandroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidSwipeRefreshLayout : public QtAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(bool refreshing READ isRefreshing WRITE setRefreshing NOTIFY refreshingChanged)

public:
    explicit QtAndroidSwipeRefreshLayout(QtAndroidView *parent = 0);

    bool isRefreshing() const;
    void setRefreshing(bool refreshing);

Q_SIGNALS:
    void refreshingChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onRefresh(JNIEnv *env, jobject object, jlong instance);

private Q_SLOTS:
    bool updateRefreshing(bool refreshing);

private:
    bool m_refreshing;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTANDROIDSWIPEREFRESHLAYOUT_P_H
