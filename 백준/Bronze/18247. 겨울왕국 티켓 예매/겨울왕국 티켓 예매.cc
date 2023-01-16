#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
#define MAX 1000001

vector<pair<int, int>> v;
queue<pair<int, int>> Cq;
bool prime[MAX] = {
    false,
};
int main(void)
{
    //L은 12
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T,N,M;
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        if(N<12||M<4)
        {
            cout << "-1"<<"\n";
        }
        else
        {
            cout <<  (M*11)+4<<"\n";

        }
    }
}
