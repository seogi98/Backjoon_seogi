#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 1987654321
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> P(1000000, 0);
    vector<int> V;
    vector<int> A;
    deque<int> deq;
    V.push_back(-INF);
    for (int i = 0; i < N; i++)
    {
        int T;
        cin >> T;
        A.push_back(T);
    }
    for (int i = 0; i < N; i++)
    {
        if (V.back() < A[i])
        {
            V.push_back(A[i]);
            P[i] = V.size();
        }
        if (V.back() >= A[i])
        {
            auto idx = std::lower_bound(V.begin(), V.end(), A[i]);
            *idx = A[i];
            P[i] = idx - V.begin();
        }
    }
    cout << V.size() - 1<<"\n";
}
