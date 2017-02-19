package com.zch.atguigu.jniutils;

import android.util.Log;

import com.zch.androidlib.utils.LogUtils;

/**
 * C调用Java代码
 * Created by zch on 17/2/19.
 */

public class CCallJava {

    {
        System.loadLibrary("Atguigu");
    }

    /**
     * 当执行这个方法的时候，让C代码调用
     * public int add(int x, int y)
     */
    public native void callbackAdd();

    /**
     * 当执行这个方法的时候，让C代码调用
     * public void helloFromJava()
     */
    public native void callbackHelloFromJava();


    /**
     * 当执行这个方法的时候，让C代码调用void printString(String s)
     */
    public native void callbackPrintString();

    /**
     * 当执行这个方法的时候，让C代码静态方法 static void sayHello(String s)
     */
    public native void callbackSayHello();


    public int add(int x, int y) {
        LogUtils.e("add() x=" + x + " y=" + y);
        return x + y;
    }

    public void helloFromJava() {
        LogUtils.e("helloFromJava()");
    }

    public void printString(String s) {
        LogUtils.e("C中输入的：" + s);
    }

    public static void sayHello(String s) {
        LogUtils.e("我是java代码中的JNI."
                + "java中的sayHello(String s)静态方法，我被C调用了:" + s);
    }

}
