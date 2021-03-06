
// This file is autogenerated by
//     D:\Workspace\JNIGenerator\jni_generator.py
// For
//     com/webservice/jni/WebServiceJNI

#ifndef com_webservice_jni_WebServiceJNI_JNI
#define com_webservice_jni_WebServiceJNI_JNI

#include <jni.h>

#include "base/android/android_jni.h"

// Step 1: forward declarations.
namespace {
const char kWebServiceJNIClassPath[] = "com/webservice/jni/WebServiceJNI";
// Leaking this jclass as we cannot use LazyInstance from some threads.
jclass g_WebServiceJNI_clazz = NULL;
#define WebServiceJNI_clazz(env) g_WebServiceJNI_clazz

}  // namespace

static jboolean Login(JNIEnv* env, jclass jcaller,
    jstring username,
    jstring password);

// Step 2: method stubs.

static intptr_t g_WebServiceJNI_loginCallback = 0;
static void Java_WebServiceJNI_loginCallback(JNIEnv* env, jstring response) {
  /* Must call RegisterNativesImpl()  */
  //CHECK_CLAZZ(env, WebServiceJNI_clazz(env),
  //    WebServiceJNI_clazz(env));
  jmethodID method_id =
      base::android::GetMethod(
      env, WebServiceJNI_clazz(env),
      base::android::STATIC_METHOD,
      "loginCallback",

"("
"Ljava/lang/String;"
")"
"V",
      &g_WebServiceJNI_loginCallback);

     env->CallStaticVoidMethod(WebServiceJNI_clazz(env),
          method_id, response);
  base::android::CheckException(env);

}

// Step 3: RegisterNatives.

static const JNINativeMethod kMethodsWebServiceJNI[] = {
    { "nativeLogin",
"("
"Ljava/lang/String;"
"Ljava/lang/String;"
")"
"Z", reinterpret_cast<void*>(Login) },
};

static bool RegisterNativesImpl(JNIEnv* env) {

  g_WebServiceJNI_clazz = reinterpret_cast<jclass>(env->NewGlobalRef(
      base::android::GetClass(env, kWebServiceJNIClassPath).Get()));

  const int kMethodsWebServiceJNISize =
      sizeof(kMethodsWebServiceJNI)/sizeof(kMethodsWebServiceJNI[0]);

  if (env->RegisterNatives(WebServiceJNI_clazz(env),
                           kMethodsWebServiceJNI,
                           kMethodsWebServiceJNISize) < 0) {
    //jni_generator::HandleRegistrationError(
    //    env, WebServiceJNI_clazz(env), __FILE__);
    return false;
  }

  return true;
}

#endif  // com_webservice_jni_WebServiceJNI_JNI
