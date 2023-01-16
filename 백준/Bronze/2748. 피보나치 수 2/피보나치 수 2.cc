#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

unsigned long long int fibo[100];

unsigned long long int getFibo(int n)
{
	fibo[0]=1;
	fibo[1]=1;
	if(n<=1)
	{
		return fibo[n];
	}
	if(fibo[n]!=0)
	{
		return fibo[n];
	}
	fibo[n] =getFibo(n-1)+getFibo(n-2);
	return fibo[n];
}

int main(void)
{
	int N;
	cin >> N;
	cout << getFibo(N-1);
	
}    
    