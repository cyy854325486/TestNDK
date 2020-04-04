//
// Created by Administrator on 2020/4/4.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <jni.h>

extern "C" {

JNIEXPORT jstring JNICALL get_hello(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF("hello jni");
}

static JNINativeMethod g_methods[] = {
    { "getHello", "()Ljava/lang/String;", (void*)get_hello}
};

JNIEXPORT int JNICALL JNI_OnLoad(JavaVM *vm,void *reserved) {
  JNIEnv *env;
  if (vm->GetEnv((void **) &env,JNI_VERSION_1_6) != JNI_OK) {
    return JNI_ERR;
  }
  const char* class_path = "com/example/testndk2/NativeApi";
  jclass javaClass = env->FindClass(class_path);
  if (javaClass == NULL){
    return JNI_ERR;
  }

  int method_count = sizeof(g_methods) / sizeof(g_methods[0]);
  if (env->RegisterNatives(javaClass, g_methods, method_count) < 0) {
    return JNI_ERR;
  }

  return JNI_VERSION_1_6;
}

}
