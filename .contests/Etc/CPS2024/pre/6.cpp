#include <bits/stdc++.h>
using namespace std;
using v2 = vector<vector<int>>;

const int north = 0, east = 1, south = 2, west = 3; // 로봇의 방향을 나타내는 상수
const int cw[] = {east, south, west, north}; // cw[i]는 현재 방향이 i일 때 시계 방향으로 회전한 방향
const int ccw[] = {west, north, east, south}; // 반시계 방향으로 회전한 방향

const int n = 10; // 전체 영역의 크기
v2 m; // 치료 상태
v2 special; // 지정한 특정 영역
int r, c; // 로봇의 좌표 (행, 열)
int dir; // 로봇의 현재 방향
int cure_cnt; // 총 치료 횟수

// 초기화
void reset() {
    m = special = v2(n, vector<int>(n, 0));
    cure_cnt = r = c = 0;
    dir = north;
}

// 현재 방향에 따라 로봇 1칸 움직이기
void move() {
    int dr[] = {-1, 0, 1, 0}; // 현재 방향에 따른 행 변화
    int dc[] = {0, 1, 0, -1}; // 현재 방향에 따른 열 변화
    r += dr[dir];
    c += dc[dir];

    // 영역을 나갔다면 반대쪽으로 돌아오게 하기
    if (r < 0) r += n;
    if (c < 0) c += n;
    if (r >= n) r -= n;
    if (c >= n) c -= n;
}

// 제약 조건에 따라 치료하기 (한 번 시도)
void cure() {
    // 지정한 영역인 경우
    if (special[r][c]) {
        dir = ccw[dir]; // 반시계 방향으로 회전
        move();
        return;
    }
    switch (m[r][c]) {
        // 처음 치료하는 경우
        case 0:
            m[r][c]++;
            cure_cnt++;
            dir = cw[dir]; // 시계 방향으로 회전
            break;
        // 두 번쨰 치료하는 경우
        case 1:
            m[r][c]++;
            cure_cnt++;
            dir = ccw[dir]; // 반시계 방향으로 회전
            break;
        // 이미 두 번 치료한 경우
        default:
            break;
    }
    move();
}

int main() {
    // n^2(==100)개의 영역 중 하나를 지정해 시뮬레이션
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            reset();
            special[i][j] = 1; // 지정한 영역을 표시

            // 가능한 최대 시행 횟수는 치료 횟수 (n^2*2) * 맵 크기 (n^2)
            // 보다는 작으므로 10 * n^4번 시행하면 충분하다.
            for (int k = 0; k < 10 * n * n * n * n; k++) cure();

            if (cure_cnt >= 2*n*n-2) { // 지정한 영역을 제외하고 모두 두 번 치료한 경우
                cout << i << ", " << j << '\n'; // "행, 열" 을 출력
            }
        }

    // 출력 결과 :
    // 1, 9
    // 7, 0
}
