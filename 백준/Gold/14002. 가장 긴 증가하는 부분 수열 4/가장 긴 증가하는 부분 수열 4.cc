#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include<stack>
#define MAXX 1001
using namespace std;

int N;
pair<int, int> dp[1001]; // (배열의 길이, 이전의 노드)
void seeDp()
{
    for(int i=0;i<N;i++)
    {
        cout << i << " : "<<dp[i].first << " , " << dp[i].second << "\n";
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> arr;
    int resultMx = 1;
    int resultNode = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        arr.push_back(A);
        dp[i].second =-1;
        dp[i].first = 1;
    }
    for (int i = 1; i < N; i++)
    {
        int mx = 0;   // 최대 길이
        int node = -1; // 최대 길이일떄 이전노드
        for (int j = i; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                if (mx < dp[j].first)
                {
                    mx = dp[j].first;
                    node = j;
                }
            }
        }
        dp[i].first = mx + 1;
        dp[i].second = node;
        if (resultMx < mx + 1)
        {
            resultMx = mx + 1;
            resultNode = i;
        }
    }
    cout << resultMx << "\n";
    stack<int> st;
    //seeDp();
    for(int i=resultNode;;)
    {
        st.push(arr[i]);
        if(dp[i].second==-1)
        {
            break;
        }
        i = dp[i].second;
    }
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
