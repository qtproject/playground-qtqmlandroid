#ifndef QTANDROIDMARGINLAYOUTPARAMS_P_H
#define QTANDROIDMARGINLAYOUTPARAMS_P_H

#include "qtandroidlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidMarginLayoutParams : public QtAndroidLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int topMargin READ topMargin WRITE setTopMargin NOTIFY topMarginChanged)
    Q_PROPERTY(int leftMargin READ leftMargin WRITE setLeftMargin NOTIFY leftMarginChanged)
    Q_PROPERTY(int rightMargin READ rightMargin WRITE setRightMargin NOTIFY rightMarginChanged)
    Q_PROPERTY(int bottomMargin READ bottomMargin WRITE setBottomMargin NOTIFY bottomMarginChanged)

public:
    explicit QtAndroidMarginLayoutParams(QtAndroidView *view);

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
    QAndroidJniObject onConstruct() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &params) Q_DECL_OVERRIDE;

private:
    QtAndroidOptional<int> m_topMargin;
    QtAndroidOptional<int> m_leftMargin;
    QtAndroidOptional<int> m_rightMargin;
    QtAndroidOptional<int> m_bottomMargin;
};

QT_END_NAMESPACE

#endif // QTANDROIDMARGINLAYOUTPARAMS_P_H
