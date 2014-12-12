#ifndef QTANDROIDVIEW_P_H
#define QTANDROIDVIEW_P_H

#include "qtandroidobject_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidContext;
class QtAndroidDrawable;
class QtAndroidLayoutParams;

class QtAndroidView : public QtAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidContext *context READ context NOTIFY contextChanged)
    Q_PROPERTY(QtAndroidView *parent READ parentView WRITE setParentView NOTIFY parentChanged)
    Q_PROPERTY(QQmlListProperty<QtAndroidView> children READ children NOTIFY childrenChanged)
    Q_PROPERTY(QtAndroidDrawable *background READ background WRITE setBackground NOTIFY backgroundChanged)
    Q_PROPERTY(bool focus READ hasFocus NOTIFY focusChanged)
    Q_PROPERTY(qreal x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(qreal y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(qreal width READ width WRITE setWidth NOTIFY widthChanged) // TODO: reset
    Q_PROPERTY(qreal height READ height WRITE setHeight NOTIFY heightChanged) // TODO: reset

public:
    explicit QtAndroidView(QtAndroidView *parent = 0);
    ~QtAndroidView();

    int identifier() const;
    void setIdentifier(int id);

    QAndroidJniObject ctx() const;
    QtAndroidContext *context() const;
    void setContext(QtAndroidContext *context);

    QtAndroidView *parentView() const;
    void setParentView(QtAndroidView *parent);

    QList<QtAndroidView *> childViews() const;
    QQmlListProperty<QtAndroidView> children();

    QtAndroidDrawable *background() const;
    void setBackground(QtAndroidDrawable *background);

    bool hasFocus() const;

    qreal x() const;
    void setX(qreal x);

    qreal y() const;
    void setY(qreal y);

    qreal width() const;
    void setWidth(qreal width);

    qreal height() const;
    void setHeight(qreal height);

    enum ViewChange {
        ViewContextChange,      // data.context
        ViewParentChange,       // data.view
        ViewChildAddedChange,   // data.view
        ViewChildRemovedChange, // data.view
        ViewVisibilityChange,   // data.boolean
    };

    union ViewChangeData {
        ViewChangeData(QtAndroidView *v) : view(v) {}
        ViewChangeData(QtAndroidContext *c) : context(c) {}
        ViewChangeData(qreal n) : number(n) {}
        ViewChangeData(bool b) : boolean(b) {}

        QtAndroidView *view;
        QtAndroidContext *context;
        qreal number;
        bool boolean;
    };

Q_SIGNALS:
    void contextChanged();
    void parentChanged();
    void backgroundChanged();
    void childrenChanged();
    void focusChanged();
    void click();
    void xChanged();
    void yChanged();
    void widthChanged();
    void heightChanged();
    void longClick(); // TODO: accept

protected:
    virtual void viewChange(ViewChange change, const ViewChangeData &data);

    void addChild(QtAndroidView *child);
    void removeChild(QtAndroidView *child);

    static void children_append(QQmlListProperty<QtAndroidView> *list, QtAndroidView *child);
    static int children_count(QQmlListProperty<QtAndroidView> *list);
    static QtAndroidView *children_at(QQmlListProperty<QtAndroidView> *list, int index);
    static void children_clear(QQmlListProperty<QtAndroidView> *list);

    virtual QAndroidJniObject construct();
    virtual void inflate();

    static void registerNativeMethods(jobject listener);
    static void onClick(JNIEnv *env, jobject object, jlong instance);
    static void onFocusChange(JNIEnv *env, jobject object, jlong instance, jboolean hasFocus);
    static void onLayoutChange(JNIEnv *env, jobject object, jlong instance, jint top, jint left, jint right, jint bottom);
    static bool onLongClick(JNIEnv *env, jobject object, jlong instance);

    bool event(QEvent *event) Q_DECL_OVERRIDE;

private Q_SLOTS:
    bool updateFocus(bool focus);

private:
    void invalidateLayoutParams();
    void setLayoutParams(QtAndroidLayoutParams *params);

    int m_id;
    QtAndroidContext *m_context;
    QtAndroidView *m_parent;
    QList<QtAndroidView *> m_children;
    QtAndroidDrawable *m_background;

    QAndroidJniObject m_listener;

    bool m_layoutParamsDirty;
    QtAndroidLayoutParams *m_layoutParams;

    QtAndroidOptional<bool> m_focus;
    qreal m_x, m_y, m_width, m_height;

    friend class QtAndroidLayoutParams;
    friend class QtAndroidViewGroup;
    friend class QtAndroidActivity;
};

QT_END_NAMESPACE

#endif // QTANDROIDVIEW_P_H
