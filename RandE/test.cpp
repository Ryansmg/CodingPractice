#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd()); // 랜덤한 수를 만드는 클래스
    uniform_int_distribution dis(1, 100); // [1, 100] 사이로 수를 분배해주는 클래스
    for(int i=0; i<100; i++) cout << dis(gen) << ' '; // 랜덤한 수 생성
}
