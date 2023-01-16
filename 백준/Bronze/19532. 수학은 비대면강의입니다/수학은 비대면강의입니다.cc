#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int P[7];
    int mtx[2][2];
    for(int i=0;i<6;i++)
    {
        cin >> P[i];
    }
    //(P[2],P[5])
    mtx[0][0] = P[4];
    mtx[0][1] = -P[1];
    mtx[1][0] = -P[3];
    mtx[1][1] = P[0];
    int divN = mtx[0][0]*mtx[1][1] - mtx[0][1]*mtx[1][0];
    int X = (mtx[0][0]*P[2] + mtx[0][1]*P[5])/divN;
    int Y = (mtx[1][0]*P[2] + mtx[1][1]*P[5])/divN;
    cout << X << " " << Y;
}
