//
// Created by zch on 17/2/19.
//

#include "com_zch_atguigu_jniutils_JavaCallC.h"
#include <string.h>

/**
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char *_JString2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env, "GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) (*env)->CallObjectMethod(env, jstr, mid,
                                                            strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte *ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);
    return rtn;
}

/**
 * jint：返回值
 * Java_全类名_方法名
 * JNIEnv *env：
 */
jint Java_com_zch_atguigu_jniutils_JavaCallC_add(JNIEnv *env, jobject jobj, jint jx, jint jy) {

    int result = jx + jy;
    return result;

}

/**
 *  从java传入字符串，C代码进行拼接
 *
 * @param java : I am from java
 *        c    : add I am from C
 * @return  I am form java add I am from C
 */
JNIEXPORT jstring JNICALL Java_com_zch_atguigu_jniutils_JavaCallC_sayHello
        (JNIEnv *env, jobject jobj, jstring jstr) {

    char *fromJava = _JString2CStr(env, jstr);
    char *fromC = "add I am from C";

    strcat(fromJava, fromC);//拼接函数strcat，把拼接的结果放在第一个参数里面

    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    return (*env)->NewStringUTF(env, fromJava);
}

JNIEXPORT jintArray JNICALL Java_com_zch_atguigu_jniutils_JavaCallC_increaseArrayEles
        (JNIEnv *env, jobject jobj, jintArray jarray) {

    jsize size = (*env)->GetArrayLength(env, jarray);
    jint *array = (*env)->GetIntArrayElements(env, jarray, JNI_FALSE);
    int i;
    for (i = 0; i < size; i++) {
        *(array + i) += 10;
    }

    return jarray;
}

JNIEXPORT jint JNICALL Java_com_zch_atguigu_jniutils_JavaCallC_checkPwd
        (JNIEnv *env, jobject jobj, jstring jstr) {

    char *orign = "123456";//服务器的密码是123456
    char *fromUser = _JString2CStr(env, jstr);

    //函数比较字符串是否相同
    if (strcmp(orign, fromUser) == 0) {
        return 200;
    }
    return 400;
}
