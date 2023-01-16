#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
/*
	문제번호, 분류 , 난이도
*/

// 푼 문제는 TRUE
pair<int, int> recPro[MAX];
struct problem
{

	// 난이도
	int L;
	// 문제 번호
	int N;
	// 분류
	int G;
};

struct cmp{
	bool operator()(const problem& p1,const problem& p2) const
	{
		if (p1.L == p2.L)
		{
			return p1.N < p2.N;
		}
		return p1.L < p2.L;
	}
};
set<problem, cmp> s1;
set<problem, cmp> s2[101];
void recommend(int G, int x)
{
	problem result;
	if (x == -1)
	{
		set<problem>::iterator iter = s2[G].begin();
		problem tmp = *iter;
		result = tmp;
	}
	if (x == 1)
	{
		set<problem>::iterator iter = s2[G].end();
		problem tmp = *(--iter);
		result = tmp;
	}
	cout << result.N << "\n";
}
void recommend2(int x)
{
	problem result;
	if (x == -1)
	{
		set<problem>::iterator iter = s1.begin();
		problem tmp = *iter;
		result = tmp;
	}
	if (x == 1)
	{
		set<problem>::iterator iter = s1.end();
		problem tmp = *(--iter);
		result = tmp;
	}
	cout << result.N << "\n";
}
void recommend3(int x, int L)
{
	set<problem>::iterator iter = s1.begin();
	if (x == -1)
	{
		// 가장 어려운 문제
		iter = s1.lower_bound({L,0,0});
		problem tmp = *(--iter);
		if(tmp.L >= L){
			cout << "-1\n";
			return;
		}
	}
	if (x == 1)
	{
		// 가장 쉬운 문제
		iter = s1.upper_bound({L,0,0});
	}
	if (iter == s1.end())
	{
		cout << "-1\n";
		return;
	}
	problem result = *iter;
	cout << result.N << "\n";
}
void add(int P, int L, int G)
{
	recPro[P] = {L, G};
	s1.insert({L, P, G});
	s2[G].insert({L, P, G});
}
void solved(int P)
{
	pair<int, int> tmp = recPro[P];
	s1.erase({recPro[P].first, P, recPro[P].second});
	s2[tmp.second].erase({recPro[P].first, P, recPro[P].second});
	recPro[P] = {0, 0};
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int P, L, G;
		cin >> P >> L >> G;
		add(P, L, G);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string op;
		cin >> op;
		if (op == "recommend")
		{
			int x, G;
			cin >> G >> x;
			recommend(G, x);
		}
		if (op == "recommend2")
		{
			int x;
			cin >> x;
			recommend2(x);
		}
		if (op == "recommend3")
		{
			int x, L;
			cin >> x >> L;
			recommend3(x, L);
		}
		if (op == "add")
		{
			int P, L, G;
			cin >> P >> L >> G;
			add(P, L, G);
		}
		if (op == "solved")
		{
			int P;
			cin >> P;
			solved(P);
		}
	}
}
