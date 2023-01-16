#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int result=0;
    for(int i=1;i<=MAX;i++)
    {
        int ans=0;
        int cur = i;
        ans+=cur;
        string tmp = to_string(cur);
        for(int i=0;i<tmp.size();i++)
        {
            ans+=tmp[i]-'0';
        }
        if(ans==N)
        {
            result = cur;
            break;
        }
    }
    cout << result;

}