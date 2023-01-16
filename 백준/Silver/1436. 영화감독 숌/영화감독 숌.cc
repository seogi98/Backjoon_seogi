#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;
#define MAX 999999999999999

int N, M;
char map[51][51];
int mx = 0;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int N;
    cin >> N;
    int tmp=0;
    for(int i=666;i<MAX;i++)
    {
        s = to_string(i);
        if(s.find("666")!=string::npos)
        {
            tmp++;
            if(tmp == N)
            {
                cout << i;
                return 0;
            }
        }
    }
    
}