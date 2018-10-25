#include "base/android/android_jni.h"
#include "base/android/scoped_java_ref.h"

namespace base {
namespace android {

JavaRef::JavaRef() : obj_(NULL) {}

JavaRef::JavaRef(JNIEnv* env, jobject obj) : obj_(obj) { }

void JavaRef::ResetNewLocalRef(JNIEnv* env, jobject obj) {
    if (!env) {
        env = AttachCurrentThread();
    }
    if (obj) {
        obj = env->NewLocalRef(obj);
    }

    if (obj_)
        env->DeleteLocalRef(obj_);
    obj_ = obj;
}

void JavaRef::ReleaseLocalRef(JNIEnv* env) {
    if (!env) {
        env = AttachCurrentThread();
    }
    env->DeleteLocalRef(obj_);
}

void JavaRef::ResetNewGlobalRef(JNIEnv* env, jobject obj) {
    if (!env) {
        env = AttachCurrentThread();
    }
    if (obj)
        obj = env->NewGlobalRef(obj);
    if (obj_)
        env->DeleteGlobalRef(obj_);
    obj_ = obj;
}

void JavaRef::ReleaseGlobalRef(JNIEnv* env) {
    if (obj_ == NULL){
        return;
    }
    if (!env) {
        env = AttachCurrentThread();
    }
    env->DeleteGlobalRef(obj_);
}

jobject JavaRef::Release() {
    jobject obj = obj_;
    obj_ = NULL;
    return obj;
}
}  // namespace android
}  // namespace base
