//
// Created by zch on 2017/2/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "Common.h"
#include <unistd.h>
#include <android/log.h>

#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


/**
 得到锅炉的压力值
 0~250之间
*/
int getPressure() {
    int pressure = rand() % 250;
    return pressure;
}

/**
* 从锅炉感应器中得到锅炉压力值
*/
jint Java_com_zch_atguigu_MainActivity_getPressure(JNIEnv *env, jobject instance) {

    // TODO
    int pressure = getPressure();
    return pressure;
}

void Java_com_zch_atguigu_MainActivity_uninstallLisetner(JNIEnv *env, jobject instance,
                                                         jstring packName_, jint sdkVersion) {
    // const char *packName = (*env)->GetStringUTFChars(env, packName_, 0);

    // TODO
    //  (*env)->ReleaseStringUTFChars(env, packName_, packName);

    //返回三个值，大于0，父进程的id,等于0就是子进程的id,负数就是出错了
    int code = fork();
    if (code == 0) {
        //判断软件是否被卸载
        LOGE("child==%d\n", code);
        int flag = 1;
        while (flag) {
            sleep(1);//睡眠1s
            //FILE	*fopen(const char *, const char *);
            char *packName = _JString2CStr(env, packName);
            FILE *file = fopen("/data/data/com.zch.atguigu", "r");
            if (file == NULL) {
                //应用对应的包名文件夹不存在, 说明已经被卸载了
//                 if(sdkVersion <17){
//                     execlp("am", "am", "start", "-a", "android.intent.action.VIEW", "-d", "http://www.baidu.com", NULL);
//
//                 }else{
//                     execlp("am", "am", "start", "--user", "0", "-a","android.intent.action.VIEW", "-d","http://www.baidu.com", (char*) NULL);
//                 }
                execlp("am", "am", "start", "--user", "0", "-a", "android.intent.action.VIEW", "-d",
                       "http://www.baidu.com/", (char *) NULL);

                execlp("am", "am", "start", "-a", "android.intent.action.VIEW", "-d",
                       "http://www.baidu.com/", NULL);

                flag = 0;//停止循环
            }
        }
    } else if (code > 0) {
        //父进程
        LOGE("father==%d\n", code);
    } else {
        //出错了
        LOGE("error==%d\n", code);
    }
}