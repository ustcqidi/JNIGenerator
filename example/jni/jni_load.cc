#include <jni.h>
#include "base/android/android_jni.h"
#include "WebService.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    base::android::InitVM(vm);
    JNIEnv* env = base::android::AttachCurrentThread();

	jni::WebService::RegisterNativesUtil(env)
	
    return JNI_VERSION_1_6;

}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
}
