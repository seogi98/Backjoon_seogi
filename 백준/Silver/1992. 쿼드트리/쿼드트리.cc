#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>

#include<stdlib.h>

using namespace std;
char arr[128][128];
int b=0;
int w=0;


void findPaper(int h,int v,int len)
{
    int result=0;
    int hlen = len/2;
    bool isRec=false;
    char fn = arr[h][v];

    for(int i=h;i<h+len;i++)
    {
        for(int j=v;j<v+len;j++)
        {
            if(fn!=arr[i][j])
            {
                isRec=true;
                break;
            }
        }
    }
    if(isRec==true)
    {
        cout << "(";
        findPaper(h,v,hlen);
        findPaper(h,v+hlen,hlen);
        findPaper(h+hlen,v,hlen);
        findPaper(h+hlen,v+hlen,hlen);   
        cout << ")";
    }
    else
    {
        if(fn=='0'){
            cout << "0";
        }
        else
        {
           cout << "1";
        }
    }
}
int main(void)
{
    int N;
    cin >>N;
    for(int i=0;i<N;i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    findPaper(0,0,N);
}
