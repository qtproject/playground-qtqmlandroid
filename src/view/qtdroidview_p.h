#ifndef QTDROIDVIEW_P_H
#define QTDROIDVIEW_P_H

#include "qtdroidobject_p.h"
#include "qtdroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtDroidContext;
class QtDroidLayoutParams;

class QtDroidView : public QtDroidObject
{
    Q_OBJECT
    Q_PROPERTY(QtDroidContext *context READ context NOTIFY contextChanged)
    Q_PROPERTY(QQmlListProperty<QtDroidView> children READ children NOTIFY childrenChanged)
    Q_PROPERTY(bool focus READ hasFocus WRITE setFocus NOTIFY focusChanged)
    Q_PROPERTY(qreal x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(qreal y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(qreal width READ width WRITE setWidth NOTIFY widthChanged) // TODO: reset
    Q_PROPERTY(qreal height READ height WRITE setHeight NOTIFY heightChanged) // TODO: reset

public:
    explicit QtDroidView(QObject *parent = 0);

    QtDroidContext *context() const;
    void setContext(QtDroidContext *context);

    QQmlListProperty<QtDroidView> children();

    bool hasFocus() const;
    void setFocus(bool focus);

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
        ViewChangeData(QtDroidView *v) : view(v) {}
        ViewChangeData(QtDroidContext *c) : context(c) {}
        ViewChangeData(qreal n) : number(n) {}
        ViewChangeData(bool b) : boolean(b) {}

        QtDroidView *view;
        QtDroidContext *context;
        qreal number;
        bool boolean;
    };

Q_SIGNALS:
    void contextChanged();
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

    void objectAdded(QObject *object) Q_DECL_OVERRIDE;
    void objectRemoved(QObject *object) Q_DECL_OVERRIDE;

    void addChild(QtDroidView *child);
    void removeChild(QtDroidView *child);

    static void children_append(QQmlListProperty<QtDroidView> *list, QtDroidView *child);
    static int children_count(QQmlListProperty<QtDroidView> *list);
    static QtDroidView *children_at(QQmlListProperty<QtDroidView> *list, int index);
    static void children_clear(QQmlListProperty<QtDroidView> *list);

    virtual QAndroidJniObject construct(jobject context);
    virtual void inflate(jobject context);

    static void registerNativeMethods(jobject listener);
    static void onClick(JNIEnv *env, jobject object, jlong instance);
    static void onFocusChange(JNIEnv *env, jobject object, jlong instance, jboolean hasFocus);
    static void onLayoutChange(JNIEnv *env, jobject object, jlong instance, jint top, jint left, jint right, jint bottom);
    static bool onLongClick(JNIEnv *env, jobject object, jlong instance);

    void customEvent(QEvent *event) Q_DECL_OVERRIDE;

private Q_SLOTS:
    bool updateFocus(bool focus);

private:
    void invalidateLayoutParams();
    void setLayoutParams(QtDroidLayoutParams *params);

    QtDroidContext *m_context;
    QList<QtDroidView *> m_children;

    QAndroidJniObject m_listener;

    bool m_layoutParamsDirty;
    QtDroidLayoutParams *m_layoutParams;

    QtDroidOptional<bool> m_focus;
    qreal m_x, m_y, m_width, m_height;

    friend class QtDroidLayoutParams;
    friend class QtDroidViewGroup;
    friend class QtDroidActivity;
};

QT_END_NAMESPACE

#endif // QTDROIDVIEW_P_H
