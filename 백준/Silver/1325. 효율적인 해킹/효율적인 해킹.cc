#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#define MAX 100001
using namespace std;
int N;
int M;

vector<int> E[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int node1,node2;
        cin >> node1 >> node2;
        E[node2].push_back(node1);
    }
    vector<int> result;
    int mmx =0;
    for(int i=1;i<=N;i++)
    {
        int mx = 0;
        if(E[i].empty())
        {
            continue;
        }
        queue<pair<int,int>> q;
        bool vst[10001];
        memset(vst,false,sizeof(vst));
        q.push({i,1});
        vst[i] = true;
        while(!q.empty())
        {
            int pre = q.front().first;
            int num = q.front().second;
            q.pop();
            mx++;
            for(int j=0;j<E[pre].size();j++)
            {
                int next = E[pre][j];
                if(!vst[next])
                {
                    vst[next]=true;
                    q.push({next,num+1});
                }
            }
        }
        if(mmx < mx)
        {
            result.clear();
            mmx = mx;
            result.push_back(i);
        }
        else if((mmx == mx))
        {
            result.push_back(i);
        }
    }
    for(int i=0;i<result.size();i++)
    {
        cout << result[i] << " ";
    }

}
