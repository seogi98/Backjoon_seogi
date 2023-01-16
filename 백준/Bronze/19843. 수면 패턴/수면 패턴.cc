#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,int> D = {{"Mon",0},{"Tue",24},{"Wed",48},{"Thu",72},{"Fri",96}};
    int T,N;
    cin >> T >> N;
    int sum=0;
    for(int i=0;i<N;i++)
    {
        string d1,d2;
        int h1 , h2;
        cin >> d1 >> h1 >> d2 >> h2;
        sum += (D[d2]+h2) - D[d1]-h1;
    }
    int result = T-sum;
    if(result>48)
    {
        cout << -1;
        return 0;
    }
    if(result<=0)
    {
        cout << 0;
        return 0;
    }
    cout << result;
}
