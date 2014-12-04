#ifndef QTDROIDLAYOUTPARAMS_P_H
#define QTDROIDLAYOUTPARAMS_P_H

#include <QtCore/qobject.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include "qtdroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtDroidView;

class QtDroidLayoutParams : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
    Q_ENUMS(Size)

public:
    explicit QtDroidLayoutParams(QtDroidView *view);

    enum Size {
        FILL_PARENT = -1,
        MATCH_PARENT = -1,
        WRAP_CONTENT = -2
    };

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    void apply(QtDroidView *view);

Q_SIGNALS:
    void widthChanged();
    void heightChanged();

protected:
    virtual QAndroidJniObject construct();
    virtual void inflate(QAndroidJniObject &params);

private:
    QtDroidView *m_view;
    QtDroidOptional<int> m_width;
    QtDroidOptional<int> m_height;
};

QT_END_NAMESPACE

#endif // QTDROIDLAYOUTPARAMS_P_H
