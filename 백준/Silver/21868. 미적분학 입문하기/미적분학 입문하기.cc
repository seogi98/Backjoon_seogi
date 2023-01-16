#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int e1,e2;
	cin >> e1 >> e2;
	int x1,x2;
	cin >> x1 >> x2;
	int x0;
	cin >> x0;
	cout << x1*x0+x2 <<"\n";
	if(x1 == 0){
		cout << "0 0";
		return 0;
	}
	cout << e1 << " "<<abs(x1*e2);
}
