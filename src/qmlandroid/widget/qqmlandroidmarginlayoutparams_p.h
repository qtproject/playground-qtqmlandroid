#ifndef QQMLANDROIDMARGINLAYOUTPARAMS_P_H
#define QQMLANDROIDMARGINLAYOUTPARAMS_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qqmlandroidlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidMarginLayoutParams : public QQmlAndroidLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int margin READ margin WRITE setMargin NOTIFY marginChanged)
    Q_PROPERTY(int topMargin READ topMargin WRITE setTopMargin NOTIFY topMarginChanged)
    Q_PROPERTY(int leftMargin READ leftMargin WRITE setLeftMargin NOTIFY leftMarginChanged)
    Q_PROPERTY(int rightMargin READ rightMargin WRITE setRightMargin NOTIFY rightMarginChanged)
    Q_PROPERTY(int bottomMargin READ bottomMargin WRITE setBottomMargin NOTIFY bottomMarginChanged)

public:
    explicit QQmlAndroidMarginLayoutParams(QQmlAndroidView *view);

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
    QQmlAndroidOptional<int> m_margin;
    QQmlAndroidOptional<int> m_topMargin;
    QQmlAndroidOptional<int> m_leftMargin;
    QQmlAndroidOptional<int> m_rightMargin;
    QQmlAndroidOptional<int> m_bottomMargin;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDMARGINLAYOUTPARAMS_P_H
