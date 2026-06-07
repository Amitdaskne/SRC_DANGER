#include <stdint.h>
#include <unistd.h>

/* ===============================
 * COMPILE TIME SEED
 * =============================== */
#define SEED_A (__COUNTER__ + 13)
#define SEED_B (__LINE__ * 7)
#define SEED_C (SEED_A ^ SEED_B)

/* ===============================
 * CONSTANT SIZES (MANDATORY)
 * =============================== */
#define PAD_A_SIZE 32
#define PAD_B_SIZE 48

#define KEY_A ((SEED_C ^ 0xA5) & 0xFF)
#define KEY_B ((SEED_C ^ 0x5A5A) & 0xFFFF)

/* ===============================
 * STRUCTS
 * =============================== */
struct PadA {
    volatile char pad[PAD_A_SIZE];
};

struct PadB {
    volatile int x;
    volatile char pad[PAD_B_SIZE];
};

static __attribute__((used)) PadA g_padA;
static __attribute__((used)) PadB g_padB;

/* ===============================
 * FAKE LOGIC
 * =============================== */
__attribute__((noinline))
int fake_calc(int v) {
    volatile int k = (KEY_A ^ KEY_B) | 1;
    return (v ^ k) ^ k;
}

/* ===============================
 * REAL LOGIC
 * =============================== */
__attribute__((noinline))
int real_calc(int v) {
    volatile int t = getpid() & 1;
    return (v + t) - t;
}

/* ===============================
 * DEAD PATH
 * =============================== */
__attribute__((noinline))
void junk_path() {
    volatile int x = KEY_B;
    if ((x & 0x1337) == 0x1337) {
        volatile int *p = 0;
        (void)p;
    }
}

/* ===============================
 * ENTRY
 * =============================== */
extern "C"
__attribute__((used))
int secure_entry(int input) {

    if ((SEED_C & 1) == 0) {
        junk_path();
    }

    int a = fake_calc(input);
    int b = real_calc(a);

    volatile int m = KEY_A & 1;
    return b ^ m ^ m;
}
