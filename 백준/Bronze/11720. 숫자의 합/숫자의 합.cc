#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    string A;
    int result =0;
    cin >> N;
    cin >> A;
    for(int i=0;i<N;i++)
    {
        result+=A[i]-'0';
    }
    cout << result;

}