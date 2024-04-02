#include <iostream>
#include <random>
using namespace std;

bool isAvailable(int i) {
    //int exclude[] = {7, 8, 12, 5, 11, 1, 14};
    int exclude[] = {11, 28, 33};
    for(int j : exclude) if(j==i) return false;
    return true;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0, 25);
    FILE *output = fopen("output.txt", "w");
    for(int i=0; i<200000; i++) {
        fprintf(output, "%c", 'a' + dis(gen));
    }
    fclose(output);
    // int i = dis(gen);
    // while(!isAvailable(i)) i = dis(gen);

    //cout << i;
}
