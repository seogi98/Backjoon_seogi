#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N,A,B;
    cin >> N >> A >> B;
    int cnt=0;
    while(A!=B)
    {
        cnt++;
        if((A%2)&&A!=1)//홀수
        {
            A=A/2+1;
        }
        else if(!(A%2)&&A!=1)
        {
            A=A/2;
        }

        if((B%2)&&B!=1)
        {
            B=B/2+1;
        }
        else if(!(B%2)&&B!=1)
        {
            B=B/2;
        }
    }
    cout << cnt;

}


