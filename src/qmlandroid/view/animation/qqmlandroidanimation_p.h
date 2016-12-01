#ifndef QQMLANDROIDANIMATION_P_H
#define QQMLANDROIDANIMATION_P_H

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

#include "qqmlandroidcontextual_p.h"
#include "qqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidInterpolator;

class QQmlAndroidAnimation : public QQmlAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int resource READ resource WRITE setResource NOTIFY resourceChanged)
    Q_PROPERTY(int duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(bool fillAfter READ fillAfter WRITE setFillAfter NOTIFY fillAfterChanged)
    Q_PROPERTY(bool fillBefore READ fillBefore WRITE setFillBefore NOTIFY fillBeforeChanged)
    Q_PROPERTY(bool fillEnabled READ fillEnabled WRITE setFillEnabled NOTIFY fillEnabledChanged)
    Q_PROPERTY(QQmlAndroidInterpolator *interpolator READ interpolator WRITE setInterpolator NOTIFY interpolatorChanged)
    Q_PROPERTY(int repeatCount READ repeatCount WRITE setRepeatCount NOTIFY repeatCountChanged)
    Q_PROPERTY(RepeatMode repeatMode READ repeatMode WRITE setRepeatMode NOTIFY repeatModeChanged)
    Q_PROPERTY(int startOffset READ startOffset WRITE setStartOffset NOTIFY startOffsetChanged)
    Q_PROPERTY(ZAdjustment zAdjustment READ zAdjustment WRITE setZAdjustment NOTIFY zAdjustmentChanged)
    Q_ENUMS(RepeatMode ZAdjustment Infinity Relation)

public:
    explicit QQmlAndroidAnimation(QObject *parent = 0);

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

    QQmlAndroidInterpolator *interpolator() const;
    void setInterpolator(QQmlAndroidInterpolator *interpolator);

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
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    void objectChange(ObjectChange change) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateInterpolator();

private:
    QQmlAndroidOptional<int> m_resource;
    QQmlAndroidOptional<int> m_duration;
    QQmlAndroidOptional<bool> m_fillAfter;
    QQmlAndroidOptional<bool> m_fillBefore;
    QQmlAndroidOptional<bool> m_fillEnabled;
    QQmlAndroidInterpolator *m_interpolator;
    QQmlAndroidOptional<int> m_repeatCount;
    QQmlAndroidOptional<RepeatMode> m_repeatMode;
    QQmlAndroidOptional<int> m_startOffset;
    QQmlAndroidOptional<ZAdjustment> m_zAdjustment;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDANIMATION_P_H
