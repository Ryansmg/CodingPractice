#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

static char input[500000];

int main() {
    scanf("%s", input);
    //fgets(input, sizeof(input), stdin);
    queue<int> qB;
    queue<int> qC;
    int ans = 0, ind;
    int size = strlen(input);
    for (int i = 0; i < size; i++)
    {
        ind = size - i - 1;
        switch (input[ind])
        {
        case 'A':
            if (!qB.empty()) { 
                ans++;
                qB.pop();
            }
            break;
        case 'B':
            qB.push(ind);
            break;
        case 'C':
            qC.push(ind);
            break;
        default:
            break;
        }
    }

    while (!qC.empty() && !qB.empty())
    {
        while (qB.front() > qC.front() && !qB.empty()) qB.pop();
        if (qB.empty()) break;
        qC.pop(); qB.pop(); ans++;
    }

    printf("%d", ans);
}