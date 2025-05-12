#include <cstdint>


#if defined(__aarch64__)
#define SYS_READ (63)
#define SYS_WRITE (64)
#elif defined(__x86_64__) || defined(_M_X64)
#define SYS_READ (0)
#define SYS_WRITE (1)
#endif

long syscall(long num, long arg1, long arg2, long arg3) {
#if defined(__aarch64__)
    register long x8 asm("x8") = num;
    register long x0 asm("x0") = arg1;
    register long x1 asm("x1") = arg2;
    register long x2 asm("x2") = arg3;
    asm volatile (
        "svc #0"
        : "+r"(x0)
        : "r"(x1), "r"(x2), "r"(x8)
        : "memory"
    );
    return x0;
#elif defined(__x86_64__) || defined(_M_X64)
    register long rax __asm__("rax") = num;
    register long rdi __asm__("rdi") = arg1;
    register long rsi __asm__("rsi") = arg2;
    register long rdx __asm__("rdx") = arg3;
    __asm__ volatile (
        "syscall"
        : "+r"(rax)
        : "r"(rdi), "r"(rsi), "r"(rdx)
        : "rcx", "r11", "memory"
    );
    return rax;
#else
    #error
#endif
}

int read(int fd, char *buf, int count) {
    return (int)syscall(SYS_READ, (long)fd, (long)buf, (long)count);
}

int write(int fd, const char *buf, int count) {
    return (int)syscall(SYS_WRITE, (long)fd, (long)buf, (long)count);
}

int main() {
    write(1, "Hello World!", 12);
}