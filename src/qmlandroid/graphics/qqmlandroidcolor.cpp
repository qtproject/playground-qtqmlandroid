#include "qqmlandroidcolor_p.h"
#include <QtGui/qcolor.h>

QT_BEGIN_NAMESPACE

int QQmlAndroidColor::alpha(int color)
{
    return static_cast<uint>(color) >> 24;
}

int QQmlAndroidColor::argb(int alpha, int red, int green, int blue)
{
    return (alpha << 24) | (red << 16) | (green << 8) | blue;
}

int QQmlAndroidColor::blue(int color)
{
    return color & 0xFF;
}

int QQmlAndroidColor::green(int color)
{
    return (color >> 8) & 0xFF;
}

int QQmlAndroidColor::red(int color)
{
    return (color >> 16) & 0xFF;
}

int QQmlAndroidColor::rgb(int red, int green, int blue)
{
    return (0xFF << 24) | (red << 16) | (green << 8) | blue;
}

int QQmlAndroidColor::name(const QString &name)
{
    return QColor(name).rgba();
}

QObject *QQmlAndroidColor::provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new QQmlAndroidColor;
}

QT_END_NAMESPACE
