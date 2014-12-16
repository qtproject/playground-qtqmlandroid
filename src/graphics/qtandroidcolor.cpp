#include "qtandroidcolor_p.h"
#include <QtGui/qcolor.h>

int QtAndroidColor::alpha(int color)
{
    return static_cast<uint>(color) >> 24;
}

int QtAndroidColor::argb(int alpha, int red, int green, int blue)
{
    return (alpha << 24) | (red << 16) | (green << 8) | blue;
}

int QtAndroidColor::blue(int color)
{
    return color & 0xFF;
}

int QtAndroidColor::green(int color)
{
    return (color >> 8) & 0xFF;
}

int QtAndroidColor::red(int color)
{
    return (color >> 16) & 0xFF;
}

int QtAndroidColor::rgb(int red, int green, int blue)
{
    return (0xFF << 24) | (red << 16) | (green << 8) | blue;
}

int QtAndroidColor::name(const QString &name)
{
    return QColor(name).rgba();
}

QObject *QtAndroidColor::provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new QtAndroidColor;
}
