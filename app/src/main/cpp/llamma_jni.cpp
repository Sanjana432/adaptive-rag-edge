#include <jni.h>
#include <cmath>
#include <string>

extern "C"
JNIEXPORT jobject JNICALL
Java_com_adaptive_rag_LlamaCppLlm_nativeGenerateNextTokenWithEntropy(
        JNIEnv *env, jobject thiz, jlong context_ptr) {

    // Simulated vocabulary and logits for our Proof of Concept
    int n_vocab = 4;
    float logits[] = {1.2f, -0.5f, 0.8f, 2.1f}; 

    // 1. Softmax normalization for numerical stability
    float max_logit = -INFINITY;
    for (int i = 0; i < n_vocab; i++) {
        if (logits[i] > max_logit) max_logit = logits[i];
    }

    float sum_exp = 0.0f;
    for (int i = 0; i < n_vocab; i++) {
        sum_exp += exp(logits[i] - max_logit);
    }

    // 2. Compute Shannon Entropy: H = -Sum(p * log2(p))
    float entropy = 0.0f;
    for (int i = 0; i < n_vocab; i++) {
        float p = exp(logits[i] - max_logit) / sum_exp;
        if (p > 1e-10f) {
            entropy -= p * log2(p);
        }
    }

    // 3. Simulated token string
    std::string token_str = "Adaptive_RAG_Token";

    // 4. Construct the Kotlin Object from C++
    jclass tokenClass = env->FindClass("com/adaptive/rag/TokenWithEntropy");
    jmethodID constructor = env->GetMethodID(tokenClass, "<init>", "(Ljava/lang/String;F)V");
    jstring jTokenStr = env->NewStringUTF(token_str.c_str());

    return env->NewObject(tokenClass, constructor, jTokenStr, entropy);
}
