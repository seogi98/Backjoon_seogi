#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

int N;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string A, B;
    cin >> A >> B;
    bool aBig = false;
    for (int i = 2; i >= 0; i--)
    {
        if (A[i] == B[i])
            continue;
        A[i] > B[i] ? aBig = true : aBig = false;
        break;
    }
    string tmp;
    aBig == true ? tmp = A : tmp = B;
    while (!tmp.empty())
    {
        cout << tmp.back();
        tmp.pop_back();
    }
}