#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int main(void)
{
    int N;
    int arrP[1001];
    int DP[1001];
    int result=0;
    cin >>  N;
    for(int i=0;i<N;i++)
    {
        cin >> arrP[i];
    }
    sort(arrP,arrP+N);
    DP[0]=arrP[0];
    for(int i=1;i<N;i++)
    {
        DP[i] = DP[i-1]+arrP[i];
        //cout << DP[i]<<endl;
    }
    for(int i=0;i<N;i++)
    {
        result +=DP[i];
    }
    cout << result;
}
