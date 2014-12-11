#ifndef QTANDROIDSCROLLVIEW_P_H
#define QTANDROIDSCROLLVIEW_P_H

#include "qtandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidScrollView : public QtAndroidFrameLayout
{
    Q_OBJECT
    Q_PROPERTY(int scrollX READ scrollX WRITE setScrollX NOTIFY scrollXChanged)
    Q_PROPERTY(int scrollY READ scrollY WRITE setScrollY NOTIFY scrollYChanged)

public:
    explicit QtAndroidScrollView(QtAndroidView *parent = 0);

    int scrollX() const;
    void setScrollX(int x);

    int scrollY() const;
    void setScrollY(int y);

Q_SIGNALS:
    void scrollXChanged();
    void scrollYChanged();

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onScrollChanged(JNIEnv *env, jobject object, jlong instance, jint left, jint top);

private Q_SLOTS:
    bool updateScrollX(int x);
    bool updateScrollY(int y);

private:
    QtAndroidOptional<int> m_scrollX;
    QtAndroidOptional<int> m_scrollY;
};

QT_END_NAMESPACE

#endif // QTANDROIDSCROLLVIEW_P_H
