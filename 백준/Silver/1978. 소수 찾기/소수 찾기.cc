#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool prime[1001]={false,};
int main(void)
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
    int N;
    int arr[51];
    int result=0;
    cin >>N;
    prime[1] = true;
    for(int i=2;i<=1000;i++)
    {
        if(prime[i]==false)
        {
            for(int j=i*2;j<=1000;j+=i)
            {
                prime[j]=true;
            }
        }
    }
    while(N--)
    {
        int tmp2;
        cin >> tmp2;
        if(prime[tmp2]==false)
        {
            result++;
        }
    }
    cout << result;
}