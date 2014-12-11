#ifndef QTDROIDPROGRESSBAR_P_H
#define QTDROIDPROGRESSBAR_P_H

#include "qtdroidview_p.h"
#include "qtdroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidProgressBar : public QtAndroidView
{
    Q_OBJECT
    Q_PROPERTY(bool indeterminate READ isIndeterminate WRITE setIndeterminate NOTIFY indeterminateChanged)
    Q_PROPERTY(int progress READ progress WRITE setProgress NOTIFY progressChanged)
    Q_PROPERTY(int max READ max WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(Style style READ style WRITE setStyle)
    Q_ENUMS(Style)

public:
    explicit QtAndroidProgressBar(QtAndroidView *parent = 0);

    bool isIndeterminate() const;
    void setIndeterminate(bool indeterminate);

    int progress() const;
    void setProgress(int progress);

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
    void maxChanged();

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

private Q_SLOTS:
    bool updateProgress(int progress);

private:
    int m_progress;
    bool m_indeterminate;
    QtAndroidOptional<int> m_max;
    QtAndroidOptional<Style> m_style;
};

QT_END_NAMESPACE

#endif // QTDROIDPROGRESSBAR_P_H
