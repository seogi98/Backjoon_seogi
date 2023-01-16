#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

#include<stdlib.h>

using namespace std;
int b=0;
int w=0;
int m=0;
int arr[2200][2200]={0,};

int findPaper(int h,int v,int len)
{
    int result=0;
    int hlen = len/3;
    bool isRec=false;
    int fn = arr[h][v];

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
        result = 
        findPaper(h,v,hlen)+
        findPaper(h+hlen,v,hlen)+
        findPaper(h+2*hlen,v,hlen)+
        findPaper(h,v+hlen,hlen)+
        findPaper(h+hlen,v+hlen,hlen)+
        findPaper(h+2*hlen,v+hlen,hlen)+
        findPaper(h,v+2*hlen,hlen)+   
        findPaper(h+hlen,v+2*hlen,hlen)+   
        findPaper(h+2*hlen,v+2*hlen,hlen); 
        return result;            
    }
    else
    {
        if(fn==0){
            w++;
        }
        else if(fn ==1)
        {
            b++;
        }
        else if(fn  == -1)
        {
            m++;
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
    cout << m << endl;
    cout << w<<endl;
    cout << b<<endl;
}
