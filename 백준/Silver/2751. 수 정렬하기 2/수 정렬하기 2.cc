#include <iostream>
#include <algorithm>
#include<queue>
#define MAX 1000000
using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool arr[MAX+1]={false,};
    bool darr[MAX+1]={false,};
    int n,a;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a;
        if(a>=0){   
            arr[a]=true;   
        }
        else
        {
            darr[-a]=true;
        }
        
    }
    for(int i=MAX;i>0;i--)
    {
        if(darr[i])
        {
            cout <<-i<<"\n";
        }
    }
    for(int i=0;i<=MAX;i++)
    {
        if(arr[i])
        {
            cout << i<<"\n";
        }
    }
}

