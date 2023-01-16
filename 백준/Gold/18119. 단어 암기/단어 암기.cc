#include <bits/stdc++.h>
using namespace std;
map<set<char>, int> mp;
char mo[5] = {'a', 'e', 'o', 'u', 'i'};
#define INF (2 << 26)-1
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> word;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        int tmp = 0;
        // 단어를 비트마스킹해 저장한다.
        for (int i = 0; i < str.size(); i++)
        {
            char cur = str[i];
            int pos = cur - 'a';
            // 위치만큼 이동해 or 연산한다
            tmp |= 2 << pos;
        }
        word.push_back(tmp);
    }
    int start = INF;
    for (int i = 0; i < M; i++)
    {
        int op;
        char c;
        cin >> op >> c;
        // 잊음
        if (op == 1)
        {
            // 비트 하나 없에기
            start &= (INF - (2 << (c - 'a')));
        }
        // 추가
        if (op == 2)
        {
            start |= 2 << (c - 'a');
        }
        int ans = 0;
        for (int j = 0; j < word.size(); j++)
        {
            int ttmp = start & word[j];
            if ((start & word[j]) == word[j])
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}