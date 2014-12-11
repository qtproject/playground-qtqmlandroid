#ifndef QTDROIDCOLOR_P_H
#define QTDROIDCOLOR_P_H

#include <QtCore/qobject.h>
#include <QtQml/qqmlengine.h>

QT_BEGIN_NAMESPACE

class QtAndroidColor : public QObject
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

    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);
};

QT_END_NAMESPACE

#endif // QTDROIDCOLOR_P_H
