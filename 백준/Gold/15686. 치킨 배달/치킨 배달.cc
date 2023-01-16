#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
#define MAX 1000001

vector<pair<int, int>> Hv, Cv; //집 , 치킨 vector
priority_queue<int, vector<int>, greater<int>> pq;
int N, M, tmp;
int chick[14];
int Hn = 0;
int Cn = 0;
int ans = 0;
int searchDistance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int findChickenDistance(vector<pair<int, int>> resultV) // CTv에 넣은 치킨값과 비교한다.
{
    int result = 0;
    
    
    for (int i = 0; i < Hv.size(); i++)
    {
        int sD = 0;
        int min = MAX;
        for (int j = 0; j < resultV.size(); j++)
        {
            sD = searchDistance(resultV[j], Hv[i]);
            if (min > sD)
            {
                min = sD;
            }
        }
        result += min;
    }
    //for (int i = 0; i < resultV.size(); i++)
    {
        //cout <<"x : "<< resultV[i].first <<" y : "<<resultV[i].second<< endl;     
    }
    //cout <<"result : "<<result <<endl;
    return result;
}
void dfs(int n, vector<pair<int, int>> CTv) // dfs중간에 넣을 치킨 vector
{

    if (CTv.size() >= M||Cv.size()<=n)
    {
        pq.push(findChickenDistance(CTv));
        return;
    }
    dfs(n+1, CTv);
    CTv.push_back({Cv[n]});
    dfs(n + 1, CTv);
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    vector<pair<int, int>> tmpV;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> tmp;
            if (tmp == 1)
            {
                Hv.push_back({j, i});
                Hn++;
            }
            if (tmp == 2)
            {
                Cv.push_back({j, i});
                Cn++;
            }
        }
    }
    dfs(0, tmpV);
    //cout << findChickenDistance(Cv);
    //while (!pq.empty())
    {
        cout << pq.top() << endl;
        //pq.pop();
    }
}
