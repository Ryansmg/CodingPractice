#define READ_BUF_SZ 50000
#define WRITE_BUF_SZ 50000

#pragma region €

#pragma region Concepts
/////////////////////// Concepts ///////////////////////

template <typename, typename> inline constexpr bool is_same = false;
template <typename T> inline constexpr bool is_same<T, T> = true;

template <typename T> struct remove_c_ { using type = T; };
template <typename T> struct remove_c_<const T> { using type = T; };
template <typename T> using remove_c = remove_c_<T>::type;
template <bool v> struct tf_type_ { static constexpr bool value = v; };
using true_type = tf_type_<true>; using false_type = tf_type_<false>;

template <typename> struct is_integral_ : false_type {};
template <typename> struct is_signed_ : false_type {};
template <typename> struct is_unsigned_ : false_type {};

template <> struct is_signed_<bool> : true_type {};
template <> struct is_signed_<char> : true_type {};
template <> struct is_signed_<short> : true_type {};
template <> struct is_signed_<int> : true_type {};
template <> struct is_signed_<long> : true_type {};
template <> struct is_signed_<long long> : true_type {};
template <> struct is_signed_<__int128> : true_type {};

template <> struct is_unsigned_<unsigned char> : true_type {};
template <> struct is_unsigned_<unsigned short> : true_type {};
template <> struct is_unsigned_<unsigned int> : true_type {};
template <> struct is_unsigned_<unsigned long> : true_type {};
template <> struct is_unsigned_<unsigned long long> : true_type {};
template <> struct is_unsigned_<unsigned __int128> : true_type {};

template <typename T> concept is_signed = is_signed_<remove_c<T>>::value;
template <typename T> concept is_unsigned = is_unsigned_<remove_c<T>>::value;
template <typename T> concept is_integral = is_integral_<remove_c<T>>::value || is_signed<T> || is_unsigned<T>;

template <typename> struct unsigned_type_ { using type = unsigned long long; };
template <> struct unsigned_type_<char> { using type = unsigned char; };
template <> struct unsigned_type_<short> { using type = unsigned short; };
template <> struct unsigned_type_<int> { using type = unsigned int; };
template <> struct unsigned_type_<long> { using type = unsigned long; };
template <> struct unsigned_type_<long long> { using type = unsigned long long; };
template <> struct unsigned_type_<__int128> { using type = unsigned __int128; };

template <typename T> using unsigned_type = unsigned_type_<T>::type;
#pragma endregion

#pragma region C++
/////////////////////// C++ ///////////////////////

bool isdigit(char c) { return '0' <= c && c <= '9'; }
bool isblank(char c) { return c == ' ' || c == '\n' || c == '\r'; }

template <typename T> void swap(T& a, T& b) {
    T tmp = a; a = b; b = tmp;
}
template <typename T> T abs(const T& v) { return v < 0 ? -v : v; }
template <typename T> T max(const T& a, const T& b) { return a < b ? b : a; }
template <typename T> T min(const T& a, const T& b) { return a < b ? a : b; }

