#include <iostream>
#include <random>
#include <ctime>
#include <vector>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); //tie(nullptr):2189 printf:388913 notie:766030
    cout.tie(nullptr);
    clock_t start = clock();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0,1);

    int i = 1, j=-200000000;
    while(j <= 300000000) {
        i<<1; j++;
    }

    cout << "\n==============================\n";
    cout << "Time : " << static_cast<double>(clock() - start) << " (ms)\n";
    cout << "==============================";
    
}