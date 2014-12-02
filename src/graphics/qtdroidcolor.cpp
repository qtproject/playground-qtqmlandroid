#include "qtdroidcolor_p.h"

int QtDroidColor::alpha(int color)
{
    return static_cast<uint>(color) >> 24;
}

int QtDroidColor::argb(int alpha, int red, int green, int blue)
{
    return (alpha << 24) | (red << 16) | (green << 8) | blue;
}

int QtDroidColor::blue(int color)
{
    return color & 0xFF;
}

int QtDroidColor::green(int color)
{
    return (color >> 8) & 0xFF;
}

int QtDroidColor::red(int color)
{
    return (color >> 16) & 0xFF;
}

int QtDroidColor::rgb(int red, int green, int blue)
{
    return (0xFF << 24) | (red << 16) | (green << 8) | blue;
}

QObject *QtDroidColor::provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new QtDroidColor();
}
