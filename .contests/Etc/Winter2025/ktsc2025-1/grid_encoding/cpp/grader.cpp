#include <vector>
#include <iostream>
#include "grid_encoding.h"
using namespace std;

static int N;
static vector<pair<int,int>> cells;

void ensure(bool p, const char *err) {
	if (!p) {
		cout << err << endl;
		exit(0);
	}
}

void select(int x, int y){
	ensure(0 <= x && x < N && 0 <= y && y < N, "Wrong Answer [1]");
	cells.push_back({x,y});
	ensure(cells.size() <= N*N, "Wrong Answer [2]");
}


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


    int tests;
    cin >> tests;
    for(int test=0;test<tests;test++){

        cin >> N;

        vector<vector<int>>A(N,vector<int>(N));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> A[i][j];
            }
        }
        vector<int>X(N), Y(N);
        for(int i=0;i<N;i++){
            cin >> X[i];
        }
        for(int i=0;i<N;i++){
            cin >> Y[i];
        }

        cells.clear();
        send(A);

        vector<vector<int>>B(N,vector<int>(N));

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                B[i][j] = -1;
            }
        }
        for(auto &[x,y] : cells){
            B[X[x]][Y[y]] = A[x][y];
        }

        auto res = reconstruct(B);

        ensure(res.size() == N, "Wrong Answer [3]");
        for(int i=0;i<N;i++){
            ensure(res[i].size() == N, "Wrong Answer [3]");
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ensure(res[X[i]][Y[j]] == A[i][j], "Wrong Answer [4]");
            }
        }

		int K = cells.size();
		cout << "K: " << K << "\n";
    }

	return 0;
}
