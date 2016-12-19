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

#ifndef QNATIVEANDROIDRADIOGROUP_P_H
#define QNATIVEANDROIDRADIOGROUP_P_H

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

#include <QtNativeAndroid/private/qnativeandroidlinearlayout_p.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidRadioButton;
class QNativeAndroidRadioGroupPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidRadioGroup : public QNativeAndroidLinearLayout
{
    Q_OBJECT
    Q_PROPERTY(QNativeAndroidRadioButton *checkedButton READ checkedButton WRITE setCheckedButton NOTIFY checkedButtonChanged)

public:
    explicit QNativeAndroidRadioGroup(QNativeAndroidContext *context = nullptr);

    QNativeAndroidRadioButton *checkedButton() const;
    void setCheckedButton(QNativeAndroidRadioButton *button);

public Q_SLOTS:
    void clearCheck();

Q_SIGNALS:
    void checkedButtonChanged();

protected:
    QAndroidJniObject onCreate() override;
    void onInflate(QAndroidJniObject &instance) override;

    static void onRegisterNativeMethods(jobject listener);
    static void onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jint checkedId);

private Q_SLOTS:
    void updateCheckedButtonId(int checkedId);
    bool updateCheckedButton(QNativeAndroidRadioButton *button);

private:
    Q_DISABLE_COPY(QNativeAndroidRadioGroup)
    Q_DECLARE_PRIVATE(QNativeAndroidRadioGroup)
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDRADIOGROUP_P_H
