package com.example.testndk2;

public class NativeApi {
    static {
        System.loadLibrary("nativelib");
    }
    public static native String getHello();
}
