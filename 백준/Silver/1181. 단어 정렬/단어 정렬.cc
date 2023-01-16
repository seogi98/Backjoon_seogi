#include <iostream>
#include <algorithm>
#include <string.h>
#include<queue>
#define MAX 10000001
using namespace std;

bool cmp(string str1,string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();


    if(len1 == len2)
    {
        return str1<str2;
    }
    else
    {
        return len1<len2;
    }
    
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str[20001];
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> str[i];
    }
    sort(str,str+N,cmp);    
    for(int i=0;i<N;i++)
    {
        if(str[i]==str[i-1])
        {
            continue;
        }
        cout << str[i]<<"\n";
    }

}