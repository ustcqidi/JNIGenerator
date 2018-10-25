package com.webservice.jni;

public class WebServiceJNI {
	
	public static native boolean nativeLogin(String username, String password);
	
	@CalledByNative
	public static void loginCallback(String response) {
	}

}
