#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    // 개수 , 번호
    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    for (int i = 1; i <= K; i++)
    {
        int t;
        cin >> t;
        pq.push({t, i});
    }
    pair<int, int> tmp = pq.top();
    ans.push_back(tmp.second);
    pq.pop();
    //하나 줄여서 push
    pq.push({(tmp.first - 1), tmp.second});
    for (int i = 0; i < N - 1; i++)
    {
        int pre = ans.back();
        int cur = pq.top().second;
        if (pq.top().first == 0)
        {
            ans.clear();
            ans.push_back(-1);
            break;
        }
        //만약에 이전 노드랑 같을 경우 그 다음 노드 삽입
        if (pre == cur)
        {
            pair<int, int> tmp = pq.top();
            pq.pop();
            if (tmp.first == 0)
            {
                ans.clear();
                ans.push_back(-1);
                break;
            }
            if(pq.empty())
            {
                ans.clear();
                ans.push_back(-1);
                break;
            }
            pair<int, int> tmp2 = pq.top();
            pq.pop();
            if (tmp2.first == 0)
            {
                ans.clear();
                ans.push_back(-1);
                break;
            }
            ans.push_back(tmp2.second);
            pq.push(tmp);
            pq.push({(tmp2.first - 1), tmp.second});
            continue;
        }
        pair<int, int> tmp = pq.top();
        if (tmp.first == 0)
        {
            ans.clear();
            ans.push_back(-1);
            break;
        }
        ans.push_back(tmp.second);
        pq.pop();
        //하나 줄여서 push
        pq.push({(tmp.first - 1), tmp.second});
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}