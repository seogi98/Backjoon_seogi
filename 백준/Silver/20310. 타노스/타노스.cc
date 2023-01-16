#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string in;
    string out;
    cin >> in;
    int count1=0;
    int count0=0;
    for(int i=0;i<in.size();i++)
    {
        char t = in[i];
        if(t == '0') 
        {
            count0++;
            if(count0%2 == 0) out.push_back(t);
        }
        if(t == '1') 
        {
            count1++;
            if(count1%2 == 0) out.push_back(t);
        }
    }
    sort(out.begin(),out.end());
    cout << out;
}