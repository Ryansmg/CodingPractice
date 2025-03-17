#include <iostream>

int sqrt(long long int i) {
    long long int ans = 1;
    while(ans*ans<i) ans++;
    if(ans*ans>i) ans--;
    return ans;
}

int main()
{
    int t; std::cin >> t; std::cout << sqrt(t);
}