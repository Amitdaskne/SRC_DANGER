package com.t

import android.app.Application
import android.content.Context
import android.widget.Toast

class Demo:Application()

{

    override fun onCreate() {
        super.onCreate()
        Toast.makeText(applicationContext,"Sucess",Toast.LENGTH_LONG).show()

        val customApplicationClassName = "androidx.multidex.MultiDexApplication"
        try {
            val applicationClass = Class.forName(customApplicationClassName)
            val attachBaseContextMethod = applicationClass.getMethod("attachBaseContext")
            val baseContext = applicationContext
            attachBaseContextMethod.invoke(null, baseContext)
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    override fun getApplicationContext(): Context {
        return super.getApplicationContext()
    }

}