#include <iostream>
#include <vector>
#include <string>
 
extern std::vector<int> find_union(int N, std::vector<int> A, std::vector<int> B, std::vector<int> C, std::vector<int> D);

const int MAX_COORD = 1e9;

void my_assert(bool x) {
	if (!x) {
		puts("Wrong input");
		exit(0);
	}
}

int main() {
	int N;
	my_assert(scanf("%d", &N) == 1);

	std::vector<int> A(N), B(N), C(N), D(N);
	for (int i = 0; i < N; i++) {
		my_assert(scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]) == 4);
		my_assert(-MAX_COORD <= A[i] && A[i] <= C[i] && C[i] <= MAX_COORD);
		my_assert(-MAX_COORD <= B[i] && B[i] <= D[i] && D[i] <= MAX_COORD);
	}

	std::vector<int> U = find_union(N, A, B, C, D);

	for (int i = 0; i < (int)U.size(); i++) {
		printf("%d ", U[i]);
	}
	printf("\n");
	return 0;
}
