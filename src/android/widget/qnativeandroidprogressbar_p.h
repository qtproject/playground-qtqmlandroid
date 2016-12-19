/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt QML Android module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QNATIVEANDROIDPROGRESSBAR_P_H
#define QNATIVEANDROIDPROGRESSBAR_P_H

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

#include <QtNativeAndroid/private/qnativeandroidview_p.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidProgressBarPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidProgressBar : public QNativeAndroidView
{
    Q_OBJECT
    Q_PROPERTY(bool indeterminate READ isIndeterminate WRITE setIndeterminate NOTIFY indeterminateChanged)
    Q_PROPERTY(int progress READ progress WRITE setProgress NOTIFY progressChanged)
    Q_PROPERTY(int secondaryProgress READ secondaryProgress WRITE setSecondaryProgress NOTIFY secondaryProgressChanged)
    Q_PROPERTY(int max READ max WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(Style style READ style WRITE setStyle)
    Q_ENUMS(Style)

public:
    explicit QNativeAndroidProgressBar(QNativeAndroidContext *context = nullptr);

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
    QNativeAndroidProgressBar(QNativeAndroidProgressBarPrivate &dd, QNativeAndroidContext *context = nullptr);

    QAndroidJniObject onCreate() override;
    void onInflate(QAndroidJniObject &instance) override;

private Q_SLOTS:
    bool updateProgress(int progress);

private:
    Q_DISABLE_COPY(QNativeAndroidProgressBar)
    Q_DECLARE_PRIVATE(QNativeAndroidProgressBar)
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDPROGRESSBAR_P_H
