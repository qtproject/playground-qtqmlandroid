#ifndef QTDROIDMARGINLAYOUTPARAMS_P_H
#define QTDROIDMARGINLAYOUTPARAMS_P_H

#include "qtdroidlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtDroidMarginLayoutParams : public QtDroidLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int topMargin READ topMargin WRITE setTopMargin NOTIFY topMarginChanged)
    Q_PROPERTY(int leftMargin READ leftMargin WRITE setLeftMargin NOTIFY leftMarginChanged)
    Q_PROPERTY(int rightMargin READ rightMargin WRITE setRightMargin NOTIFY rightMarginChanged)
    Q_PROPERTY(int bottomMargin READ bottomMargin WRITE setBottomMargin NOTIFY bottomMarginChanged)

public:
    explicit QtDroidMarginLayoutParams(QtDroidView *view);

    int topMargin() const;
    void setTopMargin(int margin);

    int leftMargin() const;
    void setLeftMargin(int margin);

    int rightMargin() const;
    void setRightMargin(int margin);

    int bottomMargin() const;
    void setBottomMargin(int margin);

Q_SIGNALS:
    void topMarginChanged();
    void leftMarginChanged();
    void rightMarginChanged();
    void bottomMarginChanged();

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void applyParams(QAndroidJniObject &params) Q_DECL_OVERRIDE;

private:
    QtDroidOptional<int> m_topMargin;
    QtDroidOptional<int> m_leftMargin;
    QtDroidOptional<int> m_rightMargin;
    QtDroidOptional<int> m_bottomMargin;
};

QT_END_NAMESPACE

#endif // QTDROIDMARGINLAYOUTPARAMS_P_H
