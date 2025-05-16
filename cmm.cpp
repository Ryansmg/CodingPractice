#define READ_BUF_SZ 100000
#define WRITE_BUF_SZ 100000

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

inline bool isdigit(char c) { return '0' <= c && c <= '9'; }
inline bool islower(char c) { return 'a' <= c && c <= 'z'; }
inline bool isupper(char c) { return 'A' <= c && c <= 'Z'; }
inline bool isalpha(char c) { return islower(c) || isupper(c); }
inline bool isblank(char c) { return c == ' ' || c == '\n' || c == '\r'; }

inline void assert_(bool a, const char* str, int line);
#define assert(...) assert_(__VA_ARGS__, # __VA_ARGS__, __LINE__)

namespace random {
    __int128 next = 1;
    struct init_random_ {
        init_random_() {
            int* i = new int(0);
            next = reinterpret_cast<long long>(i);
            delete i;
        }
    } i_r_;
}

long long rand() {
    return random::next = (random::next * 998244353998244353 + 155715571557) % 9223372036854775807;
}

// [0..bound)
long long rand(long long bound) { return rand() % bound; }

// [l..r]
long long rand(long long l, long long r) {
    return rand() % (r - l + 1) + l;
}

void srand(__int128 seed) { random::next = seed; }

template <typename T> void swap(T& a, T& b) {
    T tmp = a; a = b; b = tmp;
}
template <typename T> T abs(const T& v) { return v < 0 ? -v : v; }
template <typename T> T max(const T& a, const T& b) { return a < b ? b : a; }
template <typename T> T min(const T& a, const T& b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a < b ? b : a; }
long long min(long long a, long long b) { return a < b ? a : b; }

