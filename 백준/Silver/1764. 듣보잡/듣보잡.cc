using namespace std;
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
vector<string> q;
vector<string> A;
vector<string> B;

bool cmp(string A, string B)
{
	return A > B;
}
int main(void)
{
	int N, M, count = 0;
	int len;
	string tmp;
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		B.push_back(tmp);
	}
	sort(B.begin(), B.end());
	for (int i = 0; i < N; i++)
	{
		if (binary_search(B.begin(), B.end(), A.at(i)))
		{
			count++;
			q.push_back(A.at(i));
		}
	}
	sort(q.begin(), q.end(),cmp);
	cout << q.size() << endl;
	while (q.size())
	{
		cout << q.back() << endl;
		q.pop_back();
	}
}