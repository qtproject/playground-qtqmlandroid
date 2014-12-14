#ifndef QTANDROIDLAYOUTPARAMS_P_H
#define QTANDROIDLAYOUTPARAMS_P_H

#include "qtandroidobject_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidView;

class QtAndroidLayoutParams : public QtAndroidObject
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

Q_SIGNALS:
    void widthChanged();
    void heightChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QtAndroidView *m_view;
    QtAndroidOptional<int> m_width;
    QtAndroidOptional<int> m_height;
};

QT_END_NAMESPACE

#endif // QTANDROIDLAYOUTPARAMS_P_H
