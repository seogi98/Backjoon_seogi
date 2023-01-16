#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

#include<stdlib.h>

using namespace std;
int b=0;
int w=0;
char arr[150][150]={0,};

int findPaper(int h,int v,int len)
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
        return findPaper(h,v,hlen)+findPaper(h+hlen,v,hlen)+findPaper(h,v+hlen,hlen)+findPaper(h+hlen,v+hlen,hlen);     
    }
    else
    {
        if(fn=='0')
            w++;
        else
        {
            b++;
        }
        return 0;
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
    cout << w<<endl;
    cout << b<<endl;
}
