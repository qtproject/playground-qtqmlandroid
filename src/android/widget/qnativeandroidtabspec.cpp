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

#include "qnativeandroidtabspec_p.h"
#include "qnativeandroidtabhost_p.h"
#include "qnativeandroidview_p.h"
#include "qtnativeandroidfunctions_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtCore/private/qobject_p.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidTabSpecPrivate : public QObjectPrivate
{
public:
    QString label;
};

QNativeAndroidTabSpec::QNativeAndroidTabSpec(QNativeAndroidView *view)
    : QObject(*(new QNativeAndroidTabSpecPrivate), view)
{
    QNativeAndroidView *parent = qobject_cast<QNativeAndroidView *>(view->parent());
    if (parent)
        parent->setIdentifier(16908305); // TODO: android.R.id.tabcontent
}

QNativeAndroidTabSpec *QNativeAndroidTabSpec::qmlAttachedProperties(QObject *object)
{
    QNativeAndroidView *view = qobject_cast<QNativeAndroidView*>(object);
    if (view)
        return new QNativeAndroidTabSpec(view);
    return 0;
}

QString QNativeAndroidTabSpec::label() const
{
    Q_D(const QNativeAndroidTabSpec);
    return d->label;
}

void QNativeAndroidTabSpec::setLabel(const QString &label)
{
    Q_D(QNativeAndroidTabSpec);
    if (d->label != label) {
        d->label = label;
        // TODO: invalidate
        emit labelChanged();
    }
}

void QNativeAndroidTabSpec::setup(QAndroidJniObject &host, int index)
{
    Q_D(QNativeAndroidTabSpec);
    int id = -1;
    QNativeAndroidView *content = qobject_cast<QNativeAndroidView *>(parent());
    if (content)
        id = content->identifier();

    QtNativeAndroid::callFunction([=]() {
        QAndroidJniObject spec = host.callObjectMethod("newTabSpec",
                                                       "(Ljava/lang/String;)Landroid/widget/TabHost$TabSpec;",
                                                       QAndroidJniObject::fromString(QString::number(index)).object());

        spec.callObjectMethod("setIndicator",
                             "(Ljava/lang/CharSequence;)Landroid/widget/TabHost$TabSpec;",
                             QAndroidJniObject::fromString(d->label).object());

        if (id != -1) {
            spec.callObjectMethod("setContent",
                                  "(I)Landroid/widget/TabHost$TabSpec;",
                                  id);
        }

        host.callMethod<void>("addTab", "(Landroid/widget/TabHost$TabSpec;)V", spec.object());
    });
}

QT_END_NAMESPACE
