#ifndef QQMLANDROIDPROGRESSBAR_P_H
#define QQMLANDROIDPROGRESSBAR_P_H

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

#include <QtQmlAndroid/private/qqmlandroidview_p.h>
#include <QtQmlAndroid/private/qqmlandroidoptional_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidProgressBar : public QQmlAndroidView
{
    Q_OBJECT
    Q_PROPERTY(bool indeterminate READ isIndeterminate WRITE setIndeterminate NOTIFY indeterminateChanged)
    Q_PROPERTY(int progress READ progress WRITE setProgress NOTIFY progressChanged)
    Q_PROPERTY(int secondaryProgress READ secondaryProgress WRITE setSecondaryProgress NOTIFY secondaryProgressChanged)
    Q_PROPERTY(int max READ max WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(Style style READ style WRITE setStyle)
    Q_ENUMS(Style)

public:
    explicit QQmlAndroidProgressBar(QQmlAndroidView *parent = 0);

    bool isIndeterminate() const;
    void setIndeterminate(bool indeterminate);

    int progress() const;
    void setProgress(int progress);

    int secondaryProgress() const;
    void setSecondaryProgress(int progress);

    int max() const;
    void setMax(int max);

    enum Style {
        Medium = 16842871,
        Horizontal = 16842872,
        MediumInverse = 16843399,
        Large = 16842874,
        LargeInverse = 16843401,
        Small = 16842873,
        SmallInverse = 16843400,
        SmallTitle = 16843279
    };

    Style style() const;
    void setStyle(Style style);

Q_SIGNALS:
    void indeterminateChanged();
    void progressChanged();
    void secondaryProgressChanged();
    void maxChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private Q_SLOTS:
    bool updateProgress(int progress);

private:
    int m_max;
    int m_progress;
    int m_secondary;
    bool m_indeterminate;
    QQmlAndroidOptional<Style> m_style;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDPROGRESSBAR_P_H