template <typename T> inline T gcd(T a, T b) { if(a < b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }


template <typename T = long long> class vec {
    T* data_begin = nullptr;
    long long length = 0, capacity = 0;
public:
    explicit vec() {
        data_begin = new T[1]();
    }
    explicit vec(long long len) {
        data_begin = new T[len+1]();
        capacity = len;
    }
    explicit vec(long long len, const T& val) {
        data_begin = new T[len+1]();
        for(long long i = 0; i < len; i++) *(data_begin + i) = val;
        capacity = len;
    }
    vec(const vec& other) : length(other.length), capacity(other.capacity) {
        data_begin = new T[capacity + 1]();
        for (long long i = 0; i < length; i++) {
            data_begin[i] = other.data_begin[i];
        }
    }
    vec& operator=(const vec& other) {
        if (this != &other) {
            delete[] data_begin;
            length = other.length;
            capacity = other.capacity;
            data_begin = new T[capacity + 1]();
            for (long long i = 0; i < length; i++) {
                data_begin[i] = other.data_begin[i];
            }
        }
        return *this;
    }
    vec(vec&& other) noexcept : data_begin(other.data_begin), length(other.length), capacity(other.capacity) {
        other.data_begin = nullptr;
        other.length = other.capacity = 0;
    }
    vec& operator=(vec&& other) noexcept {
        if (this != &other) {
            delete[] data_begin;
            data_begin = other.data_begin;
            length = other.length;
            capacity = other.capacity;
            other.data_begin = nullptr;
            other.length = other.capacity = 0;
        }
        return *this;
    }
    ~vec() { delete[] data_begin; }
    T& operator[](long long idx) { return *(data_begin + idx); }
    T& operator[](long long idx) const { return *(data_begin + idx); }
    T& push(const T& val) {
        if(length == capacity) {
            capacity = (capacity ? capacity * 2 : 1);
            T* old_data = data_begin;
            data_begin = new T[capacity+1]();
            for(long long i = 0; i < length; i++) *(data_begin + i) = *(old_data + i);
            delete[] old_data;
        }
        length++;
        return *(data_begin + length - 1) = val;
    }
    template <typename... C> T& emplace(const C&... c) {
        return push(T(c...));
    }
    T pop() {
        T ret = back();
        length--;
        *(data_begin + length) = T();
        return ret;
    }
    void clear() { length = 0; }
    void dispose() {
        delete[] data_begin;
        length = capacity = 0;
        data_begin = new T[1]();
    }
    T* begin() { return data_begin; } T* begin() const { return data_begin; }
    T* end() { return data_begin + length; } T* end() const { return data_begin + length; }
    T& front() { return *data_begin; } T& front() const { return *data_begin; }
    T& back() { return *(data_begin + length - 1); } T& back() const { return *(data_begin + length - 1); }
    void resize(long long len) {
        long long old_len = length;
        T* old_data = data_begin;
        length = len; capacity = len;
        data_begin = new T[len+1]();
        for(long long i = 0; i < min(len, old_len); i++) *(data_begin + i) = *(old_data + i);
        delete[] old_data;
    }
    long long size() const { return length; }
    bool empty() const { return !length; }
};

class str : public vec<char> {
public:
    str() = default;
    str(const char* c) { // NOLINT(*-explicit-constructor)
        long long l = 0;
        const char* d = c;
        while(*(d++)) l++;
        resize(l);
        for(long long i = 0; i < l; i++) operator[](i) = *(c++);
    }
    bool operator==(const str& b) const {
        if(size() != b.size()) return false;
        for(long long i = 0; i < size(); i++) if(operator[](i) != b[i]) return false;
        return true;
    }
    bool operator==(const char* c) const {
        for(long long i = 0; i < size(); i++)
            if(*c == 0 || operator[](i) != *(c++)) return false;
        return *c == 0;
    }
    friend bool operator==(const char* c, const str& a) {
        for(char i : a) if(*c == 0 || i != *(c++)) return false;
        return *c == 0;
    }
    bool operator<(const str& b) const {
        for(long long i = 0; i < min(size(), b.size()); i++) {
            if(operator[](i) != b[i]) return operator[](i) < b[i];
        }
        return size() < b.size();
    }
};

template <typename T = long long> class list {
    struct node {
        T val;
        long long left, right;
    };
    vec<node> mem; vec<long long> free_mem;
    long long front_ = -1, back_ = -1, size_ = 0;
    long long New() {
        if(!free_mem.empty()) return free_mem.pop();
        mem.emplace(T(), -1, -1); return mem.size() - 1;
    }
    void Delete(long long t) {
        mem[t] = node(T(), -1, -1);
        free_mem.push(t);
    }
public:
    struct iterator {
        list* ptr; long long idx;
        bool operator==(const iterator& b) const { return idx == b.idx; }
        T& operator*() const { return ptr->mem[idx].val; }
        iterator& operator++() { idx = ptr->mem[idx].right; return *this; }
        iterator operator++(int) { iterator ret = *this; idx = ptr->mem[idx].right; return ret; }
        iterator& operator--() { idx = ptr->mem[idx].left; return *this; }
        iterator operator--(int) { iterator ret = *this; idx = ptr->mem[idx].left; return ret; }
    };
    T& front() { return mem[front_].val; } T& front() const { return mem[front_].val; }
    T& back() { return mem[back_].val; } T& back() const { return mem[back_].val; }
    iterator begin() { return {this, front_}; }
    iterator end() { return {this, -1}; }
    void push_front(const T& val) {
        size_++;
        long long cur = New();
        mem[cur].val = val;
        if(front_ != -1) mem[front_].left = cur;
        mem[cur].right = front_;
        front_ = cur;
        if(back_ == -1) back_ = cur;
    }
    void push_back(const T& val) {
        size_++;
        long long cur = New();
        mem[cur].val = val;
        if(back_ != -1) mem[back_].right = cur;
        mem[cur].left = back_;
        back_ = cur;
        if(front_ == -1) front_ = cur;
    }
    T pop_front() {
        size_--;
        T ret = front();
        long long cur = front_;
        if(front_ == back_) back_ = -1;
        front_ = mem[front_].right;
        if(front_ != -1) mem[front_].left = -1;
        Delete(cur);
        return ret;
    }
    T pop_back() {
        size_--;
        T ret = back();
        long long cur = back_;
        if(front_ == back_) front_ = -1;
        back_ = mem[back_].left;
        if(back_ != -1) mem[back_].right = -1;
        Delete(cur);
        return ret;
    }
    long long size() const { return size_; }
    bool empty() const { return !size_; }
};
#pragma endregion

#pragma region Stdio
/////////////////////// Stdio ///////////////////////

extern "C" long read(int fd, void *buf, unsigned long count);
extern "C" long write(int fd, const void *buf, unsigned long count);

char rBuf[READ_BUF_SZ], wBuf[WRITE_BUF_SZ];
int rBufIdx = -1, rBufLen = -1, wBufLen = 0;

void initRBuf_() {
    if(rBufIdx == -1 || rBufIdx == rBufLen) {
        rBufLen = read(0, rBuf, READ_BUF_SZ - 1);
        rBufIdx = 0;
    }
}

char peekc() {
    initRBuf_();
    if(!rBufLen) return 0;
    return rBuf[rBufIdx];
}

char getc() {
    initRBuf_();
    if(!rBufLen) return 0;
    return rBuf[rBufIdx++];
}

bool eof() { return !peekc(); }

void get(char& c) { c = getc(); while(isblank(c)) c = getc(); }

void getline(char* arr) {
    char c = getc();
    while(c != '\n' && c) *(arr++) = c, c = getc();
    *arr = 0;
}

void gettoken(char* arr) {
    char c = getc();
    while(isblank(c)) c = getc();
    while(!isblank(c)) *(arr++) = c, c = getc();
    *arr = 0;
}

void getall(char* arr) {
    while(!eof()) *(arr++) = getc();
    *arr = 0;
}

template <is_integral T> void get(T& t) {
    t = 0; bool neg = false;
    char c = getc();
    while(!isdigit(c) && c != '-') c = getc();
    if(c == '-') neg = true, c = getc();
    while(isdigit(c)) t = t * 10 + (c - '0'), c = getc();
    if(neg) t = -t;
}

void get(bool& t) { int v; get(v); t = v; }

void get(str& s) {
    s.clear();
    char c = getc();
    while(isblank(c)) c = getc();
    while(!isblank(c)) s.push(c), c = getc();
}

template <typename T = long long> T get() { T t; get(t); return t; }

template <typename T1, typename... T2> void get(T1& a, T2&... b) { get(a); get(b...); }

void flush() {
    if(wBufLen) write(1, wBuf, wBufLen);
    wBufLen = 0; wBuf[0] = 0;
}

void putc(char c) {
    wBuf[wBufLen++] = c; wBuf[wBufLen] = 0;
    if(wBufLen == WRITE_BUF_SZ - 1) flush();
}

void put(char c) { putc(c); }

void put(char* c) { while(*c) putc(*c), c++; }
void put(const char* c) { while(*c) putc(*c), c++; }
void put(const str& s) { for(char i : s) putc(i); }

template <is_unsigned T> void put(T t) {
    if(t == 0) { putc('0'); return; }
    T c = 1; while(t / c > 9) c = c * 10;
    while(c) putc('0' + t / c), t -= t / c * c, c = c / 10;
}

void put(bool b) { putc(b ? '1' : '0'); }

template <is_signed T> void put(const T& t) {
    if(t < 0) putc('-'), put(static_cast<unsigned_type<T>>(-(t + 1)) + 1);
    else put(static_cast<unsigned_type<T>>(t));
}

template <typename T1, typename... T2> void put(const T1& a, const T2&... b) { put(a); put(b...); }

template <typename... T> void ln(const T&... a) { put(a...); put('\n'); }
void ln() { put('\n'); }

[[maybe_unused]] struct auto_flush_ { ~auto_flush_() { flush(); } } f;

#pragma endregion

#pragma region Math
/////////////////////// Math ///////////////////////

long double PI = 3.14159265358979323846;

template <typename T> inline T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T modInv(T a, const T& m) { // by @kuhyaku
    T b = m, u = 1, v = 0;
    while (b) { T t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
    u %= m; if (u < 0) {u += m;} return u;
}
inline long long pow(long long a, long long b, long long mod) {return pow_(b < 0 ? modInv(a, mod) : a, abs(b), mod);}
inline long long pow(long long a, long long b) { long long ans=1;while(b){if(b&1)ans=ans*a;b>>=1;a=a*a;} return ans; }
template <typename T> inline T pow(T a, T b) { T ans=1;while(b){if(b&1)ans=ans*a;b>>=1;a=a*a;} return ans; }

#pragma endregion

#pragma region Custom Keywords
/////////////////////// Custom Keywords ///////////////////////
using i64 = long long; using i32 = int; using i128 = __int128;

#pragma endregion

#pragma endregion

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    vec<str> board;
    board.push("xxkkkxx");
    board.push("xxkkkxx");
    board.push("kkkkkkk");
    board.push("kkkkkkk");
    board.push("kkkkkkk");
    board.push("xxkkkxx");
    board.push("xxkkkxx");
    for(auto& a : board) for(char &c : a) if(c == 'k') c = get<char>();

    int ans = 0;
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(board[i][j] != 'o') continue;
            for(int k = 0; k < 4; k++) {
                int mi = i + dy[k], mj = j + dx[k], ni = i + 2 * dy[k], nj = j + 2 * dx[k];
                if(ni < 0 || nj < 0 || ni >= 7 || nj >= 7) continue;
                ans += board[mi][mj] == 'o' && board[ni][nj] == '.';
            }
        }
    }
    ln(ans);
}
