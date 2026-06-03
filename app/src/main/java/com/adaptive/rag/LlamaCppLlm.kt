package com.adaptive.rag

class LlamaCppLlm {
    companion object {
        init {
            System.loadLibrary("llamma_jni")
        }
    }

    external fun nativeGenerateNextTokenWithEntropy(contextPtr: Long): TokenWithEntropy
    
    fun generateToken(ptr: Long): TokenWithEntropy {
        return nativeGenerateNextTokenWithEntropy(ptr)
    }
}
