#include <cstdio>
#include <cstdlib>
#include <vector>

extern std::vector<std::vector<int> > set_tasks(int);
extern std::vector<int> find_location(std::vector<std::vector<int> >);

void my_assert(bool x) {
	if (!x) {
		puts("Constraints not satisfied");
		exit(0);
	}
}

int main(){
    int N;
    my_assert(scanf("%d", &N) == 1);

    std::vector<std::vector<int> > S = set_tasks(N);
    int K = (int)S.size();
    my_assert(1 <= K && K <= 35);

    std::vector<int> C (K);
    for(int i=0; i<K; i++){
        C[i] = (int)S[i].size();
        for(int a=0; a<C[i]; a++) my_assert(1 <= S[i][a] && S[i][a] <= N);
        for(int a=0; a<C[i]; a++) for(int b=a+1; b<C[i]; b++) my_assert(S[i][a] != S[i][b]);
    }

    for(int i=0; i<K; i++){
        for(int j=0; j<C[i]; j++) printf("%d ", S[i][j]);
        puts("");
    }

    int T;
    my_assert(scanf("%d", &T) == 1);

    std::vector<std::vector<int> > R (T);
    for(int i=0; i<T; i++){
        R[i] = std::vector<int> (K);
        for(int j=0; j<K; j++){
            my_assert(scanf("%d", &R[i][j]) == 1);
        }
    }

    std::vector<int> L = find_location(R);
    for(int i=0; i<T; i++){
        printf("%d ", L[i]);
    }
}
