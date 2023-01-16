#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;
void artGen(int R,int G,int B)
{
    int resultT=0;
    char resultC;
    resultT = 2126*R+7152*G+722*B;
    if(0<=resultT&&resultT<510000){resultC = '#';}
    else if(510000<=resultT&&resultT<1020000){resultC = 'o';}
    else if(1020000<=resultT&&resultT<1530000){resultC = '+';}
    else if(1530000<=resultT&&resultT<2040000){resultC = '-';}
    else if(resultT>=2040000){resultC = '.';}
    else{resultC='x';}
    cout << resultC;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int R,G,B;
            cin >> R >> G >> B;
            artGen(R,G,B);
        }
        cout << "\n";
    }
}