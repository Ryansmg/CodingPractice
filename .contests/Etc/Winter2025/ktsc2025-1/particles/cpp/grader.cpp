#include <iostream>
#include <vector>
 
extern void initialize(int N, std::vector<int> A, std::vector<int> B);
extern int generate(int v, bool result);
 
void my_assert(bool x){
    if (!x){
        puts("Wrong input");
        exit(0);
    }
}
 
int main(){
    int N, Q;
    my_assert(scanf("%d %d", &N, &Q) == 2);
    
    std::vector<int> A(N-1), B(N-1);
    for (int i=0;i<N-1;i++){
        my_assert(scanf("%d %d", &A[i], &B[i]) == 2);
        my_assert(0 <= A[i] && A[i] <= N-1);
        my_assert(0 <= B[i] && B[i] <= N-1);
        my_assert(A[i] != B[i]);
    }
    
    std::vector<int> V(Q), R(Q);
    for (int i=0;i<Q;i++){
        my_assert(scanf("%d %d", &V[i], &R[i]) == 2);
        my_assert(0 <= V[i] && V[i] <= N-1);
        my_assert(R[i] == 0 || R[i] == 1);
    }
    
    initialize(N, A, B);
    
    std::vector<int> ans(Q);
    for (int i=0;i<Q;i++){
        ans[i] = generate(V[i], R[i]==1);
    }
    
    for (int i=0;i<Q;i++){
        printf("%d\n", ans[i]);
    }
}
