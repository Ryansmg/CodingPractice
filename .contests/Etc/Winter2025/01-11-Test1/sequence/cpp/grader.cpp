#include "sequence.h"

#include <cstdio>
#include <vector>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	std::vector<int> L, R, X;
	for (int i = 0; i < M; i++) {
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		L.push_back(l);
		R.push_back(r);
		X.push_back(x);
	}

	std::vector<int> result = find_sequence(N, L, R, X);
	for (int i = 0; i < result.size(); i++) printf("%d ", result[i]);
}