#include<iostream>
#include<queue>
#include<functional>

using namespace std;
int main(void)
{
	int a;
	cin >> a;
	if(89<a&&a<101)
	{
		cout<<"A";
	}
	else if(79<a&&a<90)
	{
		cout << "B";
	}
	else if(69<a&&a<80)
	{
		cout << "C";
	}
	else if(59<a&&a<70)
	{
		cout << "D";
	}
	else
	{
		cout << "F";
	}
}