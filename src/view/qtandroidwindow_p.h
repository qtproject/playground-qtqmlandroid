#ifndef QTANDROIDWINDOW_P_H
#define QTANDROIDWINDOW_P_H

#include "qtandroidcontextual_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidWindow : public QtAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int statusBarColor READ statusBarColor WRITE setStatusBarColor NOTIFY statusBarColorChanged)

public:
    explicit QtAndroidWindow(QtAndroidContext *context);

    int statusBarColor() const;
    void setStatusBarColor(int color);

Q_SIGNALS:
    void statusBarColorChanged();

protected:
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QtAndroidOptional<int> m_statusBarColor;
    friend class QtAndroidActivity;
};

QT_END_NAMESPACE

#endif // QTANDROIDWINDOW_P_H
