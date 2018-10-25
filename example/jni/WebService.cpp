#include "WebService.h"
#include "WebService_jni.h"

jboolean Login(JNIEnv* env, jclass jcaller,
    jstring username,
    jstring password) {
        // call WebService::nativeLogin()
        return false;
    }

namespace jni {

bool WebService::RegisterNativesUtil(JNIEnv *) {
    return RegisterNativesImpl(env);
}

void WebService::nativeLogin(std::string name, std::password) {
    // native implementation
    // ...

    // callback to java
    JNIEnv *env = base::android::AttachCurrentThread();
    const char* resp = "response from backend";
    
    jstring jresp = env->NewStringUTF(resp);

    Java_WebServiceJNI_loginCallback(env, jresp);

    env->ReleaseStringUTFChars(jresp, resp);
}

}