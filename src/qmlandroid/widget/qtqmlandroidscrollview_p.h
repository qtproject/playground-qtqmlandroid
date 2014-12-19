#ifndef QQMLANDROIDSCROLLVIEW_P_H
#define QQMLANDROIDSCROLLVIEW_P_H

#include "qtqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidScrollView : public QQmlAndroidFrameLayout
{
    Q_OBJECT
    Q_PROPERTY(int scrollX READ scrollX WRITE setScrollX NOTIFY scrollXChanged)
    Q_PROPERTY(int scrollY READ scrollY WRITE setScrollY NOTIFY scrollYChanged)

public:
    explicit QQmlAndroidScrollView(QQmlAndroidView *parent = 0);

    int scrollX() const;
    void setScrollX(int x);

    int scrollY() const;
    void setScrollY(int y);

Q_SIGNALS:
    void scrollXChanged();
    void scrollYChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject listener);
    static void onScrollChanged(JNIEnv *env, jobject object, jlong instance, jint left, jint top);

private Q_SLOTS:
    bool updateScrollX(int x);
    bool updateScrollY(int y);

private:
    QQmlAndroidOptional<int> m_scrollX;
    QQmlAndroidOptional<int> m_scrollY;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDSCROLLVIEW_P_H
