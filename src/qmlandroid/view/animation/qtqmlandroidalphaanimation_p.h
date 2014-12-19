#ifndef QTQMLANDROIDALPHAANIMATION_P_H
#define QTQMLANDROIDALPHAANIMATION_P_H

#include "qtqmlandroidanimation_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidAlphaAnimation : public QtQmlAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(qreal fromAlpha READ fromAlpha WRITE setFromAlpha NOTIFY fromAlphaChanged)
    Q_PROPERTY(qreal toAlpha READ toAlpha WRITE setToAlpha NOTIFY toAlphaChanged)

public:
    explicit QtQmlAndroidAlphaAnimation(QObject *parent = 0);

    qreal fromAlpha() const;
    void setFromAlpha(qreal alpha);

    qreal toAlpha() const;
    void setToAlpha(qreal alpha);

Q_SIGNALS:
    void fromAlphaChanged();
    void toAlphaChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    qreal m_fromAlpha;
    qreal m_toAlpha;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDALPHAANIMATION_P_H
