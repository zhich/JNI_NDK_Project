//
// Created by zch on 17/2/19.
//

#include "com_zch_atguigu_jniutils_CCallJava.h"

#include <android/log.h>

#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

/**
 * 让C代码调用 java 中CCallJava类的 public int add(int x, int y)
 */
JNIEXPORT void JNICALL Java_com_zch_atguigu_jniutils_CCallJava_callbackAdd
        (JNIEnv *env, jobject jobj) {

    /*反射的方式*/
    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (*env)->FindClass(env, "com/zch/atguigu/jniutils/CCallJava");
    //2.得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID methodID = (*env)->GetMethodID(env, jclazz, "add", "(II)I");
    //3.实例化该类
    // jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject obj = (*env)->AllocObject(env, jclazz);
    //4.调用方法
    //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    jint value = (*env)->CallIntMethod(env, obj, methodID, 1, 99);

    LOGE("value = %d\n", value);
}

/**
 * 让C代码调用
 * public void helloFromJava()
 */
JNIEXPORT void JNICALL Java_com_zch_atguigu_jniutils_CCallJava_callbackHelloFromJava
        (JNIEnv *env, jobject jobj) {

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (*env)->FindClass(env, "com/zch/atguigu/jniutils/CCallJava");
    //2.得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID methodID = (*env)->GetMethodID(env, jclazz, "helloFromJava", "()V");
    //3.实例化该类
    // jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject obj = (*env)->AllocObject(env, jclazz);
    //4.调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env, obj, methodID);
}

/**
 * 让C代码调用void printString(String s)
 */
JNIEXPORT void JNICALL Java_com_zch_atguigu_jniutils_CCallJava_callbackPrintString
        (JNIEnv *env, jobject jobj) {

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (*env)->FindClass(env, "com/zch/atguigu/jniutils/CCallJava");
    //2.得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID methodID = (*env)->GetMethodID(env, jclazz, "printString", "(Ljava/lang/String;)V");
    //3.实例化该类
    // jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject obj = (*env)->AllocObject(env, jclazz);
    //4.调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    jstring jstr = (*env)->NewStringUTF(env, "I am zch.");
    (*env)->CallVoidMethod(env, obj, methodID, jstr);
}

/**
 * 让C代码静态方法 static void sayHello(String s)
 */
JNIEXPORT void JNICALL Java_com_zch_atguigu_jniutils_CCallJava_callbackSayHello
        (JNIEnv *env, jobject jobj) {

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (*env)->FindClass(env, "com/zch/atguigu/jniutils/CCallJava");
    //2.得到方法
    //jmethodID   (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名
    jmethodID methodID = (*env)->GetStaticMethodID(env, jclazz, "sayHello",
                                                   "(Ljava/lang/String;)V");
    //3.实例化该类
    //void        (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
    jstring jst = (*env)->NewStringUTF(env, "I am android1223");
    (*env)->CallStaticVoidMethod(env, jclazz, methodID, jst);
}