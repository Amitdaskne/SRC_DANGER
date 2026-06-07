// secure.cpp (FIXED - SAFE + LLVM FRIENDLY)
#include <jni.h>
#include <unistd.h>
#include <ctime>
#include <cstdint>

#define NOINLINE __attribute__((noinline))
#define FORCEINLINE __attribute__((always_inline))

// ===============================
// 1️⃣ RUNTIME ENTROPY
// ===============================
FORCEINLINE unsigned char entropy_key() {
    uintptr_t x;
    return (unsigned char)((uintptr_t)&x ^ getpid() ^ (unsigned)time(nullptr));
}

// ===============================
// 2️⃣ SECURE WIPE
// ===============================
NOINLINE void secure_wipe(void* p, size_t n) {
    volatile unsigned char* v = (volatile unsigned char*)p;
    while (n--) *v++ = 0;
}

// ===============================
// 3️⃣ RUNTIME STRING (SAFE, ONE-TIME DECRYPT)
// ===============================
NOINLINE char* get_secure_string() {
    static unsigned char enc[] = { 0x3A, 0x2F, 0x2C, 0x39 }; // encrypted buffer
    static bool decrypted = false;

    if (!decrypted) {
        unsigned char k = entropy_key();
        for (int i = 0; i < 4; i++)
            enc[i] ^= (k + i);
        decrypted = true;
    }

    return (char*)enc;
}

// ===============================
// 4️⃣ PATTERN-LESS ZERO
// ===============================
NOINLINE int safe_zero() {
    volatile int a = getpid() & 1;
    return a ^ a;
}

// ===============================
// 5️⃣ PROTECTED LOGIC
// ===============================
NOINLINE int protected_logic(int v) {
    int r = (v ^ 0x55);
    asm volatile("" ::: "memory"); // LLVM safe
    return r ^ 0x55;
}

// ===============================
// 6️⃣ JNI ENTRY (PACKAGE FIXED)
// ===============================
extern "C"
JNIEXPORT jint JNICALL
Java_com_kuroyama_nino_Thunder_a(JNIEnv* env, jobject thiz, jint v) {

    int out = protected_logic(v);

    char* s = get_secure_string();

    // FIXED LENGTH WIPE (no strlen)
    secure_wipe(s, 4);

  //  return out ^ safe_zero();
}
