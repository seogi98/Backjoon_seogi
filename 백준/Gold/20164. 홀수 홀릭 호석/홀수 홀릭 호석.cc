#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 99999999
int mx = 0;
int mn = INF;
//갯수 + 합친값 반환
pair<int,string> divNum(int ptr1, int ptr2, string num)
{
	string tmp[3];
	int oddCount=0;
	int numSum=0;
	for (int i = 0; i < num.size(); i++)
	{
		if((num[i]-'0')%2)
		{
			oddCount++;
		}
		if (i <= ptr1)
		{
			tmp[0].push_back(num[i]);
			continue;
		}
		if (ptr1 < i && i <= ptr2)
		{
			tmp[1].push_back(num[i]);
			continue;
		}
		tmp[2].push_back(num[i]);
		continue;
	}
	for (int i = 0; i < 3; i++)
	{
		numSum+=atoi(tmp[i].c_str());
	}
	return {oddCount,to_string(numSum)};
}
//현제 숫자 , 홀 수 합
void rec(string cur,int oddSum)
{
	if(cur.size()<=1)
	{
		int n1 = cur[0]-'0';
		oddSum +=n1%2;
		mx = max(mx,oddSum);
		mn = min(mn,oddSum);
		return;
	}
	if(cur.size() == 2)
	{
		int n1 = cur[0]-'0';
		int n2 = cur[1]-'0';
		oddSum +=n1%2;
		oddSum +=n2%2;
		rec(to_string(n1+n2),oddSum);
		return;
	}
	for(int i=0;i<cur.size()-1;i++)
	{
		for(int j=i+1;j<cur.size()-1;j++)
		{
			pair<int,string> tmp = divNum(i,j,cur);
			rec(tmp.second,oddSum+tmp.first);
			continue;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string num;
	cin >> num;
	rec(num,0);
	cout << mn << " " << mx;
}
