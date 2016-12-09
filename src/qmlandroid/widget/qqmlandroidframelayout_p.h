#ifndef QQMLANDROIDFRAMELAYOUT_P_H
#define QQMLANDROIDFRAMELAYOUT_P_H

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

#include <QtQmlAndroid/private/qqmlandroidviewgroup_p.h>
#include <QtQmlAndroid/private/qqmlandroidframelayoutparams_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidFrameLayout : public QQmlAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QQmlAndroidFrameLayout(QQmlAndroidView *parent = 0);

    static QQmlAndroidFrameLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QQmlAndroidFrameLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QQMLANDROIDFRAMELAYOUT_P_H
