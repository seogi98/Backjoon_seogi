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
    string A;
    int num=0;
    while(cin.eof()==false)
    {
        cin >> A;
        num++;
    }
    cout << num-1;
    
}