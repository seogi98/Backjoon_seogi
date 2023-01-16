#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<pair<int,string>> v;

bool cmp(pair<int,string> a,pair<int,string> b)
{
    return a.first<b.first;
}

int main(void)
{
    cin >> N;
    int Y;
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> Y >>  name;
        v.push_back({Y,name});
    }
    stable_sort(v.begin(),v.end(),cmp);
    for(int i=0;i<N;i++)
    {
        cout << v[i].first << " "<<v[i].second<<"\n";
    }
    
}