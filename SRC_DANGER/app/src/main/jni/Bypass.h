#include <jni.h>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <unwind.h>
#include <dlfcn.h>
#include <libgen.h>
#include <stdint.h>
#include <cstring>
#include <functional>


#include <sys/stat.h>
#include <fcntl.h>
#include <android/log.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include "Main/Tools.h" 
#include "Main/Logger.h"
#include "Main/oxorany.h"
//#include "Main/obfuscate.h"
#include "Main/Utils.h"
#include "Main/KittyMemory/MemoryPatch.h"
#define targetLibName oxorany("libUE4.so")

#define targetLibName oxorany("libTBlueData.so")
#define targetLibName oxorany("libhdmpve.so")
#define targetLibName oxorany("libAntsVoice.so")
#define targetLibName oxorany("libanogs.so")
#define DEV_CREDIT "@DangerIndiaSrc"
#include "Main/Macros.h"
#define ARM64_SYSREG(reg0, reg1, reg2, reg3, op) (((reg0) & 0x1F) | (((reg1) & 0x1F) << 5) | (((reg2) & 0x7) << 10) | (((reg3) & 0xF) << 16) | (((op) & 0x7) << 20))

#ifdef __aarch64__
uint64_t _ReadStatusReg(uint64_t reg) {
    return 0;
}
#endif


char *Offset;
#define ret_zero
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD __int64
#define _OWORD uint64_t
#define _QWORD uint64_t
#define _BOOL8 uint64_t

#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
#define j_j__free
#define log_suspicious_activity
#define apply_cheat_penalty
#define check_memory_integrity
#define __OFSUB__
#define AnoSDKIoctlOld_0
#define HIWORD
#define JUMPOUT
#define byte_4
#include <random>
#define _ReadStatusReg
#define BYTE5
#define BYTE4
#define HIBYTE
#define BYTE6
#define sub_95A8204
#define IsMemoryReadable
#define BYTE1
#define BYTE3
#define MEMORY_BASIC_INFORMATION mbi
#define BYTE2
#define ARM64_SYSREG
#define _WriteStatusReg
#define fn1

#define targetLibName OBFUSCATE("libhdmpve.so")
#define targetLibName OBFUSCATE("libAntsVoice.so")
#define targetLibName OBFUSCATE("libanogs.so")
#define targetLibName OBFUSCATE("libUE4.so")
#define targetLibName OBFUSCATE("libTBlueData.so")
#define targetLibName OBFUSCATE("libanogs.so")
#define Max_Size 0x170
#define Offset_Value 0x61
typedef long long int64; 
typedef short int16;     
uintptr_t libaviwaBase = 0;
uintptr_t libaviwaSize = 0;
uintptr_t libaviwaAlloc = 0;
uintptr_t libanogsBase = 0;
uintptr_t UE4Base = 0;
uintptr_t libanortBase = 0;
uintptr_t libcBase = 0;
uintptr_t libEGLBase = 0;
uintptr_t libanogsAlloc = 0;
uintptr_t libUE4Alloc = 0;
uintptr_t libUE4Base = 0;
uintptr_t libEGLAlloc = 0;
uintptr_t libanogsSize = 0;// 0x3856E5  3.6.0
uintptr_t libUE4Size = 0;// 0x7CF8F10  3.6.0
uintptr_t NewBase = 0;

typedef unsigned char BYTE;
#define targetLibName OBFUSCATE("libanogs.so")

constexpr const char DefineStr1[] = "00 00 80 D2 C0 03 5F D6"; // MOV X0, #0; RET
constexpr const char RET[] = "C0 03 5F D6";              // RET
constexpr const char NOP[] = "1F 20 03 D5";              // NOP
constexpr const char RET1[] = "01 00 80 D2 C0 03 5F D6"; // MOV X0, #1; RET

size_t getLibrarySize(const char *libraryName)
{
    FILE *mapsFile = fopen(oxorany("/proc/self/maps"), "r");
    if (mapsFile == nullptr)
    {
        return 0;
    }

    char line[256];
    size_t size = 0;
    uintptr_t startAddr = 0, endAddr = 0;
    while (fgets(line, sizeof(line), mapsFile))
    {
        if (strstr(line, libraryName))
        {
            sscanf(line, oxorany("%lx-%lx"), &startAddr, &endAddr);
            size = endAddr - startAddr;
            break;
        }
    }

    fclose(mapsFile);
    return size;
}

static unsigned int rs;
__attribute__((constructor)) static void init_hook(){
    rs = (unsigned)time(NULL) ^ (unsigned)getpid();
}

//define constants (must Important).

//add Hook Function 




void * anogs_thread(void *) {
    LOGI(OBFUSCATE("@DangerIndiaSrc ...."));
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));
#if defined(__aarch64__)
//add your Safe Bypass

 // Compile for arm64 lib only


#endif
   
return NULL;

}

__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, anogs_thread, NULL);
}

