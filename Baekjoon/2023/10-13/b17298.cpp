#include <stdio.h>
#include <stack>
using namespace std;

static int input[1000000] = { 0 };
static int ans[1000000] = { 0 };

int main() {
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        scanf(" %d", input + i);
    }
    stack<int> st;
    int ind;
    for (int i = 0; i < size; i++)
    {
        ind = size - i - 1;
        while (!st.empty() && st.top() <= input[ind])
            st.pop();
        if (st.empty()) ans[ind] = -1;
        else ans[ind] = st.top();
        st.push(input[ind]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(ans + i));
    }
}