#include <iostream>
#include <algorithm>
#include <string.h>
#include<queue>

using namespace std;

int main(void)
{
    int n;
    int arr[1001];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}

