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

#ifndef QNATIVEANDROIDANIMATION_P_H
#define QNATIVEANDROIDANIMATION_P_H

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

#include <QtNativeAndroid/private/qnativeandroidcontextual_p.h>
#include <QtNativeAndroid/private/qnativeandroidoptional_p.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidInterpolator;
class QNativeAndroidAnimationPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidAnimation : public QNativeAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int resource READ resource WRITE setResource NOTIFY resourceChanged)
    Q_PROPERTY(int duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(bool fillAfter READ fillAfter WRITE setFillAfter NOTIFY fillAfterChanged)
    Q_PROPERTY(bool fillBefore READ fillBefore WRITE setFillBefore NOTIFY fillBeforeChanged)
    Q_PROPERTY(bool fillEnabled READ fillEnabled WRITE setFillEnabled NOTIFY fillEnabledChanged)
    Q_PROPERTY(QNativeAndroidInterpolator *interpolator READ interpolator WRITE setInterpolator NOTIFY interpolatorChanged)
    Q_PROPERTY(int repeatCount READ repeatCount WRITE setRepeatCount NOTIFY repeatCountChanged)
    Q_PROPERTY(RepeatMode repeatMode READ repeatMode WRITE setRepeatMode NOTIFY repeatModeChanged)
    Q_PROPERTY(int startOffset READ startOffset WRITE setStartOffset NOTIFY startOffsetChanged)
    Q_PROPERTY(ZAdjustment zAdjustment READ zAdjustment WRITE setZAdjustment NOTIFY zAdjustmentChanged)
    Q_ENUMS(RepeatMode ZAdjustment Infinity Relation)

public:
    explicit QNativeAndroidAnimation(QObject *parent = nullptr);

    int resource() const;
    void setResource(int resource);

    enum Relation {
        ABSOLUTE = 0,
        RELATIVE_TO_SELF = 1,
        RELATIVE_TO_PARENT = 2
    };

    enum Infinity {
        INFINITE = -1
    };

    int duration() const;
    void setDuration(int duration);

    bool fillAfter() const;
    void setFillAfter(bool fill);

    bool fillBefore() const;
    void setFillBefore(bool fill);

    bool fillEnabled() const;
    void setFillEnabled(bool enabled);

    QNativeAndroidInterpolator *interpolator() const;
    void setInterpolator(QNativeAndroidInterpolator *interpolator);

    int repeatCount() const;
    void setRepeatCount(int count);

    enum RepeatMode {
        RESTART = 1,
        REVERSE = 2
    };

    RepeatMode repeatMode() const;
    void setRepeatMode(RepeatMode mode);

    int startOffset() const;
    void setStartOffset(int offset);

    enum ZAdjustment {
        ZORDER_NORMAL = 0,
        ZORDER_TOP = 1,
        ZORDER_BOTTOM = -1
    };

    ZAdjustment zAdjustment() const;
    void setZAdjustment(ZAdjustment adjustment);

public Q_SLOTS:
    void cancel();
    void start();
    void startNow();

Q_SIGNALS:
    void resourceChanged();
    void durationChanged();
    void fillAfterChanged();
    void fillBeforeChanged();
    void fillEnabledChanged();
    void interpolatorChanged();
    void repeatCountChanged();
    void repeatModeChanged();
    void startOffsetChanged();
    void zAdjustmentChanged();

protected:
    QNativeAndroidAnimation(QNativeAndroidAnimationPrivate &dd, QObject *parent = nullptr);

    QAndroidJniObject onCreate() override;
    void onInflate(QAndroidJniObject &instance) override;

    void objectChange(ObjectChange change) override;

private Q_SLOTS:
    void updateInterpolator();

private:
    Q_DISABLE_COPY(QNativeAndroidAnimation)
    Q_DECLARE_PRIVATE(QNativeAndroidAnimation)
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDANIMATION_P_H