template <typename T> inline T gcd(T a, T b) { if(a < b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }

template <typename T> inline bool less(const T& a, const T& b) { return a < b; }
template <typename T> inline bool greater(const T& a, const T& b) { return a > b; }
template <typename T> inline bool less_equal(const T& a, const T& b) { return a <= b; }
template <typename T> inline bool greater_equal(const T& a, const T& b) { return a >= b; }

template <typename T = long long> class vec {
    T* data_begin = nullptr;
    long long length = 0, capacity = 0;
public:
    explicit vec() {
        data_begin = new T[1]();
    }
    explicit vec(long long len) {
        data_begin = new T[len+1]();
        length = capacity = len;
    }
    explicit vec(long long len, const T& val) {
        data_begin = new T[len+1]();
        for(long long i = 0; i < len; i++) *(data_begin + i) = val;
        length = capacity = len;
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
    T& push_back(const T& val) { return push(val); }
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
template <typename T = long long> using vector = vec<T>;
namespace std { template <typename T = long long> using vector = vec<T>; }

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
using string = str;

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

template <typename T = long long> class queue : public list<T> {
public:
    void push(const T& v) { this->push_back(v); }
    T pop() { return this->pop_front(); }
    T back() = delete;
};

template <typename T = long long> class stack : public list<T> {
public:
    void push(const T& v) { this->push_front(v); }
    T pop() { return this->pop_front(); }
    T top() { return list<T>::front(); }
    T back() = delete;
    T front() = delete;
};

template <typename T1 = long long, typename T2 = long long>
class pair {
public:
    T1 first; T2 second;
    pair() : first(), second() {}
    pair(const T1& a, const T2& b) : first(a), second(b) {}
    T1& operator[](int i) requires is_same<T1, T2> {
        return i ? second : first;
    }
    T1& operator[](int i) const requires is_same<T1, T2> {
        return i ? second : first;
    }
};

long long stoll(const str& s) {
    long long r = 0;
    for(char c : s) r = r * 10 + (c - '0');
    return r;
}

#pragma region Algorithm

template <typename T, typename Compare> void merge(const T* s1, const T* e1, const T* s2, const T* e2, T* out, Compare cmp = less<T>) {
    while(s1 != e1 && s2 != e2) {
        if(cmp(*s1, *s2)) *(out++) = *(s1++);
        else *(out++) = *(s2++);
    }
    while(s1 != e1) *(out++) = *(s1++);
    while(s2 != e2) *(out++) = *(s2++);
}

template <typename T, typename Compare> void merge(const vec<T>& a, const vec<T>& b, vec<T>& out, Compare cmp = less<T>) {
    merge(a.begin(), a.end(), b.begin(), b.end(), out.begin(), cmp);
}

template <typename T, typename Compare> void naive_sort(T* s, T* e, Compare cmp = less<T>) {
    for(T* i = s; i != e; i++)
        for(T* j = i + 1; j != e; j++)
            if(!cmp(*i, *j)) swap(*i, *j);
}

template <typename T, typename Compare> void sort_(T* s, T* e, T* buf, Compare cmp) {
    long long dist = e - s;
    if(dist <= 5) {
        naive_sort(s, e, cmp);
        return;
    }
    sort_(s, s + dist / 2 + 1, buf, cmp);
    sort_(s + dist / 2 + 1, e, buf, cmp);
    merge(s, s + dist / 2 + 1, s + dist / 2 + 1, e, buf, cmp);
    for(long long i = 0; i < dist; i++) *(s + i) = *(buf + i);
}

template <typename T> void sort(T* s, T* e) { sort(s, e, less<T>); }
template <typename T, typename Compare> void sort(T* s, T* e, Compare cmp) {
    T* buffer = new T[e - s]();
    sort_(s, e, buffer, cmp);
    delete[] buffer;
}

template <typename T, typename Compare> void sort(vec<T>& v, Compare cmp) { sort(v.begin(), v.end(), cmp); }
template <typename T> void sort(vec<T>& v) { sort(v.begin(), v.end(), less<T>); }

template <typename T> void reverse(T* s, T* e) {
    if(s == e--) return;
    while(s != e) swap(*s, *e), s++, e--;
}
template <typename T> void reverse(vec<T>& v) { reverse(v.begin(), v.end()); }

#pragma endregion


#pragma endregion

#pragma region Splay

template <typename T> concept hasUpdFunc = requires(T& a, const T* l, const T* r) { a.update(l, r); };
template <typename T> concept hasPushFunc = requires(T& a, T* l, T* r) { a.push(l, r); };
template <typename T> concept hasFlip = requires(T a) { a.flip; };

/// can detect: void T.update(const T*, const T*)
///             void T.push(T*, T*)
///             bool T.flip
/// 추가 기능을 구현하려면 내려갈 때 push 함수를 잘 호출해줘야 함
/// 0-based index
template <typename T> class Splay {
public:
    struct Node {
        Node *l = nullptr, *r = nullptr, *p = nullptr;
        T v = T(); int cnt = 1;
        Splay* sp = nullptr;
        ~Node() { delete l; delete r; }
        Node(const T& value, Splay* splay) : v(value), sp(splay) {}
        explicit Node(Splay* splay) : sp(splay) {}
        friend Splay;
        template <typename Callable> inline void forEach(const Callable& f) { Splay<T>::forEach(this, f); }
        template <typename Callable> inline void preorder(const Callable& f) { Splay<T>::preorder(this, f); }

        inline void upd() {
            if(l) l->push();
            if(r) r->push();
            if constexpr (hasUpdFunc<T>) v.update(l ? &l->v : nullptr, r ? &r->v : nullptr);
            for(auto f : sp->updFunctions) f(*this);
            cnt = 1 + (l ? l->cnt : 0) + (r ? r->cnt : 0);
        }
        inline void push() {
            if constexpr(hasPushFunc<T>) v.push(l ? &l->v : nullptr, r ? &r->v : nullptr);
            for(auto f : sp->pushFunctions) f(*this);
        }
    };
protected:
    vector<void(*)(Node&)> updFunctions;
    vector<void(*)(Node&)> pushFunctions;

    int sz = 0;
    int size() const { return sz; }
    Node* tree = nullptr;
    void rotate(Node *x) {
        Node *p = x->p, *b;
        if(!p) return;
        p->push(); x->push();
        if(x == p->l) p->l = b = x->r, x->r = p;
        else p->r = b = x->l, x->l = p;
        x->p = p->p; p->p = x;
        if(b) b->p = p;
        (x->p ? p == x->p->l ? x->p->l : x->p->r : tree) = x;
        p->upd(); x->upd();
    }
public:
    void splay(Node* x, Node* g = nullptr) {
        while(x->p != g) {
            Node *p = x->p, *pp = p->p;
            if(pp == g) { rotate(x); break; }
            rotate((x == p->l) == (p == pp->l) ? p : x);
            rotate(x);
        }
    }
    Node* insert(Node* pos, bool left, const T& val) {
        sz++;
        if(left) {
            assert(pos->l == nullptr);
            pos->l = new Node(val, this);
            pos->l->p = pos;
            pos = pos->l;
        } else {
            assert(pos->r == nullptr);
            pos->r = new Node(val, this);
            pos->r->p = pos;
            pos = pos->r;
        }
        splay(pos);
        return pos;
    }
    Node* insertPrev(Node* pos, const T& val) {
        pos->push();
        if(pos->l) {
            pos = pos->l, pos->push();
            while(pos->r) pos = pos->r, pos->push();
            return insert(pos, false, val);
        } else return insert(pos, true, val);
    }
    Node* insertNext(Node* pos, const T& val) {
        pos->push();
        if(pos->r) {
            pos = pos->r, pos->push();
            while(pos->l) pos = pos->l, pos->push();
            return insert(pos, true, val);
        } else return insert(pos, false, val);
    }
    void erase(Node* p) {
        sz--;
        splay(p);
        if(p->l) {
            if(p->r) {
                tree = p->l;
                tree->p = nullptr;
                Node* x = tree;
                while(x->r) x = x->r;
                x->r = p->r;
                p->r->p = x;
                splay(x);
                p->l = p->r = nullptr;
                delete p; return;
            }
            tree = p->l;
            tree->p = nullptr;
            p->l = p->r = nullptr;
            delete p; return;
        }
        if(p->r) {
            tree = p->r;
            tree->p = nullptr;
            p->l = p->r = nullptr;
            delete p; return;
        }
        delete p;
        tree = nullptr;
    }
    ~Splay() { delete tree; }
    Splay() = default;
    explicit Splay(int length, void (*updateFunc)(Node&) = nullptr, void (*pushFunc)(Node&) = nullptr) : sz(length) {
        if(updateFunc) updFunctions.push_back(updateFunc);
        if(pushFunc) pushFunctions.push_back(pushFunc);
        if(!length) return;
        Node* x = tree = new Node(this);
        for(long long i = 1; i < length; i++) {
            x->r = new Node(this);
            x->r->p = x;
            x = x->r;
        }
        while(x) x->upd(), x = x->p;
    }
    explicit Splay(const std::vector<T>& arr, void (*updateFunc)(Node&) = nullptr, void (*pushFunc)(Node&) = nullptr) {
        long long length = static_cast<long long>(arr.size());
        sz = length;
        if(updateFunc) updFunctions.push_back(updateFunc);
        if(pushFunc) pushFunctions.push_back(pushFunc);
        if(!length) return;
        Node* x = tree = new Node(arr[0], this);
        for(long long i = 1; i < length; i++) {
            x->r = new Node(arr[i], this);
            x->r->p = x;
            x = x->r;
        }
        while(x) x->upd(), x = x->p;
    }

    void addUpdFun(void (*updateFunc)(Node&)) { updFunctions.push_back(updateFunc); }
    void addPushFun(void (*pushFunc)(Node&)) { pushFunctions.push_back(pushFunc); }

    const Node* root() const { return tree; }
    Node* root() { return tree; }

    // k >= 0
    Node* kth(int k) {
        assert(0 <= k && k < sz);
        auto x = tree;
        x->push();
        while(true) {
            while(x->l && x->l->cnt > k) x = x->l, x->push();
            if(x->l) k -= x->l->cnt;
            if(!k--) break;
            x = x->r; x->push();
        }
        splay(x);
        return x;
    }

    // k >= 0
    inline T operator[](int k) { return kth(k)->v; }

    // 0-based index, s > 0, e < sz - 1
    Node* gather(int s, int e) {
        kth(e + 1);
        auto tmp = tree;
        kth(s - 1);
        splay(tmp, tree);
        return tree->r->l;
    }

    // 0-based index
    void set(int k, const T& val) {
        kth(k);
        tree->v = val;
    }

    void set(Node* x, const T& val) {
        x->v = val;
    }

    inline T operator()(int s, int e) { return gather(s, e)->v; }

    template <typename Callable>
    static void forEach(Node* i, const Callable& t) {
        i->push();
        if(i->l) forEach(i->l, t);
        t(*i);
        if(i->r) forEach(i->r, t);
    }

    template <typename Callable>
    inline void forEach(const Callable& f) { forEach(tree, f); }

    template <typename Callable>
    static void preorder(Node* i, const Callable& t) {
        i->push();
        t(*i);
        if(i->l) preorder(i->l, t);
        if(i->r) preorder(i->r, t);
    }

    template <typename Callable>
    inline void preorder(const Callable& f) { preorder(tree, f); }

    static void push_flip(Splay<T>::Node& a) requires hasFlip<T> {
        if(!a.v.flip) return;
        swap(a.l, a.r);
        if(a.l) a.l->v.flip ^= 1;
        if(a.r) a.r->v.flip ^= 1;
        a.v.flip = false;
    }

    /// 1 <= l <= r <= size - 2
    void flip(int l, int r) requires hasFlip<T> {
        auto x = gather(l, r);
        T t = x->v; t.flip = true;
        set(x, t);
    }

    /// 1 <= s <= e <= size - 2
    void shift(int s, int e, int k) requires hasFlip<T> {
        if(k >= 0) {
            k %= e - s + 1; if(!k) return;
            flip(s, e); flip(s, s+k-1); flip(s+k, e);
        } else {
            k *= -1; k %= e - s + 1; if(!k) return;
            flip(s, e); flip(s, e-k); flip(e-k+1, e);
        }
    }

    int idxOf(Node* tar) {
        Node* p = tar;
        int idx = 0; bool addLS = true;
        while(p) {
            if(addLS && p->l) idx += p->l->cnt;
            if(p->p && p->p->r == p) addLS = true, idx++;
            else addLS = false;
            p = p->p;
        }
        p = kth(idx);
        assert(p == tar);
        return idx;
    }

    vector<Node*> ptrArr() {
        vector<Node*> ret;
        auto x = [&](Node& p) { ret.push_back(&p); };
        forEach(x);
        return ret;
    }
};

template <typename T = long long> class set : public Splay<T> {
    using Node = Splay<T>::Node;
public:
    long long size() const { return this->sz; }
    void insert(const T& key) {
        Node *p = this->tree;
        if(!p) {
            this->tree = new Node(key, this);
            return;
        }
        while(true) {
            if(key == p->v) return;
            if(key < p->v) {
                if(!p->l) {
                    Splay<T>::insert(p, true, key);
                    break;
                }
                p = p->l;
            } else {
                if(!p->r) {
                    Splay<T>::insert(p, false, key);
                    break;
                }
                p = p->r;
            }
        }
    }

    /// 없는 경우 nullptr를 반환
    T* find(const T& key) {
        Node* p = this->tree;
        if(!p) return nullptr;
        while(p) {
            if(key == p->v) break;
            if(key < p->v) {
                if(!p->l) break;
                p = p->l;
            } else {
                if(!p->r) break;
                p = p->r;
            }
        }
        Splay<T>::splay(p);
        return key == p->v ? &p->v : nullptr;
    }

    inline bool contains(const T& key) { return find(key); }

    void erase(const T& key) {
        Node* t = find(key);
        if(!t) return;
        Splay<T>::erase(t);
    }
};
template <typename Key = long long, typename Value = long long>
class map {
    struct Pair {
        Key key = Key(); Value value = Value();
        bool operator==(const Pair& b) const { return key == b.key; }
        bool operator<(const Pair& b) const { return key < b.key; }
    };
private:
    set<Pair> s;
public:
    bool contains(const Key& key) { return s.contains({key}); }
    void insert(const Key& key, const Value& value) {
        Pair p = { key, value };
        auto x = s.find(p);
        if(x) x->value = value;
        else s.insert(p);
    }
    void erase(const Key& key) { s.erase({key}); }
    long long size() const { return s.size(); }
    Value& operator[](const Key& key) {
        auto x = s.find({key});
        if(!x) {
            s.insert({key});
            x = s.find({key});
        }
        return x->value;
    }
    const Value& operator[](const Key& key) const { return operator[](key); }
};

#pragma endregion

#pragma region Stdio
/////////////////////// Stdio ///////////////////////

extern "C" long read(int fd, void *buf, unsigned long count);
extern "C" long write(int fd, const void *buf, unsigned long count);

char rBuf[READ_BUF_SZ], wBuf[WRITE_BUF_SZ];
int rBufIdx = -1, rBufLen = -1, wBufLen = 0;

inline void initRBuf_() {
    if(rBufIdx == -1 || rBufIdx == rBufLen) {
        rBufLen = read(0, rBuf, READ_BUF_SZ - 1);
        rBufIdx = 0;
    }
}

inline char peekc() {
    initRBuf_();
    if(!rBufLen) return 0;
    return rBuf[rBufIdx];
}

inline char getc() {
    initRBuf_();
    if(!rBufLen) return 0;
    return rBuf[rBufIdx++];
}

inline bool eof() { return !peekc(); }

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

template <typename T = long long> inline T get() { T t; get(t); return t; }

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

[[maybe_unused]] struct auto_flush_ { ~auto_flush_() { flush(); } } a_f_;

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

#pragma region Kotlin

#define CONCAT_INNER_(x, y) x##y
#define CONCAT_(x, y) CONCAT_INNER_(x, y)
#define repeat_(n, i) for(long long i = 0; i < n; i++)
#define repeat(n) repeat_(n, CONCAT_(rep_var_, __COUNTER__))

#pragma endregion

#pragma region Python

struct range {
    long long s, e;
    struct iterator {
        long long cur;
        iterator& operator++() { ++cur; return *this; }
        iterator operator++(int) { auto r = *this; cur++; return r; }
        iterator& operator--() { --cur; return *this; }
        iterator operator--(int) { auto r = *this; cur--; return r; }
        bool operator==(const iterator& b) const { return cur == b.cur; }
        bool operator<(const iterator& b) const { return cur < b.cur; }
        long long operator*() const { return cur; }
    };
    explicit range(long long n) : s(0), e(n) {}
    /// [left..right]
    range(long long left, long long right) : s(left), e(right + 1) {}
    iterator begin() const { return {s}; }
    iterator end() const { return {e}; }
};

#pragma endregion

#pragma region Rust

#define loop while(true)

#pragma endregion

#pragma region Custom Keywords
/////////////////////// Custom Keywords ///////////////////////
using i64 = long long; using i32 = int; using i128 = __int128;
#ifdef LOCAL
const bool is_local = true;
#else
const bool is_local = false;
#endif

inline void assert_(bool a, const char* str, int line) {
    if(!a) {
        do {
            ln();
            put("ASSERTION FAILED: ");
            ln(str);
            flush();
        } while(!is_local);
    }
}

#pragma endregion

template <typename T = long long, typename AddType = T> struct segtree {
    vec<T> tree; signed n = -1; signed offset = 1;
    explicit segtree(const vec<T> &arr) {
        n = signed(arr.size()); tree = vec<T>(2 * n, T());
        for(signed i = n, j = 0; i < 2 * n; i++, j++) tree[i] = arr[j];
        for(signed i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    segtree() = default;
    explicit segtree(signed i) { tree = vec<T>(i * 2, T()); n = i; }
    segtree(signed lBound, signed rBound) {
        n = rBound - lBound + 1; offset = lBound;
        tree = vec<T>(n * 2, T());
    }
    void add(signed tar, const AddType& val) { tar -= offset;
        tree[n + tar] += val;
        for(signed i = (n + tar) >> 1; i; i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    void set(signed tar, const T &val) { tar -= offset;
        tree[n + tar] = val;
        for(signed i = (n + tar) >> 1; i; i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    inline void set(signed tar, const auto& val) { set(tar, T(val)); }
    template <typename T2, typename... T3> requires (sizeof...(T3) > 0)
    inline void set(signed tar, const T2& val, const T3&... arr) { set(tar, T(val, arr...)); }
    T query(signed left, signed right) { left -= offset; right -= offset;
        signed l = n + left, r = n + right + 1;
        T ansL, ansR;
        bool lSet = false, rSet = false;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) {
                if(!lSet) lSet = true, ansL = tree[l++];
                else ansL = ansL + tree[l++];
            }
            if(r & 1) {
                if(!rSet) rSet = true, ansR = tree[--r];
                else ansR = tree[--r] + ansR;
            }
        }
        if(!lSet) return ansR;
        if(!rSet) return ansL;
        return ansL + ansR;
    }
    inline T query(signed tar) { return tree[n + tar - offset]; }
};

#pragma endregion

// 우선순위 : set 처리 후
// (왼쪽 서브트리의 크기 + 1) * X + s를 더함
struct T {
    i64 value = 0;
    i64 set = -1; // -1인 경우 연산 없음
    i64 X = 0, s = 0;
    i64 sum = 0;
    void update(const T* l, const T* r) {
        sum = value + (l ? l->sum : 0) + (r ? r->sum : 0);
    }
};

i64 sum(i64 l, i64 r) {
    return (r - l + 1) * (l + r) / 2;
}

void push(Splay<T>::Node& a) {
    i64 lsz = (a.l ? a.l->cnt : 0);
    i64 rsz = (a.r ? a.r->cnt : 0);
    if(a.v.set != -1) {
        a.v.value = a.v.set;
        a.v.sum = a.v.set * (lsz + rsz + 1);
        if(a.l) a.l->v.X = a.l->v.s = 0, a.l->v.set = a.v.set;
        if(a.r) a.r->v.X = a.r->v.s = 0, a.r->v.set = a.v.set;
        a.v.set = -1;
    }
    a.v.value += (lsz + 1) * a.v.X + a.v.s;

    a.v.sum += sum(1, lsz + rsz + 1) * a.v.X;
    a.v.sum += (lsz + rsz + 1) * a.v.s;

    if(a.l) a.l->v.X += a.v.X, a.l->v.s += a.v.s;
    if(a.r) a.r->v.X += a.v.X, a.r->v.s += (lsz + 1) * a.v.X + a.v.s;
    a.v.X = 0, a.v.s = 0;
}

void pr(Splay<T>::Node &a) {
    put(a.v.value, " ");
}

int main() {
    int n, q; get(n, q);
    vec<T> arr(n + 2);
    for(int i : range(1, n)) arr[i].value = get();
    Splay<T> splay(arr, 0, push);
    for(int _ : range(q)) {
        int op = get(), a, b, c, x;
        if(op == 1) {
            get(a, b, x);
            auto t = splay.gather(a, b);
            T v = t->v; v.set = x;
            splay.set(t, v);
        }
        else if(op == 2) {
            get(a, b, x);
            auto t = splay.gather(a, b);
            T v = t->v; v.X += x;
            splay.set(t, v);
        }
        else if(op == 3) {
            get(c, x);
            T v{x};
            splay.insertPrev(splay.kth(c), v);
        }
        else {
            get(a, b);
            auto x = splay.gather(a, b);
            ln(x->v.sum);
        }
    }
}
