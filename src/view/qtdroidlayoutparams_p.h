#ifndef QTDROIDLAYOUTPARAMS_P_H
#define QTDROIDLAYOUTPARAMS_P_H

#include "qtdroidobject_p.h"
#include "qtdroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtDroidView;

class QtDroidLayoutParams : public QtDroidObject
{
    Q_OBJECT
    Q_PROPERTY(Size width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(Size height READ height WRITE setHeight NOTIFY heightChanged)
    Q_ENUMS(Size)

public:
    explicit QtDroidLayoutParams(QtDroidView *view);

    enum Size {
        FILL_PARENT = -1,
        MATCH_PARENT = -1,
        WRAP_CONTENT = -2
    };

    Size width() const;
    void setWidth(Size width);

    Size height() const;
    void setHeight(Size height);

Q_SIGNALS:
    void widthChanged();
    void heightChanged();

protected:
    virtual QAndroidJniObject construct();
    virtual void applyParams(QAndroidJniObject &params);

private:
    QtDroidView *m_view;
    QtDroidOptional<Size> m_width;
    QtDroidOptional<Size> m_height;
    friend class QtDroidView;
};

QT_END_NAMESPACE

#endif // QTDROIDLAYOUTPARAMS_P_H
