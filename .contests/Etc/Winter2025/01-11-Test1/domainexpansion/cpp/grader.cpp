#include <iostream>
#include <vector>

extern std::vector<int> count_graphs(int N, std::vector<int> U, std::vector<int> V);

void my_assert(bool x){
    if (!x){
        puts("Wrong input");
        exit(0);
    }
}

int main(){
    int N, M;
    my_assert(scanf("%d %d", &N, &M) == 2);
    
    std::vector<int> U(M), V(M);
    for (int i=0;i<M;i++){
        my_assert(scanf("%d %d", &U[i], &V[i]) == 2);
    }
    
    std::vector<int> ans = count_graphs(N, U, V);
    printf("%d\n", (int)ans.size());
    for (int i=0;i<(int)ans.size();i++){
        printf("%d", ans[i]);
        if (i+1 < (int)ans.size()) printf(" ");
    }
    printf("\n");
}