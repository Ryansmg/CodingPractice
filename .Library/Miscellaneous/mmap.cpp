#define USE_MMAP 0

#ifdef LOCAL
#define LOCAL_DEFINED 1
#else
#define LOCAL_DEFINED 0
#endif

#pragma region MMAP
#if USE_MMAP && !LOCAL_DEFINED
#include <sys/stat.h>
#include <sys/mman.h>
#define cin mmi_
namespace std {
    class MmapInput_ {
        struct stat st{}; char* data = nullptr;
        inline void skipBlank() { while(data && (*data == ' ' || *data == '\n')) data++; }
    public:
        MmapInput_() {
            fstat(0, &st);
            data = (char*) mmap(nullptr, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
            assert(data != MAP_FAILED);
        }
        inline char get() { return *(data++); }
        inline MmapInput_& operator>>(char& v) { skipBlank(); v = *(data++); return *this; }
        MmapInput_& operator>>(long long& v) {
            long long sign = 1; v = 0; skipBlank(); if(*data == '-') sign = -1, data++;
            while('0' <= *data && *data <= '9') v = v * 10 + *data - '0', data++;
            v *= sign; return *this;
        }
        MmapInput_& operator>>(__int128& v) {
            long long sign = 1; v = 0; skipBlank(); if(*data == '-') sign = -1, data++;
            while('0' <= *data && *data <= '9') v = v * 10 + *data - '0', data++;
            v *= sign; return *this;
        }
        inline MmapInput_& operator>>(bool& v) { long long tmp; operator>>(tmp); v = tmp; return *this; }
        inline MmapInput_& operator>>(signed& v) { long long t; *this >> t; v = static_cast<signed>(t); return *this; }
        MmapInput_& operator>>(std::string& v) { skipBlank(); v.clear();
            while(*data != ' ' && *data != '\n') v.push_back(*(data++));
            return *this;
        }
        inline void tie(void*) {}
    } mmi_;
}
#endif // USE_MMAP
#pragma endregion