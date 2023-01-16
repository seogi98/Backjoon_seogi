#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int N, S;
int C[101];
int mx = 0;

pair<int, int> D[51];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first == b.first ? a.second > b.second : a.first > b.first;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> D[i].first >> D[i].second;
    }
    for (int i = 0; i < N; i++)
    {
        int rank=1;
        for (int j = 0; j < N; j++)
        {
            if(D[i].first < D[j].first&&D[i].second < D[j].second)
            {
                rank++;
            }
        }
        cout << rank<<"\n";
        
    }
    
    
    
}