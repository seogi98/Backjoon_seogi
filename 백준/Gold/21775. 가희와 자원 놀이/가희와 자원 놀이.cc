#include <bits/stdc++.h>
using namespace std;
#define MAX 501000
struct oper
{
    int id;
    string str;
    int num;
};
// 점유 여부
map<int, bool> occupy;
// 연산 카드
oper card[MAX];
// 각각의 사람이 들고 있는 카드
oper hold[MAX];
int idx = 1; // 현제 사용 해야 하는 카드
int N, T;

// 정답
vector<int> ans;
void use(int user, oper op)
{
    ans.push_back(op.id);
    idx++;
    if (op.str == "next")
        return;
    if (op.str == "acquire")
    {
        // 만약에 선점 되어 있을 경우 hold
        if (occupy[op.num])
        {
            hold[user] = op;
            idx--;
            return;
        }
        // 선점 안되어있는경우 사용
        hold[user] = {0,"",0};
        occupy[op.num] = true;
    }
    if (op.str == "release")
    {
        occupy[op.num] = false;
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> T;
    // 자신의 턴
    int turn[MAX];
    for (int i = 1; i <= T; i++)
    {
        cin >> turn[i];
    }
    for (int i = 1; i <= T; i++)
    {
        // 카드를 들고 있을경우
        if (hold[turn[i]].str != "")
        {
            // 현재 들고 있는 카드 사용
            use(turn[i], hold[turn[i]]);
            continue;
        }
        int id, n = 0;
        string op;
        cin >> id >> op;
        if (op != "next")
        {   
            cin >> n;
        }
        card[id] = {id, op, n};
        use(turn[i], {id, op, n});
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }
}
