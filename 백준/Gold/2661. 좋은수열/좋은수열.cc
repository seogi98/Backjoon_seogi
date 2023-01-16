#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
#define MAX 1000001

int N;
int map[21][21];
priority_queue<int, vector<int>, greater<int>> pq;

string str = "";

void dfs(int n, char c)
{
    string A;
    string B;
    if (n-1 ==  N)
    {
        cout << str << "\n";
        exit(0);
    }
    str += c;


    for (int i = 1; i <= n / 2; i++)
    {
        A = str.substr(n - i, i);
        B = str.substr(n - i * 2, i);
        if (A == B)
        {
            str.erase(n - 1);
            return;
        }
    }
    dfs(n + 1, '1');
    dfs(n + 1, '2');
    dfs(n + 1, '3');
    str.erase(n - 1);
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    dfs(1, '1');
    dfs(1, '2');
    dfs(1, '3');
}
