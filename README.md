# JNIGenerator
Extracts native methods from a Java file and generates the JNI bindings via python script. You should follow rule to generate corresponding jni interface.

1. Java call Native：the method should starts with **native**, such as
<br>public static native boolean nativeLogin(String username, String password, String server, String roomEmail, String requestID);

2. Native call Java: you should add the annotation **@CalledByNative**, such as
<br>@CalledByNative
<br>public static void sinkResponse(String response) {
<br>}

## Usage
1. Add the files under base folder to you project.
2. Run python jni_generator.py <java_file_path> <jni_header_file_output_path>
3. You will get the JNI binding file
4. Implementation the JNI interface and them to you project.

## Dependency
- python 2.x
