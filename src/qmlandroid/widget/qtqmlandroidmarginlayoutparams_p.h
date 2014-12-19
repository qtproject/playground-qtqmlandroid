#ifndef QTQMLANDROIDMARGINLAYOUTPARAMS_P_H
#define QTQMLANDROIDMARGINLAYOUTPARAMS_P_H

#include "qtqmlandroidlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidMarginLayoutParams : public QtQmlAndroidLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int margin READ margin WRITE setMargin NOTIFY marginChanged)
    Q_PROPERTY(int topMargin READ topMargin WRITE setTopMargin NOTIFY topMarginChanged)
    Q_PROPERTY(int leftMargin READ leftMargin WRITE setLeftMargin NOTIFY leftMarginChanged)
    Q_PROPERTY(int rightMargin READ rightMargin WRITE setRightMargin NOTIFY rightMarginChanged)
    Q_PROPERTY(int bottomMargin READ bottomMargin WRITE setBottomMargin NOTIFY bottomMarginChanged)

public:
    explicit QtQmlAndroidMarginLayoutParams(QtQmlAndroidView *view);

    int margin() const;
    void setMargin(int margin);

    int topMargin() const;
    void setTopMargin(int margin);

    int leftMargin() const;
    void setLeftMargin(int margin);

    int rightMargin() const;
    void setRightMargin(int margin);

    int bottomMargin() const;
    void setBottomMargin(int margin);

Q_SIGNALS:
    void marginChanged();
    void topMarginChanged();
    void leftMarginChanged();
    void rightMarginChanged();
    void bottomMarginChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QtQmlAndroidOptional<int> m_margin;
    QtQmlAndroidOptional<int> m_topMargin;
    QtQmlAndroidOptional<int> m_leftMargin;
    QtQmlAndroidOptional<int> m_rightMargin;
    QtQmlAndroidOptional<int> m_bottomMargin;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDMARGINLAYOUTPARAMS_P_H
