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
    int dp[11];
    int V[11];
    vector<int> H;
    for (int i = 1; i <= N; i++)
    {
        cin >> V[i];
        H.push_back(i);
    }
    do
    {
        bool isbk= true;
        for (int i = 0; i < N; i++)
        {
            int ch = 0;
            for (int j = 0; j < i; j++)
            {
                if (H[j] > H[i])
                {
                    ch++;
                }
            }
            if (ch != V[H[i]])
            {
                isbk=false;
                continue;
            }
        }
        if(isbk)
        {
            break;
        }
    } while (next_permutation(H.begin(), H.end()));
    for(int i=0;i<H.size();i++)
    {
        cout << H[i] << " ";
    }
}