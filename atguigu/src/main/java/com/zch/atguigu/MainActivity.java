package com.zch.atguigu;

import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.os.SystemClock;
import android.widget.Toast;

import com.zch.androidlib.utils.LogUtils;
import com.zch.atguigu.jniutils.CCallJava;
import com.zch.atguigu.jniutils.Hello;
import com.zch.atguigu.jniutils.JavaCallC;
import com.zch.atguigu.jniutils.view.PressureView;

public class MainActivity extends Activity {

    {
        System.loadLibrary("Atguigu");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        final PressureView pressureView = new PressureView(this);
        setContentView(pressureView);

        //testJavaCallC();
        //testCCallJava();

        new Thread() {
            @Override
            public void run() {
                super.run();
                while (true) {
                    SystemClock.sleep(1000);
                    int pressure = Math.abs(getPressure());//0~250
                    pressureView.setPressure(pressure);
                    if (pressure > 220) {//如果压力大于220就要爆炸
                        break;
                    }
                }
            }
        }.start();

        //uninstallLisetner("/data/data/" + getPackageName(), Build.VERSION.SDK_INT);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    /**
     * Java调用C
     */
    private void testJavaCallC() {
        Hello hello = new Hello();
        JavaCallC javaCallC = new JavaCallC();

        String result = hello.sayHello();
        LogUtils.e(result);

        int sum = javaCallC.add(1, 2);
        LogUtils.e(sum + "");

        String str = javaCallC.sayHello("I am from java ");
        LogUtils.e(str);

        int[] array = {1, 2, 3, 4};
        for (int i = 0; i < array.length; i++) {
            LogUtils.e(array[i]);
        }

        LogUtils.e(javaCallC.checkPwd("1234567"));
        LogUtils.e(javaCallC.checkPwd("123456"));
    }

    /**
     * C调用Java
     */
    private void testCCallJava() {
        CCallJava cCallJava = new CCallJava();

        cCallJava.callbackAdd();
        cCallJava.callbackHelloFromJava();
        cCallJava.callbackPrintString();
        cCallJava.callbackSayHello();

        //C调用Java之回调UI
        MainActivity.this.callBackShowToast();
    }

    public void showToast() {
        LogUtils.e("showToast");
        Toast.makeText(MainActivity.this, "showToast", Toast.LENGTH_LONG).show();
    }

    /**
     * 让C代码调用MainActiity里面的showToast
     */
    public native void callBackShowToast();

    /**
     * 获取锅炉压力值
     *
     * @return
     */
    public native int getPressure();

    /**
     * 判断软件是否被卸载
     *
     * @param packName
     * @param sdkVersion
     */
    public native void uninstallLisetner(String packName, int sdkVersion);

}
