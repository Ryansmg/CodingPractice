#include <iostream>
#include <random>
using namespace std;

int main() {
    int width;
    cin >> width;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0,2);

    for(int i=0; i<width; i++) {
        cout << (char) (dis(gen) + 'A');
    }

}