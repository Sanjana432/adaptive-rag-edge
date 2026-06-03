package com.adaptive.rag

import android.app.Activity
import android.os.Bundle
import android.widget.TextView

class MainActivity : Activity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        
        val llm = LlamaCppLlm()
        val result = llm.generateToken(0L) // Passing a dummy context pointer
        
        val textView = TextView(this).apply {
            text = "C++ Output:\nToken: ${result.token}\nEntropy: ${result.entropy}"
            textSize = 20f
            setPadding(50, 50, 50, 50)
        }
        
        setContentView(textView)
    }
}
