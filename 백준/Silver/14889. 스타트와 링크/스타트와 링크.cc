#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
#define MAX 1000001

int N;
int map[21][21];
priority_queue<int,vector<int>,greater<int>> pq;

int searchAbility(vector<int> v)
{
    int result = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            result += map[v[i]][v[j]];
        }
    }
    return result;
}
void dfs(int n, vector<int> St)
{
    if (St.size() == N / 2)
    {
        vector<int> Lk;
        bool isSt[30] = {
            false,
        };
        for (int i = 0; i < St.size(); i++)
        {
            isSt[St[i]] = true;
        }
        for (int i = 1; i <= N; i++)
        {
            if (!isSt[i])
            {
                Lk.push_back(i);
            }
        }
        pq.push(abs(searchAbility(St) - searchAbility(Lk)));
    }
    if (St.size() < N / 2 && n < N)
    {
        dfs(n + 1, St);
        St.push_back(n + 1);
        dfs(n + 1, St);
    }
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> rest;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }
    dfs(1, rest);
    //while (!pq.empty())
    {
        cout << pq.top();
        //pq.pop();
    }
}
