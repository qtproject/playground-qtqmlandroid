#ifndef QTANDROIDANIMATION_P_H
#define QTANDROIDANIMATION_P_H

#include "qtandroidcontextual_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidInterpolator;

class QtAndroidAnimation : public QtAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int resource READ resource WRITE setResource NOTIFY resourceChanged)
    Q_PROPERTY(int duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(bool fillAfter READ fillAfter WRITE setFillAfter NOTIFY fillAfterChanged)
    Q_PROPERTY(bool fillBefore READ fillBefore WRITE setFillBefore NOTIFY fillBeforeChanged)
    Q_PROPERTY(bool fillEnabled READ fillEnabled WRITE setFillEnabled NOTIFY fillEnabledChanged)
    Q_PROPERTY(QtAndroidInterpolator *interpolator READ interpolator WRITE setInterpolator NOTIFY interpolatorChanged)
    Q_PROPERTY(int repeatCount READ repeatCount WRITE setRepeatCount NOTIFY repeatCountChanged)
    Q_PROPERTY(RepeatMode repeatMode READ repeatMode WRITE setRepeatMode NOTIFY repeatModeChanged)
    Q_PROPERTY(int startOffset READ startOffset WRITE setStartOffset NOTIFY startOffsetChanged)
    Q_PROPERTY(ZAdjustment zAdjustment READ zAdjustment WRITE setZAdjustment NOTIFY zAdjustmentChanged)
    Q_ENUMS(RepeatMode ZAdjustment Infinity Relation)

public:
    explicit QtAndroidAnimation(QObject *parent = 0);

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

    QtAndroidInterpolator *interpolator() const;
    void setInterpolator(QtAndroidInterpolator *interpolator);

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
    QtAndroidOptional<int> m_resource;
    QtAndroidOptional<int> m_duration;
    QtAndroidOptional<bool> m_fillAfter;
    QtAndroidOptional<bool> m_fillBefore;
    QtAndroidOptional<bool> m_fillEnabled;
    QtAndroidInterpolator *m_interpolator;
    QtAndroidOptional<int> m_repeatCount;
    QtAndroidOptional<RepeatMode> m_repeatMode;
    QtAndroidOptional<int> m_startOffset;
    QtAndroidOptional<ZAdjustment> m_zAdjustment;
};

QT_END_NAMESPACE

#endif // QTANDROIDANIMATION_P_H
