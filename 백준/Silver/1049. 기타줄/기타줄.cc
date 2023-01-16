#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    int mnS = 9999;
    int mn = 9999;
    for(int i=0;i<M;i++)
    {
        int A,B;
        cin >> A >> B;
        mnS = min(mnS,A);
        mn = min(mn,B);
    }
    int result =0;
    mnS>mn*6?result=mn*N:result = min((N/6)*mnS+(N%6)*mn,((N/6)+1)*mnS);
    cout << result;
}