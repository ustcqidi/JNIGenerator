#ifndef BASE_ANDROID_SCOPED_JAVA_REF_H_
#define BASE_ANDROID_SCOPED_JAVA_REF_H_

#include <jni.h>

namespace base {
namespace android {
class JavaRef {
 public:
    JavaRef();

    JavaRef(JNIEnv* env, jobject obj);

    ~JavaRef() {}

    void ResetNewLocalRef(JNIEnv* env, jobject obj);

    void ReleaseLocalRef(JNIEnv* env);

    void ResetNewGlobalRef(JNIEnv* env, jobject obj);

    void ReleaseGlobalRef(JNIEnv* env);

    jobject Release();

    jobject Get() const { return obj_;}

    bool IsNull() const { return obj_ == NULL; }

 protected:
    jobject obj_;
};

template <typename T>
class ScopedLocalJavaRef : public JavaRef {
 public:
    ScopedLocalJavaRef() : env_(NULL) {}

    ScopedLocalJavaRef(JNIEnv* env, T obj) : env_(env), JavaRef(env, obj) {
    }

    ScopedLocalJavaRef(const ScopedLocalJavaRef<T>& other) : env_(other.env_) {
        Reset(env_, other.Get());
    }

    void operator=(const ScopedLocalJavaRef<T>& other) {
        env_ = other.env_;
        Reset(env_, other.Get());
    }

    ~ScopedLocalJavaRef() {
        ReleaseLocalRef(env_);
    }

    void Reset(JNIEnv* env, jobject obj) {
        ResetNewLocalRef(env, obj);
    }

    T Get() const { return (T) obj_;}

    T Release() { return (T) JavaRef::Release();}

 private:
    JNIEnv* env_;
};

template <typename T>
class ScopedGlobalJavaRef : public JavaRef {
 public:
    ScopedGlobalJavaRef() {}

    ScopedGlobalJavaRef(JNIEnv* env, T obj) {
        Reset(env, obj);
    }

    ScopedGlobalJavaRef(const ScopedGlobalJavaRef<T>& other) {
        Reset(NULL, other.Get());
    }

    ScopedGlobalJavaRef(
        const ScopedLocalJavaRef<T>& other) {
        Reset(NULL, other.Get());
    }

    ~ScopedGlobalJavaRef() {
        ReleaseGlobalRef(NULL);
    }

    void operator=(const ScopedGlobalJavaRef<T>& other) {
        Reset(NULL, other.Get());
    }

    void Reset(JNIEnv* env, const ScopedLocalJavaRef<T>& other) {
        ResetNewGlobalRef(env, other.Get());
    }

    void Reset(JNIEnv* env, jobject obj) {
        ResetNewGlobalRef(env, obj);
    }

    T Get() const { return (T) obj_;}
};

}  // namespace android
}  // namespace base


#endif  // BASE_ANDROID_SCOPED_JAVA_REF_H_
