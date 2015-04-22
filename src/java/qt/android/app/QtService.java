package qt.android.app;

import android.app.Service;
import android.os.IBinder;
import android.content.Intent;

public class QtService extends Service
{
    public QtService() {
    }

    @Override
    public void onCreate() {
        System.out.println("### QtService.onCreate");
        onCreated(0);
    }

    @Override
    public void onDestroy() {
        System.out.println("### QtService.onDestroy");
        onDestroyed(0);
    }

    @Override
    public IBinder onBind(Intent intent) {
        long instance = intent.getLongExtra("QtService", 0);
        System.out.println("### TODO: QtService.onBind " + instance);
        return null;
    }

    @Override
    public void onRebind(Intent intent) {
        long instance = intent.getLongExtra("QtService", 0);
        System.out.println("### TODO: QtService.onRebind " + instance);
    }

    @Override
    public boolean onUnbind(Intent intent) {
        long instance = intent.getLongExtra("QtService", 0);
        System.out.println("### TODO: QtService.onUnbind " + instance);
        return false;
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        long instance = intent.getLongExtra("QtService", 0);
        System.out.println("### QtService.onStartCommand " + instance);
        return onStartCommand(instance, flags, startId) ? START_STICKY : START_NOT_STICKY;
    }

    @Override
    public void onTaskRemoved(Intent rootIntent) {
        long instance = rootIntent.getLongExtra("QtService", 0);
        System.out.println("### QtService.onTaskRemoved " + instance);
    }

    private static native void onCreated(long instance);
    private static native void onDestroyed(long instance);
    private static native boolean onStartCommand(long instance, int flags, int startId);
}
