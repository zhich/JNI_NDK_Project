//
// Created by zch on 17/2/19.
//

#include<stdio.h>
#include<stdlib.h>
#include <jni.h>

/**
 * jstring ：返回值
 * Java_全类名_方法名
 * JNIEnv* env:里面有很多方法
 * jobject jobj：谁调用了这个方法就是谁的实例，当前就是HelloJNI.this
 */
jstring Java_com_zch_atguigu_jniutils_Hello_sayHello(JNIEnv *env, jobject jobj) {

    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    char *text = "I am from c.";
    return (*env)->NewStringUTF(env, text);

}