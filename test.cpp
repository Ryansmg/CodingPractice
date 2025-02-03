#include <cstdio>
#include <cassert>
#include <sys/stat.h>
#include <sys/mman.h>
#undef fastio
#define fastio mmi_.init()
#define cin mmi_
class MmapInput_ {
    struct stat st{}; char* data = nullptr; bool initCalled = false;
    void skipBlank() {
        assert(data && initCalled);
        while(data && (*data == ' ' || *data == '\n')) data++;
        assert(data);
    }
public:
    void init() {
        fstat(0, &st); initCalled = true;
        data = (char*) mmap(nullptr, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
        assert(data != MAP_FAILED);
    }
    MmapInput_& operator>>(char& v) { skipBlank(); v = *(data++); return *this; }
    MmapInput_& operator>>(long long& v) {
        long long sign = 1; v = 0;
        skipBlank(); if(*data == '-') sign = -1, data++;
        while('0' <= *data && *data <= '9') v = v * 10 + *data - '0', data++;
        v *= sign;
        return *this;
    }
} mmi_;

signed main() {
    fastio;
    long long a, b;
    cin >> a >> b;
    printf("%lld\n", a + b);
}
