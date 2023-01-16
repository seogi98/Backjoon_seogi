#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
vector<pair<int,int>> V;
int DP[501]={0,};
int N;
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first<p2.first;
}
bool isNotCross(pair<int,int> S,pair<int,int> E)
{
    return E.first>S.first&&E.second>S.second;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int A,B;
        cin >> A >> B;
        V.push_back({A,B});
    }
    sort(V.begin(),V.end(),cmp);
    DP[0]=1;
    for(int i=0;i<N;i++)
    {
        int max =1;
        for(int j=0;j<i;j++)
        {
            if(isNotCross(V[j],V[i]))
            {
                if(max <= DP[j])
                {
                    max = DP[j]+1;
                }
            }
        }
        DP[i] = max;
    }
    sort(DP,DP+N);
    cout << N-DP[N-1];
}


