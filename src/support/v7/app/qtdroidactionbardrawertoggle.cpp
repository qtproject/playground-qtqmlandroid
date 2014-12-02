#include "qtdroidactionbardrawertoggle_p.h"

QtDroidActionBarDrawerToggle::QtDroidActionBarDrawerToggle(QObject *parent) : QtDroidObject(parent)
{
}

void QtDroidActionBarDrawerToggle::construct(jobject activity, jobject drawer)
{
    QAndroidJniObject toggle("android/support/v7/app/ActionBarDrawerToggle",
                             "(Landroid/app/Activity;Landroid/support/v4/widget/DrawerLayout;II)V",
                             activity, drawer,
                             17039375,  // TODO: R.string.drawer_open
                             17039375); // TODO: R.string.drawer_close
    setInstance(toggle);
}
