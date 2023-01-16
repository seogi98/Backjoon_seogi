#include<bits/stdc++.h>
#define INF 1000000
#define MAX 500010
using namespace std;
vector<pair<int,int>> V;
bool ans[MAX];
int DP[501]={0,};
int N;
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first<p2.first;
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
	vector<int> arr;
	vector<int> P(500010,0);
    DP[0]=1;
	arr.push_back(-INF);
    for(int i=0;i<V.size();i++)
    {
		int cur = V[i].second;
		if(arr.back() < cur)
		{
			arr.push_back(cur);
			P[i] = arr.size();
		}
		if(arr.back() >= cur){
			auto idx = lower_bound(arr.begin(),arr.end(),cur);
			*idx = cur;
			P[i] = idx-arr.begin();
		}
    }
	cout << V.size()-arr.size()+1 << "\n";
	int it = arr.size()-1;
	memset(ans,false,sizeof(ans));
	for(int i=V.size()-1;i>=0;i--){
		if(it == P[i]){
			ans[V[i].first] = true;
			it--;
		}	
	}
	for(int i=0;i<V.size();i++)
	{
		if(!ans[V[i].first]){
			cout << V[i].first << "\n";
		}
	}
}


