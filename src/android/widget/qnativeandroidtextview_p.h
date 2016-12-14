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

#ifndef QNATIVEANDROIDTEXTVIEW_P_H
#define QNATIVEANDROIDTEXTVIEW_P_H

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

#include <QtQmlAndroid/private/qnativeandroidview_p.h>
#include <QtQmlAndroid/private/qnativeandroidoptional_p.h>
#include <QtGui/qcolor.h>

QT_BEGIN_NAMESPACE

class Q_QMLANDROID_EXPORT QNativeAndroidTextView : public QNativeAndroidView
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(int textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(qreal textSize READ textSize WRITE setTextSize NOTIFY textSizeChanged)
    Q_PROPERTY(QString hint READ hint WRITE setHint NOTIFY hintChanged)
    Q_PROPERTY(bool singleLine READ isSingleLine WRITE setSingleLine NOTIFY singleLineChanged)
    Q_PROPERTY(int inputType READ inputType WRITE setInputType NOTIFY inputTypeChanged)

public:
    explicit QNativeAndroidTextView(QNativeAndroidView *parent = nullptr);

    QString text() const;
    void setText(const QString &text);

    int textColor() const;
    void setTextColor(int color);

    qreal textSize() const;
    void setTextSize(qreal size);

    QString hint() const;
    void setHint(const QString &hint);

    bool isSingleLine() const;
    void setSingleLine(bool singleLine);

    int inputType() const;
    void setInputType(int type);

Q_SIGNALS:
    void textChanged();
    void textColorChanged();
    void textSizeChanged();
    void hintChanged();
    void singleLineChanged();
    void inputTypeChanged();

protected:
    QAndroidJniObject onCreate() override;
    void onInflate(QAndroidJniObject &instance) override;

private:
    QString m_text;
    QString m_hint;
    QNativeAndroidOptional<int> m_textColor;
    QNativeAndroidOptional<qreal> m_textSize;
    bool m_singleLine;
    QNativeAndroidOptional<int> m_inputType;
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDTEXTVIEW_P_H
