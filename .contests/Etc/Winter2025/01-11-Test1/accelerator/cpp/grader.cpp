#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

extern std::string accelerator(std::vector<int> U, std::vector<int> V, std::vector<int> A, std::vector<int> B);

void my_assert(bool x) {
    if (!x) {
        puts("Constraints not satisfied");
        exit(0);
    }
}

int main() {
    int N, M;
    my_assert(scanf("%d %d", &N, &M) == 2);
    std::vector<int> U(N - 1), V(N - 1);
    for (int i = 0; i < N - 1; i++) {
        my_assert(scanf("%d %d", &U[i], &V[i]) == 2);
        my_assert(0 <= U[i] && U[i] < N);
        my_assert(0 <= V[i] && V[i] < N);
    }
    std::vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        my_assert(scanf("%d %d", &A[i], &B[i]));
        my_assert(0 <= A[i] && A[i] < N);
        my_assert(0 <= B[i] && B[i] < N);
        my_assert(A[i] != B[i]);
    }
    std::string S = accelerator(U, V, A, B);
    printf("%s\n", S.c_str());
    return 0;
}
