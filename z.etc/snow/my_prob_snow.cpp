#include <bits/stdc++.h>
#define int __int128
#define lf __float128
#define double long double
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
using namespace std;
bool printTime = false;

// 눈 내리는 겨울 밤 2147483647
// #lazyprop #coordinate_compression #offline_queries #prefix_sum
// https://ryansmg.notion.site/2147483647-4babe99d5075451ea95f98508bba5203

// 각각 좌표*눈질량 합을 저장하는 lazyprop의 트리 배열, 레이지 배열, 눈질량 합을 저장하는 lazyprop의 트리 배열, 레이지 배열,
// 좌표 압축을 위한 배열, 각 노드가 나타내는 범위의 크기의 누적 합 배열, 각 노드가 나타내는 범위의 좌표 합의 누적 합 배열
vector<int> weightTree, weightLazy, sumTree, sumLazy, comp,
sumW(1, 0), weightW(1, 0);

// 풀이 방법 설명
// [start, end]에 해당하는 노드에 (sumW[end] - sumW[start-1]) * diff를 더하면
// (sumW[end] - sumW[start-1])이 좌표압축 전 범위의 크기를 나타내므로 [start, end]에 쌓인 눈의 질량의 합을 구할 수 있다.
// 마찬가지로 sumW 대신 weightW를 사용하면 범위에서의 좌표의 합(좌표압축 전)을 나타내므로 [start, end]에 쌓인
// ((눈의 질량)*(좌표))의 합을 구할 수 있다.

int tl; // (트리 생성 후)  트리의 크기(리프 노드의 수)를 나타냄

// comp에서 val의 위치를 반환 => 좌표 압축에 사용
int idx(const int &val) {
    return lower_bound(comp.begin(), comp.end(), val) - comp.begin();
}

// a + a+1 + .. + b를 반환
int range_sum(int a, int b) {
    if(a>b) return 0;
    return (a+b)*(b-a+1)/2;
}

// [start, end] 범위의 sumLazy를 update
void update_lazy_sum(int node, int start, int end) {
    if(sumLazy[node] == 0) return;
    sumTree[node] += (sumW[end] - sumW[start-1]) * sumLazy[node];
    if(start != end) {
        sumLazy[node*2] += sumLazy[node];
        sumLazy[node*2+1] += sumLazy[node];
    }
    sumLazy[node] = 0;
}

//[left, right] 범위의 sumTree를 update (+= diff), 탐색하는 범위는 [start, end], 해당하는 노드는 node
void update_range_sum(int node, int start, int end, const int &left, const int &right, int diff) {
    update_lazy_sum(node, start, end);
    if(right<start || end<left) return;
    if(left <= start && end <= right) {
        sumTree[node] += (sumW[end] - sumW[start-1]) * diff;
        if (start != end) {
            sumLazy[node*2] += diff;
            sumLazy[node*2+1] += diff;
        }
    } else {
        update_range_sum(node * 2, start, (start + end) / 2, left, right, diff);
        update_range_sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
        sumTree[node] = sumTree[node*2] + sumTree[node*2+1];
    }
}

