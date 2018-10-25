#include <jni.h>

namespace jni {
class WebService {
public:
    static bool RegisterNativesUtil(JNIEnv *env);

    void nativeLogin(std::string name, std::password);
};
}