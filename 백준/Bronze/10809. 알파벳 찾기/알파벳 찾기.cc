#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;

int N;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string A;
    cin >> A;
    int isEx[50];
    memset(isEx,-1,sizeof(isEx));
    for(int i=0;i<A.length();i++)
    {
        if(isEx[A[i]-'a']==-1)
        {
            isEx[A[i]-'a'] = i;
        }
    }
    for(int i=0;i<='z'-'a';i++)
    {
        cout << isEx[i] << " ";
    }
}