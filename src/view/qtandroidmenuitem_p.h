#ifndef QTANDROIDMENUITEM_P_H
#define QTANDROIDMENUITEM_P_H

#include "qtandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidMenuItem : public QtAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(bool checkable READ isCheckable WRITE setCheckable NOTIFY checkableChanged)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked NOTIFY checkedChanged)

public:
    explicit QtAndroidMenuItem(QObject *parent = 0);

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

Q_SIGNALS:
    void click();
    void titleChanged();
    void enabledChanged();
    void visibleChanged();
    void checkableChanged();
    void checkedChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject item);
    static bool onClick(JNIEnv *env, jobject object, jlong instance);

private:
    QString m_title;
    bool m_enabled;
    bool m_visible;
    bool m_checkable;
    bool m_checked;
};

QT_END_NAMESPACE

#endif // QTANDROIDMENUITEM_P_H
