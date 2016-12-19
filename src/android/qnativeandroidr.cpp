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

#include "qnativeandroidr_p.h"
#include <QtCore/private/qobject_p.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>
#include <QtQml/qqmlpropertymap.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidRPrivate : public QObjectPrivate
{
public:
    QQmlPropertyMap *anim = nullptr;
    QQmlPropertyMap *animator = nullptr;
    QQmlPropertyMap *array = nullptr;
    QQmlPropertyMap *attr = nullptr;
    QQmlPropertyMap *boolean = nullptr;
    QQmlPropertyMap *color = nullptr;
    QQmlPropertyMap *dimen = nullptr;
    QQmlPropertyMap *drawable = nullptr;
    QQmlPropertyMap *fraction = nullptr;
    QQmlPropertyMap *id = nullptr;
    QQmlPropertyMap *integer = nullptr;
    QQmlPropertyMap *interpolator = nullptr;
    QQmlPropertyMap *layout = nullptr;
    QQmlPropertyMap *menu = nullptr;
    QQmlPropertyMap *mipmap = nullptr;
    QQmlPropertyMap *plurals = nullptr;
    QQmlPropertyMap *raw = nullptr;
    QQmlPropertyMap *string = nullptr;
    QQmlPropertyMap *style = nullptr;
    QQmlPropertyMap *styleable = nullptr;
    QQmlPropertyMap *transition = nullptr;
    QQmlPropertyMap *xml = nullptr;
};

QNativeAndroidR::QNativeAndroidR(QObject *parent)
    : QObject(*(new QNativeAndroidRPrivate), parent)
{
}

static QQmlPropertyMap *getFields(const char *className, QObject *parent)
{
    QQmlPropertyMap *map = new QQmlPropertyMap(parent);

    QAndroidJniEnvironment env;
    QAndroidJniObject anim(className);
    QAndroidJniObject clazz = anim.callObjectMethod("getClass", "()Ljava/lang/Class;");
    QAndroidJniObject fields = clazz.callObjectMethod("getFields", "()[Ljava/lang/reflect/Field;");

    jobjectArray array = fields.object<jobjectArray>();
    int length = env->GetArrayLength(array);
    for (int i = 0; i < length; ++i) {
        QAndroidJniObject field(env->GetObjectArrayElement(array, i));
        QString name = field.callObjectMethod("getName", "()Ljava/lang/String;").toString();
        jint value = field.callMethod<jint>("getInt", "(Ljava/lang/Object;)I", field.object());
        map->insert(name, value);
    }
    return map;
}

QQmlPropertyMap *QNativeAndroidR::anim()
{
    Q_D(QNativeAndroidR);
    if (!d->anim)
        d->anim = getFields("android/R$anim", this);
    return d->anim;
}

QQmlPropertyMap *QNativeAndroidR::animator()
{
    Q_D(QNativeAndroidR);
    if (!d->animator)
        d->animator = getFields("android/R$animator", this);
    return d->animator;
}

QQmlPropertyMap *QNativeAndroidR::array()
{
    Q_D(QNativeAndroidR);
    if (!d->array)
        d->array = getFields("android/R$array", this);
    return d->array;
}

QQmlPropertyMap *QNativeAndroidR::attr()
{
    Q_D(QNativeAndroidR);
    if (!d->attr)
        d->attr = getFields("android/R$attr", this);
    return d->attr;
}

QQmlPropertyMap *QNativeAndroidR::boolean()
{
    Q_D(QNativeAndroidR);
    if (!d->boolean)
        d->boolean = getFields("android/R$boolean", this);
    return d->boolean;
}

QQmlPropertyMap *QNativeAndroidR::color()
{
    Q_D(QNativeAndroidR);
    if (!d->color)
        d->color = getFields("android/R$color", this);
    return d->color;
}

QQmlPropertyMap *QNativeAndroidR::dimen()
{
    Q_D(QNativeAndroidR);
    if (!d->dimen)
        d->dimen = getFields("android/R$dimen", this);
    return d->dimen;
}

QQmlPropertyMap *QNativeAndroidR::drawable()
{
    Q_D(QNativeAndroidR);
    if (!d->drawable)
        d->drawable = getFields("android/R$drawable", this);
    return d->drawable;
}

QQmlPropertyMap *QNativeAndroidR::fraction()
{
    Q_D(QNativeAndroidR);
    if (!d->fraction)
        d->fraction = getFields("android/R$fraction", this);
    return d->fraction;
}

QQmlPropertyMap *QNativeAndroidR::id()
{
    Q_D(QNativeAndroidR);
    if (!d->id)
        d->id = getFields("android/R$id", this);
    return d->id;
}

QQmlPropertyMap *QNativeAndroidR::integer()
{
    Q_D(QNativeAndroidR);
    if (!d->integer)
        d->integer = getFields("android/R$integer", this);
    return d->integer;
}

QQmlPropertyMap *QNativeAndroidR::interpolator()
{
    Q_D(QNativeAndroidR);
    if (!d->interpolator)
        d->interpolator = getFields("android/R$interpolator", this);
    return d->interpolator;
}

QQmlPropertyMap *QNativeAndroidR::layout()
{
    Q_D(QNativeAndroidR);
    if (!d->layout)
        d->layout = getFields("android/R$layout", this);
    return d->layout;
}

QQmlPropertyMap *QNativeAndroidR::menu()
{
    Q_D(QNativeAndroidR);
    if (!d->menu)
        d->menu = getFields("android/R$menu", this);
    return d->menu;
}

QQmlPropertyMap *QNativeAndroidR::mipmap()
{
    Q_D(QNativeAndroidR);
    if (!d->mipmap)
        d->mipmap = getFields("android/R$mipmap", this);
    return d->mipmap;
}

QQmlPropertyMap *QNativeAndroidR::plurals()
{
    Q_D(QNativeAndroidR);
    if (!d->plurals)
        d->plurals = getFields("android/R$plurals", this);
    return d->plurals;
}

QQmlPropertyMap *QNativeAndroidR::raw()
{
    Q_D(QNativeAndroidR);
    if (!d->raw)
        d->raw = getFields("android/R$raw", this);
    return d->raw;
}

QQmlPropertyMap *QNativeAndroidR::string()
{
    Q_D(QNativeAndroidR);
    if (!d->string)
        d->string = getFields("android/R$string", this);
    return d->string;
}

QQmlPropertyMap *QNativeAndroidR::style()
{
    Q_D(QNativeAndroidR);
    if (!d->style)
        d->style = getFields("android/R$style", this);
    return d->style;
}

QQmlPropertyMap *QNativeAndroidR::styleable()
{
    Q_D(QNativeAndroidR);
    if (!d->styleable)
        d->styleable = getFields("android/R$styleable", this);
    return d->styleable;
}

QQmlPropertyMap *QNativeAndroidR::transition()
{
    Q_D(QNativeAndroidR);
    if (!d->transition)
        d->transition = getFields("android/R$transition", this);
    return d->transition;
}

QQmlPropertyMap *QNativeAndroidR::xml()
{
    Q_D(QNativeAndroidR);
    if (!d->xml)
        d->xml = getFields("android/R$xml", this);
    return d->xml;
}

QObject *QNativeAndroidR::provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new QNativeAndroidR;
}

QT_END_NAMESPACE
