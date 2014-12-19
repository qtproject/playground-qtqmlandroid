#include "qtqmlandroidcolor_p.h"
#include <QtGui/qcolor.h>

QT_BEGIN_NAMESPACE

int QtQmlAndroidColor::alpha(int color)
{
    return static_cast<uint>(color) >> 24;
}

int QtQmlAndroidColor::argb(int alpha, int red, int green, int blue)
{
    return (alpha << 24) | (red << 16) | (green << 8) | blue;
}

int QtQmlAndroidColor::blue(int color)
{
    return color & 0xFF;
}

int QtQmlAndroidColor::green(int color)
{
    return (color >> 8) & 0xFF;
}

int QtQmlAndroidColor::red(int color)
{
    return (color >> 16) & 0xFF;
}

int QtQmlAndroidColor::rgb(int red, int green, int blue)
{
    return (0xFF << 24) | (red << 16) | (green << 8) | blue;
}

int QtQmlAndroidColor::name(const QString &name)
{
    return QColor(name).rgba();
}

QObject *QtQmlAndroidColor::provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new QtQmlAndroidColor;
}

QT_END_NAMESPACE
