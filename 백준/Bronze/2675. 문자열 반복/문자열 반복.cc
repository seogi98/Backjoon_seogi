#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;

int N;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        string A;
        cin  >> N;
        cin >> A;
        for(int i=0;i<A.length();i++)
        {
            for(int j=0;j<N;j++)
            {
                cout << A[i];
            }
        }
        cout << "\n";
    }
}