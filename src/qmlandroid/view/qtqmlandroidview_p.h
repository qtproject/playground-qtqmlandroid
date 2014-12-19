#ifndef QTQMLANDROIDVIEW_P_H
#define QTQMLANDROIDVIEW_P_H

#include "qtqmlandroidcontextual_p.h"
#include "qtqmlandroidoptional_p.h"
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidDrawable;
class QtQmlAndroidAnimation;
class QtQmlAndroidLayoutParams;

class QtQmlAndroidView : public QtQmlAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(QtQmlAndroidView *parent READ parentView WRITE setParentView NOTIFY parentChanged)
    Q_PROPERTY(QQmlListProperty<QtQmlAndroidView> children READ children NOTIFY childrenChanged)

    Q_PROPERTY(QtQmlAndroidDrawable *background READ background WRITE setBackground NOTIFY backgroundChanged)
    Q_PROPERTY(int backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(int backgroundResource READ backgroundResource WRITE setBackgroundResource NOTIFY backgroundResourceChanged)

    Q_PROPERTY(QtQmlAndroidAnimation *animation READ animation WRITE setAnimation NOTIFY animationChanged)

    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(bool focus READ hasFocus NOTIFY focusChanged)

    Q_PROPERTY(qreal x READ x NOTIFY xChanged)
    Q_PROPERTY(qreal y READ y NOTIFY yChanged)
    Q_PROPERTY(int top READ top WRITE setTop NOTIFY topChanged)
    Q_PROPERTY(int left READ left WRITE setLeft NOTIFY leftChanged)
    Q_PROPERTY(int right READ right WRITE setRight NOTIFY rightChanged)
    Q_PROPERTY(int bottom READ bottom WRITE setBottom NOTIFY bottomChanged)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)

    Q_PROPERTY(int padding READ padding WRITE setPadding NOTIFY paddingChanged)
    Q_PROPERTY(int paddingTop READ paddingTop WRITE setPaddingTop NOTIFY paddingTopChanged)
    Q_PROPERTY(int paddingLeft READ paddingLeft WRITE setPaddingLeft NOTIFY paddingLeftChanged)
    Q_PROPERTY(int paddingRight READ paddingRight WRITE setPaddingRight NOTIFY paddingRightChanged)
    Q_PROPERTY(int paddingBottom READ paddingBottom WRITE setPaddingBottom NOTIFY paddingBottomChanged)

public:
    explicit QtQmlAndroidView(QtQmlAndroidView *parent = 0);
    ~QtQmlAndroidView();

    int identifier() const;
    void setIdentifier(int id);

    QtQmlAndroidView *parentView() const;
    void setParentView(QtQmlAndroidView *parent);

    QList<QtQmlAndroidView *> childViews() const;
    QQmlListProperty<QtQmlAndroidView> children();

    QtQmlAndroidLayoutParams *layoutParams() const;
    void setLayoutParams(QtQmlAndroidLayoutParams *params);

    QtQmlAndroidDrawable *background() const;
    void setBackground(QtQmlAndroidDrawable *background, int resource = 0);

    int backgroundColor() const;
    void setBackgroundColor(int color);

    int backgroundResource() const;
    void setBackgroundResource(int resource);

    QtQmlAndroidAnimation *animation() const;
    void setAnimation(QtQmlAndroidAnimation *animation);

    bool isVisible() const;
    void setVisible(bool visible);

    bool hasFocus() const;

    qreal x() const;
    qreal y() const;

    int top() const;
    void setTop(int top);

    int left() const;
    void setLeft(int left);

    int right() const;
    void setRight(int right);

    int bottom() const;
    void setBottom(int bottom);

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    int padding() const;
    void setPadding(int padding);

    int paddingTop() const;
    void setPaddingTop(int padding);

    int paddingLeft() const;
    void setPaddingLeft(int padding);

    int paddingRight() const;
    void setPaddingRight(int padding);

    int paddingBottom() const;
    void setPaddingBottom(int padding);

    void requestPolish();

    enum ViewChange {
        ViewParentChange,       // data.view
        ViewChildAddedChange,   // data.view
        ViewChildRemovedChange, // data.view
        ViewVisibilityChange,   // data.boolean
    };

    union ViewChangeData {
        ViewChangeData(QtQmlAndroidView *v) : view(v) {}
        ViewChangeData(qreal n) : number(n) {}
        ViewChangeData(bool b) : boolean(b) {}

        QtQmlAndroidView *view;
        qreal number;
        bool boolean;
    };

Q_SIGNALS:
    void parentChanged();
    void backgroundChanged();
    void backgroundColorChanged();
    void backgroundResourceChanged();
    void animationChanged();
    void childrenChanged();
    void visibleChanged();
    void focusChanged();
    void click();
    void xChanged();
    void yChanged();
    void topChanged();
    void leftChanged();
    void rightChanged();
    void bottomChanged();
    void widthChanged();
    void heightChanged();
    void paddingChanged();
    void paddingTopChanged();
    void paddingLeftChanged();
    void paddingRightChanged();
    void paddingBottomChanged();
    void longClick(); // TODO: accept

protected:
    virtual void polish();
    virtual void viewChange(ViewChange change, const ViewChangeData &data);

    void addChild(QtQmlAndroidView *child);
    void removeChild(QtQmlAndroidView *child);

    static void children_append(QQmlListProperty<QtQmlAndroidView> *list, QtQmlAndroidView *child);
    static int children_count(QQmlListProperty<QtQmlAndroidView> *list);
    static QtQmlAndroidView *children_at(QQmlListProperty<QtQmlAndroidView> *list, int index);
    static void children_clear(QQmlListProperty<QtQmlAndroidView> *list);

    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject listener);
    static void onClick(JNIEnv *env, jobject object, jlong instance);
    static void onFocusChange(JNIEnv *env, jobject object, jlong instance, jboolean hasFocus);
    static void onLayoutChange(JNIEnv *env, jobject object, jlong instance, jint left, jint top, jint right, jint bottom);
    static bool onLongClick(JNIEnv *env, jobject object, jlong instance);

    bool event(QEvent *event) Q_DECL_OVERRIDE;

    void objectChange(ObjectChange change) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateBackground();
    void updateAnimation();
    bool updateFocus(bool focus);
    void updateLayoutParams();
    void updateGeometry(int top, int left, int right, int bottom);

private:
    int m_id;
    QtQmlAndroidView *m_parent;
    QList<QtQmlAndroidView *> m_children;
    QtQmlAndroidDrawable *m_background;
    int m_backgroundResource;
    QtQmlAndroidAnimation *m_animation;
    bool m_polishing;
    bool m_visible;

    QAndroidJniObject m_listener;

    QtQmlAndroidLayoutParams *m_layoutParams;

    QtQmlAndroidOptional<bool> m_focus;
    QtQmlAndroidOptional<int> m_top;
    QtQmlAndroidOptional<int> m_left;
    QtQmlAndroidOptional<int> m_right;
    QtQmlAndroidOptional<int> m_bottom;
    QtQmlAndroidOptional<int> m_padding;
    QtQmlAndroidOptional<int> m_paddingTop;
    QtQmlAndroidOptional<int> m_paddingLeft;
    QtQmlAndroidOptional<int> m_paddingRight;
    QtQmlAndroidOptional<int> m_paddingBottom;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDVIEW_P_H
