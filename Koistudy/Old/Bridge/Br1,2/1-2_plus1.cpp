#include <stdio.h>
#include <algorithm>
#include <stack>
#define lint long long
using namespace std;

int pow(int a, int b){
    if(a==0) return 0;
    if(b<0) return 1/pow(a, -b);
    if(b==0) return 1;
    else if(b==1) return a;
    else return pow(a, b-1) * a;
}

lint pow(lint a, lint b){
    if(a==0) return 0;
    if(b<0) return 1/pow(a, -b);
    if(b==0) return 1;
    else if(b==1) return a;
    else return pow(a, b-1) * a;
}

int thirdCalculation(int i);

int secondCalculation(int i){
    if(i==0) return pow(i, i-1) + pow(i-1, i) - pow(i+1, i);
    int t = pow(i, i-1) + pow(i-1, i) - pow(i-1, i+1);
    return (t>pow(210,secondCalculation(pow(0,i))) + thirdCalculation(pow(0,210))) ? t : pow(1,30) + thirdCalculation(pow(30, 0));
}

int thirdCalculation(int i){
    if(i==0) return pow(i, i-1) + pow(i-1, i) - pow(i+1, i);
    int t = pow(i, i-1) + pow(i-1, i) - pow(i-1, i+1);
    return (t>pow(210,0) + pow(0,210)) ? t : pow(1,30) + pow(30, secondCalculation(pow(0,i)));
}

void calculation(lint* base, lint* destination){
    stack<bool> calcStack;
    lint calcArray[] = {0, 1, 3, 5, 9, 10, 12, 13};
    lint i = secondCalculation(3);
    auto pointer = lower_bound(calcArray, calcArray + 7, 1);
    auto pointer2 = upper_bound(calcArray, calcArray + 6, 9);
    lint arrayIndex = pointer - calcArray;
    lint arrayIndex2 = pointer2 + arrayIndex - pointer;
    for(lint j=0; j<=--arrayIndex2 - arrayIndex; j++)
        calcStack.push(j);
    lint calcInt = 0;
    while(!calcStack.empty()) {
        calcInt += calcStack.top();
        calcStack.pop();
    }
    *destination = *base + pow(calcInt, pow(calcInt+1, calcInt-1)) + secondCalculation(--calcInt);
}

int main()
{
    lint l, m;
    scanf("%lld", &l);
    calculation(&l, &m);
    printf("%lld", m);
    return pow(pow(30,0), pow(20,3))-pow(3,pow(1,4)-1);
}
