#ifndef QQMLANDROIDCOLOR_P_H
#define QQMLANDROIDCOLOR_P_H

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

#include <QtCore/qobject.h>
#include <QtQml/qqmlengine.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidColor : public QObject
{
    Q_OBJECT
    Q_ENUMS(Constants)

public:
    enum Constants {
        BLACK       = 0xFF000000,
        DKGRAY      = 0xFF444444,
        GRAY        = 0xFF888888,
        LTGRAY      = 0xFFCCCCCC,
        WHITE       = 0xFFFFFFFF,
        RED         = 0xFFFF0000,
        GREEN       = 0xFF00FF00,
        BLUE        = 0xFF0000FF,
        YELLOW      = 0xFFFFFF00,
        CYAN        = 0xFF00FFFF,
        MAGENTA     = 0xFFFF00FF,
        TRANSPARENT = 0
    };

    Q_INVOKABLE static int alpha(int color);
    Q_INVOKABLE static int argb(int alpha, int red, int green, int blue);
    Q_INVOKABLE static int blue(int color);
    Q_INVOKABLE static int green(int color);
    Q_INVOKABLE static int red(int color);
    Q_INVOKABLE static int rgb(int red, int green, int blue);
    Q_INVOKABLE static int name(const QString &name);

    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCOLOR_P_H
