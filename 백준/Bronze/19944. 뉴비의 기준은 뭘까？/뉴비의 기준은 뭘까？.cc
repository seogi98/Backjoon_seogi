#include<iostream>
using namespace std;
int main(void)
{
	int N,M;
	cin >> N >> M;
	if(M<=2){
		cout << "NEWBIE!";
		return 0;
	}
	if(M<=N)
	{
		cout << "OLDBIE!";
		return 0;
	}
	cout << "TLE!";

}