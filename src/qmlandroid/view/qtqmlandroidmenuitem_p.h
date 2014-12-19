#ifndef QTQMLANDROIDMENUITEM_P_H
#define QTQMLANDROIDMENUITEM_P_H

#include "qtqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidView;

class QtQmlAndroidMenuItem : public QtQmlAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(bool checkable READ isCheckable WRITE setCheckable NOTIFY checkableChanged)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked NOTIFY checkedChanged)
    Q_PROPERTY(int showAs READ showAs WRITE setShowAs NOTIFY showAsChanged)
    Q_PROPERTY(QtQmlAndroidView *actionView READ actionView WRITE setActionView NOTIFY actionViewChanged)
    Q_ENUMS(ShowAs)

public:
    explicit QtQmlAndroidMenuItem(QObject *parent = 0);

    QString title() const;
    void setTitle(const QString &title);

    bool isEnabled() const;
    void setEnabled(bool enabled);

    bool isVisible() const;
    void setVisible(bool visible);

    bool isCheckable() const;
    void setCheckable(bool checkable);

    bool isChecked() const;
    void setChecked(bool checked);

    enum ShowAs {
        SHOW_AS_ACTION_NEVER = 0,
        SHOW_AS_ACTION_IF_ROOM = 1,
        SHOW_AS_ACTION_ALWAYS = 2,
        SHOW_AS_ACTION_WITH_TEXT = 4,
        SHOW_AS_ACTION_COLLAPSE_ACTION_VIEW = 8
    };

    int showAs() const;
    void setShowAs(int showAs);

    QtQmlAndroidView *actionView() const;
    void setActionView(QtQmlAndroidView *view);

Q_SIGNALS:
    void click();
    void titleChanged();
    void enabledChanged();
    void visibleChanged();
    void checkableChanged();
    void checkedChanged();
    void showAsChanged();
    void actionViewChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject item);
    static bool onClick(JNIEnv *env, jobject object, jlong instance);
    static bool onMenuItemActionCollapse(JNIEnv *env, jobject object, jlong instance);
    static bool onMenuItemActionExpand(JNIEnv *env, jobject object, jlong instance);

    void objectChange(ObjectChange change) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateActionView();

private:
    QString m_title;
    bool m_enabled;
    bool m_visible;
    bool m_checkable;
    bool m_checked;
    int m_showAs;
    QtQmlAndroidView *m_actionView;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDMENUITEM_P_H
