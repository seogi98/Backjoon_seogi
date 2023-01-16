#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
using namespace std;

typedef struct Student
{
    string name;
    int K;
    int E;
    int M;
}S;
bool cmp(S a,S b)
{
    {
        if(a.K == b.K)
        {
            if(a.E == b.E)
            {
                if(a.M == b.M)
                {
                    return a.name>b.name;
                }
                return a.M<b.M;
            }
            return a.E>b.E;
        }
        return a.K<b.K;
    }
}; 
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<S> v;
    for (int i = 0; i < N; i++)
    {
        S t;
        cin >> t.name >> t.K >> t.E >>t.M;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=v.size()-1;i>=0;i--)
    {
        cout << v[i].name << "\n";
    }
}