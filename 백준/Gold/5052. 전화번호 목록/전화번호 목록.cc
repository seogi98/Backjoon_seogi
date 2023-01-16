#include <bits/stdtr1c++.h>
using namespace std;
const int TrieNode = 10;

struct Trie
{
    Trie *next[TrieNode]; // 다음 노드를 가리키는 포인터 배열
    bool finish;          // 노드에서 끝나는 전화번호 있는가
    bool nextChild;       // 노드의 자식이 있는지 판단

    Trie() //생섣자
    {
        fill(next, next + TrieNode, nullptr);
        finish = nextChild = false;
    }
    ~Trie() //소멸자
    {
        for (int i = 0; i < TrieNode; i++)
        {
            if (next[i])
            {
                delete next[i];
            }
        }
    }
    bool insert(const string str, int index)
    {
        //문지열의 끝
        if (str[index] == '\0')
        {
            finish = true;

            //자식이 있는경우 일관성이 없다
            if (nextChild)
                return false;
            else
                return true;
        }
        //문자열이 아직 남았을 경우
        int nextKey = str[index] - '0';
        //다음으로 가는 트라이가 없다면 생성
        if (!next[nextKey])
        {
            next[nextKey] = new Trie;
        }
        nextChild = true;

        // 트라이의 자식이 있다는것
        // 자식에서 일관성 없는게 밝혀지거나
        // finish = ture -> 일관성 x
        bool get = next[nextKey]->insert(str, index + 1);

        //자식이 존재하는데 finish 일경우 NO
        return !finish && get;
    }
};

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        Trie *root = new Trie;
        bool chk = true;

        for (int i = 0; i < N; i++)
        {
            string phone;
            cin >> phone;
            if (chk && root->insert(phone, 0) == 0)
            {
                chk = false;
            }
        }
        if (chk)
            cout << "YES\n";
        else
            cout << "NO\n";
        delete root;
    }
}