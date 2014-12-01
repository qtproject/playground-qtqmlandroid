#ifndef QTDROIDLAYOUTPARAMS_P_H
#define QTDROIDLAYOUTPARAMS_P_H

#include "qtdroidobject_p.h"
#include "qtdroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtDroidView;

class QtDroidLayoutParams : public QtDroidObject
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

Q_SIGNALS:
    void widthChanged();
    void heightChanged();

protected:
    virtual QAndroidJniObject construct();
    virtual void applyParams(QAndroidJniObject &params);

private:
    QtDroidView *m_view;
    QtDroidOptional<int> m_width;
    QtDroidOptional<int> m_height;
    friend class QtDroidView;
};

QT_END_NAMESPACE

#endif // QTDROIDLAYOUTPARAMS_P_H
