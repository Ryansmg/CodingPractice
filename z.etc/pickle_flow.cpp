//code by p1ckle/sft
#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8, rne = 1000;
int n, m, h[1003], w[1003][103], c[103];
int ans, cap[1103][1103], flow[1103][1103], par[1103], source = 0, sink = 1101;
vector<int> ver[1103];
queue<int> q;

void input() {

    //문제에서 제시된 대로 입력받기
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {

        cin >> h[i];
        for (int j = 1; j <= h[i]; j++) cin >> w[i][j];

    }
    for (int i = 1; i <= m; i++) cin >> c[i];
}

void modeling() {

    //network flow를 위한 모델링(전처리)
    //0번 노드는 source, 1101번 노드는 sink
    for (int i = 1; i <= n; i++) {

        ver[source].push_back(i);
        ver[i].push_back(source);
        cap[source][i] = 1;

    }
    for (int i = rne+1; i <= rne+m; i++) {

        ver[i].push_back(sink);
        ver[sink].push_back(i);
        cap[i][sink] = c[i-rne];

    }
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= h[i]; j++) {

            ver[i].push_back(rne+w[i][j]);
            ver[rne+w[i][j]].push_back(i);
            cap[i][rne+w[i][j]] = 1;

        }

    }

}

void networkflow() {

    //모델링 된 구조로 network flow 실행
    while (true) {

        fill(par, par+1103, -1);
        q.push(source);
        while (!q.empty()) {

            //bfs
            int cor = q.front(); q.pop();
            for (int nxt : ver[cor]) {

                if (cap[cor][nxt] - flow[cor][nxt] > 0 && par[nxt] == -1) {

                    q.push(nxt);
                    par[nxt] = cor;
                    if (nxt == sink) break;

                }

            }

        }
        if (par[sink] == -1) return;

        int mxflow = inf;
        for (int cor = sink; cor != source; cor = par[cor])
            mxflow = min(cap[par[cor]][cor] - flow[par[cor]][cor], mxflow);
        for (int cor = sink; cor != source; cor = par[cor]) {

            flow[par[cor]][cor] += mxflow;
            flow[cor][par[cor]] -= mxflow;

        }
        ans += mxflow;

    }

}

int main() {

    input();
    modeling();
    networkflow();
    cout << ans;

}