//[left, right] 범위의 눈 질량의 합을 return, 탐색하는 범위는 [start, end], 해당하는 노드는 node
int query_sum(int node, int start, int end, const int &left, const int &right) {
    update_lazy_sum(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return sumTree[node];
    return query_sum(node * 2, start, (start + end) / 2, left, right)
           + query_sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

// [start, end] 범위의 weightLazy를 update
void update_lazy_weight(int node, int start, int end) {
    if(weightLazy[node] == 0) return;
    weightTree[node] += (weightW[end] - weightW[start-1]) * weightLazy[node];
    if(start != end) {
        weightLazy[node*2] += weightLazy[node];
        weightLazy[node*2+1] += weightLazy[node];
    }
    weightLazy[node] = 0;
}

//[left, right] 범위의 weightTree를 update (+= diff * 좌표값), 탐색하는 범위는 [start, end], 해당하는 노드는 node
void update_range_weight(int node, int start, int end, const int &left, const int &right, int diff) {
    update_lazy_weight(node, start, end);
    if(right<start || end<left) return;
    if(left <= start && end <= right) {
        weightTree[node] += (weightW[end] - weightW[start-1]) * diff;
        if (start != end) {
            weightLazy[node*2] += diff;
            weightLazy[node*2+1] += diff;
        }
    } else {
        update_range_weight(node * 2, start, (start + end) / 2, left, right, diff);
        update_range_weight(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
        weightTree[node] = weightTree[node*2] + weightTree[node*2+1];
    }
}

//[left, right] 범위의 (눈 질량)*(좌표 값)의 합을 return, 탐색하는 범위는 [start, end], 해당하는 노드는 node
int query_weight(int node, int start, int end, const int &left, const int &right) {
    update_lazy_weight(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return weightTree[node];
    return query_weight(node * 2, start, (start + end) / 2, left, right)
           + query_weight(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

// __int128 형에 직접 입력받는 것이 불가능하므로 long long에 입력받고 변환하는 방법을 사용함
int input() { long long a; cin >> a; return (int) a; }

signed main() {
    auto startTime = clock(); // 실행 시간 측정을 위한 시작 시간 측정
    filein; fileout; // 파일 입출력 활성화
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); // 빠른 입출력
    cout.precision(8); cout << fixed; // 소수점 아래 8자리까지 출력
    int l, n, m; l = input(); n = input(); m = input();
    int a, b, k, t;
    // 쿼리들을 저장하는 배열
    // [0] : 쿼리의 순서, [1] : 쿼리의 종류 (1 또는 2)
    // 쿼리 1인 경우 a, b, k / 쿼리 2인 경우 a, b, 주어진 순서(0~m-1)
    // (a, b는 압축되지 않은 값)
    vector<array<int, 5>> queries;
    // 쿼리 1 입력
    for(int i=1; i<=n; i++) {
        a = input(); b = input(); k = input();
        queries.push_back({i, 1, a, b, k});
        comp.push_back(a);
        comp.push_back(b);
    }
    // 쿼리 2 입력
    for(int i=1; i<=m; i++) {
        t = input(); a = input(); b = input();
        queries.push_back({t, 2, a, b, i-1});
        comp.push_back(a);
        comp.push_back(b);
    }
    vector<lf> answers(m); // 정답을 쿼리가 주어진 순서대로 저장하는 배열
    sort(comp.begin(), comp.end()); // 좌표 압축
    comp.erase(unique(comp.begin(), comp.end()), comp.end()); // 좌표 압축
    tl = (int) comp.size(); // 좌표의 개수 (중복 제외)

    // 트리의 리프 노드를 좌표1, (좌표1+1~좌표2-1), 좌표2, (좌표2+1~좌표3-1), 좌표3, ..., 좌표tl 으로 구성한다.
    sumW.push_back(1);
    weightW.push_back(comp[0]);
    for(int i=1; i<tl; i++) {
        weightW.push_back(range_sum(comp[i-1]+1, comp[i]-1));
        weightW.push_back(comp[i]);
        t = comp[i] - comp[i-1] - 1;
        sumW.push_back(t);
        sumW.push_back(1);
    }
    tl = tl*2-1; // tl에 트리의 크기를 저장
    // 누적 합 계산
    for(int i=2; i<=tl; i++) {
        sumW[i] += sumW[i-1];
        weightW[i] += weightW[i-1];
    }
    sumTree = sumLazy = weightTree = weightLazy = vector<int>(4*tl, 0); // 트리 배열 초기화
    sort(queries.begin(), queries.end()); // 시간 순서대로 쿼리를 정렬
    for(auto &query : queries) {
        query[2] = idx(query[2]); // 좌표 압축
        query[3] = idx(query[3]); // 좌표 압축
        if(query[1] == 1) { // 쿼리 1 : update, (압축 전) query[2] ~ query[3] 범위에 query[4]를 더함
            update_range_sum(1, 1, tl, query[2]*2+1, query[3]*2+1, query[4]);
            update_range_weight(1, 1, tl, query[2]*2+1, query[3]*2+1, query[4]);
        } else { // 쿼리 2 : output, |질량 중심 - 중심 좌표|를 answers 배열의 query[4]번째에 저장
            int sum = query_sum(1, 1, tl, query[2]*2+1, query[3]*2+1);
            int weight = query_weight(1, 1, tl, query[2]*2+1, query[3]*2+1);
            if(sum==0) answers[query[4]] = -1; // 질량 중심을 구할 수 없는 경우
            else answers[query[4]] = abs(((lf)weight / ((lf) sum))
                    - ((lf)(comp[query[2]]+comp[query[3]])/((lf)2))); // |질량 중심 - 중심 좌표|
        }
    }
    for(const lf& i : answers) cout << (double)i << '\n'; // 정답 출력
    auto time = clock()-startTime;
    if(printTime) cout << time; // breakpoint를 지정하거나 printTime을 true로 설정해 걸린 시간을 측정하기 위함
}
