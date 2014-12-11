#ifndef QTANDROIDLAYOUTPARAMS_P_H
#define QTANDROIDLAYOUTPARAMS_P_H

#include <QtCore/qobject.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include "qtdroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidView;

class QtAndroidLayoutParams : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
    Q_ENUMS(Size)

public:
    explicit QtAndroidLayoutParams(QtAndroidView *view);

    enum Size {
        FILL_PARENT = -1,
        MATCH_PARENT = -1,
        WRAP_CONTENT = -2
    };

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    void apply(QtAndroidView *view);

Q_SIGNALS:
    void widthChanged();
    void heightChanged();

protected:
    virtual QAndroidJniObject construct();
    virtual void inflate(QAndroidJniObject &params);

private:
    QtAndroidView *m_view;
    QtAndroidOptional<int> m_width;
    QtAndroidOptional<int> m_height;
};

QT_END_NAMESPACE

#endif // QTANDROIDLAYOUTPARAMS_P_H
