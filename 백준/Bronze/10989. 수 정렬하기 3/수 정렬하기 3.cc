#include <iostream>
#include <algorithm>
#include <string.h>
#include<queue>
#define MAX2 10000
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int arr[MAX2+1]={0,};
    int n,a;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >>a;
        arr[a]++;
    }
    for(int i=1;i<=MAX2;i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            cout << i<<"\n";    
        }
    }
}
