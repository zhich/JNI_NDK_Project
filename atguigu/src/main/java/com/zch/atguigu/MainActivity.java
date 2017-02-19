package com.zch.atguigu;

import android.app.Activity;
import android.os.Bundle;

import com.zch.androidlib.utils.LogUtils;
import com.zch.atguigu.jniutils.CCallJava;
import com.zch.atguigu.jniutils.Hello;
import com.zch.atguigu.jniutils.JavaCallC;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //testJavaCallC();
        testCCallJava();
    }

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

    private void testCCallJava() {
        CCallJava cCallJava = new CCallJava();

        cCallJava.callbackAdd();
        cCallJava.callbackHelloFromJava();
        cCallJava.callbackPrintString();
        cCallJava.callbackSayHello();
    }

}
