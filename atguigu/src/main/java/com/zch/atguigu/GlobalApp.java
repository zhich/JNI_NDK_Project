package com.zch.atguigu;

import android.app.Application;

import com.zch.androidlib.utils.LogUtils;

/**
 * Created by zch on 17/2/19.
 */

public class GlobalApp extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        LogUtils.setDebug(true);
    }
}
