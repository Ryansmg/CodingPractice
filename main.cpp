#include <iostream>
#include <random>
#include <ctime>
#include <vector>
using namespace std;

int main() {
    vector<int> a(100000000);
    cout << "a";
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); //tie(nullptr):2189 printf:388913 notie:766030
    cout.tie(nullptr);
    clock_t start = clock();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0,1);

    int i = dis(gen);
    while(i <= 30000) {
        i++;
        printf("%d", 0);
        cout << 1;
    }

    cout << "\n==============================\n";
    cout << "Time : " << static_cast<double>(clock() - start) << " (ms)\n";
    cout << "==============================";
    */
}