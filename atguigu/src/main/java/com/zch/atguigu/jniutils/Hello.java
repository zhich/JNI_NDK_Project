package com.zch.atguigu.jniutils;

/**
 * Java调用对应的C代码
 * Created by zch on 17/2/19.
 */

public class Hello {

    {
        System.loadLibrary("Atguigu");
    }

    /**
     * 定义native方法
     * 调用C代码对应的方法
     *
     * @return
     */
    public native String sayHello();

}
