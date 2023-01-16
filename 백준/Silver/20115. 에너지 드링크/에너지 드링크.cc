#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 999999999999999
priority_queue<double> pq;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double N;
	cin >> N;
	double sum=0;
	for(double i=0;i<N;i++)
	{
		double t;
		cin >> t;
		pq.push(-t);
	}
	while(pq.size()>1)
	{
		//작은거
		sum += -pq.top();
		pq.pop();
	}
	cout << -pq.top()+(sum/2);
}
