#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
struct MO{
    int N;
    int sum;
};
bool cmp(MO m1 , MO m2)
{
     if(m1.sum == m2.sum)
     {
         return m1.N  < m2.N;
     }
     return m1.sum > m2.sum;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<MO> V;
    for(int i=1;i<=N;i++)
    {
        int W,H;
        cin >> W >> H;
        V.push_back({i,pow(W,2)+pow(H,2)});
    }
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<N;i++) cout << V[i].N << "\n";
}