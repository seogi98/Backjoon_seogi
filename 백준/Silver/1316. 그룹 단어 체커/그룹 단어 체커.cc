#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

int N;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    int result =0;
    cin >> N;
    while(N--)
    {
        string A;
        cin >> A;
        int len = A.length();
        char prev = A[0];
        bool isEx[50];
        memset(isEx,false,sizeof(isEx));
        isEx[A[0]-'a']=true;
        for(int i=1;i<len;i++)
        {
            if(A[i] == prev)
            {
                continue;
            }
            if(isEx[A[i]-'a'])
            {
                result--;
                break;
            }
            else
            {        
                isEx[A[i]-'a'] = true;   
            }
            prev=A[i];
        }
        result++;
    }
    cout << result;
}