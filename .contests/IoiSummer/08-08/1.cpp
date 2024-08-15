//#include "nostl.h"
#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false

#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

using i16 = short;
using i32 = signed;
using i64 = long long;
using i128 = __int128;
using u16 = unsigned short;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using f128 = long double;

#define int i64
#define uint u64
//#define double long double
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &

const long long llmax = 9223372036854775807; // 2^63-1
const long long INF = 1000000000000000000; // INF * INF > 2^63
const long long inf = 3000000000; // inf > 2^31, inf * inf < 2^63
const signed smax = 2147483647;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define pass {cout << "";} // do nothing

#ifndef ONLINE_JUDGE
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
#else
#define filein cout << ""
#define fileout filein
#endif
#define fileio filein; fileout

__int128 operator ""_I(const char* str, size_t len) {
    __int128 t = 0; i64 st=0, sign=1; if(*str == '-') sign=-1, st=1;
    for(i64 i=st; i < len; i++) { t *= 10; t += (*(str + i) - '0'); }
    return t*sign;
}


#define all(vec) (vec).begin(), (vec).end()

template <typename T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <typename T> T min(T a, T b, T c, T d) { return min(min(a, b), min(c, d)); }
template <typename T> T min(T a, T b, T c, T d, T e) { return min(min(a, b), min(c, d), e); }
template <typename T> T min(T a, T b, T c, T d, T e, T f) { return min(min(a, b), min(c, d), min(e, f)); }
template <typename T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <typename T> T max(T a, T b, T c, T d) { return max(max(a, b), max(c, d)); }
template <typename T> T max(T a, T b, T c, T d, T e) { return max(max(a, b), max(c, d), e); }
template <typename T> T max(T a, T b, T c, T d, T e, T f) { return max(max(a, b), max(c, d), max(e, f)); }

enum Null_{} null_;

//@formatter:on
#pragma endregion

template <class T>
class linkedList {

public:
    struct node {
        node* prev = nullptr;
        node* next = nullptr;
        T data;
        explicit node(T d) {
            data = d;
        }
    };
    node* first = nullptr;
    node* last = nullptr;
    i64 size = 0;
public:
    /**
     * tar 뒤에 val을 삽입합니다.
     */
    void insertNode(node *tar, node *val) {
        val->prev = tar;
        val->next = tar->next;
        if(tar->next) tar->next->prev = val;
        tar->next = val;
        if(tar == last) last = val;
        size++;
    }
    void deleteNode(node *tar) {
        if(tar->next) tar->next->prev = tar->prev;
        if(tar->prev) tar->prev->next = tar->next;
        if(tar == first) first = tar->next;
        if(tar == last) last = tar->prev;
        delete tar;
        size--;
    }
    linkedList()=default;
    ~linkedList() {
        if(!first) return;
        node* cur = last;
        while(cur) {
            node* p = cur->prev;
            delete cur;
            cur = p;
        }
    }

    node* get(i64 index) {
        node* cur = first;
        for(i64 i=0; i<index; i++) {
            cur = cur->next;
            if(cur==nullptr) assert(false);
        }
        return cur;
    }
    T operator[](i64 index) { return get(index)->data; }

    /**
     * index 위치에 val 값을 넣습니다. 즉, 이전의 [index]의 값은 [index+1]로 이동합니다.
     * @param index val을 넣을 위치, 0 <= val <= size
     * @param val 삽입할 값
     */
    void insert(i64 index, i64 val) {
        node* n = new node(val);
        if(index == 0) {
            n->next = first;
            if(first) first->prev = n;
            first = n;
            if(!last) last = n;
            size++;
        } else if (index == size) {
            if(last) last->next = n;
            n->prev = last;
            last = n;
            size++;
        } else {
            node* cur = get(index);
            insertNode(cur->prev, n);
        }
    }
    void push_front(i64 val) {
        insert(0, val);
    }
    void push_back(i64 val) {
        insert(size, val);
    }
    void remove(i64 index) {
        deleteNode(get(index));
    }
};

#pragma region disable c-style types
#define float
#undef int
#define int
#undef double
#define double
#pragma endregion
i32 main() {
    i64 n; scanf(" %lld", &n);
    linkedList<char>::node *iter = nullptr;
    linkedList<char> list;
    forn(i, n) {
        i64 type; scanf(" %lld", &type);
        linkedList<char>::node *t;
        char c;
        switch(type) {
            case 1:
                if(iter) iter = iter->prev;
                break;
            case 2:
                if(iter == nullptr && list.first) iter = list.first;
                else if(iter && iter->next) iter = iter->next;
                break;
            case 3:
                scanf(" %c", &c);
                if(!iter) {
                    list.insert(0, c);
                    iter = list.first;
                } else {
                    t = new linkedList<char>::node(c);
                    list.insertNode(iter, t);
                    iter = t;
                }
                break;
            case 4:
                if(iter == nullptr) break;
                t = iter -> prev;
                list.deleteNode(iter);
                iter = t;
                break;
        }
    }
    for(auto ptr = list.first; ptr != nullptr; ptr = ptr->next) {
        printf("%c", ptr->data);
    }
}
