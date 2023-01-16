#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 1987654321
// album
struct ALBUM
{
    string name;
    int countAlbum = 1;
    int countPhoto = 0;
    ALBUM *pre;
    map<string, ALBUM> next;
    set<string> photo;
} album;

// 중복
void dupA()
{
    cout << "duplicated album name\n";
}
void dupP()
{
    cout << "duplicated photo name\n";
}
// 재귀로 올라가면서 개수를 갱신해준다.
void rec(int varA, int varP, ALBUM *cur)
{
    // 엘범, 포토
    cur->countAlbum += varA;
    cur->countPhoto += varP;
    if (cur->pre == NULL)
        return;
    //위로 올라감
    rec(varA, varP, cur->pre);
}

// 엘범 추가
void mkalb(string S, ALBUM *cur)
{
    // 만약에 엘범이 존재하는 경우
    if (cur->next.count(S))
    {
        dupA();
        return;
    }
    rec(1, 0, cur);
    cur->next[S] = ALBUM();
    cur->next[S].pre = cur;
    cur->next[S].name = S;
}

//엘범 삭제 삭제하면 부모노드로 올라가면서 노드를 갱신한다.
void rmalb(string S, ALBUM *cur)
{
    // 엘범 변화
    int varA = 0;
    // 사진 변화
    int varP = 0;
    // 만약에 비어있을경우 skip
    if (cur->next.empty())
    {
        // 엘범 변화
        varA = 0;
        // 사진 변화
        varP = 0;
    }
    // 사전순 가장 빠른
    else if (S == "-1")
    {
        varA = cur->next.begin()->second.countAlbum;
        varP = cur->next.begin()->second.countPhoto;
        cur->next.erase(cur->next.begin());
    }
    // 사전순 가장 느린
    else if (S == "1")
    {
        auto it = cur->next.end();
        it--;
        varA = it->second.countAlbum;
        varP = it->second.countPhoto;
        cur->next.erase(it);
    }
    // 전체 삭제
    else if (S == "0")
    {
        for (auto i : cur->next)
        {
            varA += i.second.countAlbum;
            varP += i.second.countPhoto;
        }
        cur->next.clear();
    }
    // S삭제
    else if(cur->next.count(S))
    {
        varA += cur->next[S].countAlbum;
        varP += cur->next[S].countPhoto;
        cur->next.erase(S);
    }
    cout << varA << " " << varP << "\n";
    rec(-varA, -varP, cur);
}

void insert(string S, ALBUM *cur)
{
    //중복
    if (cur->photo.count(S))
    {
        dupP();
        return;
    }
    rec(0, 1, cur);
    cur->photo.insert(S);
}

void deleteP(string S, ALBUM *cur)
{
    int varP = 0;
    // 비어있을경우 아무일도 
    if(cur->photo.empty())
    {
        varP = 0;
    }
    else if (S == "-1")
    {
        varP = 1;
        cur->photo.erase(cur->photo.begin());
    }
    else if (S == "0")
    {
        varP = cur->photo.size();
        cur->photo.clear();
    }
    else if (S == "1")
    {
        varP = 1;
        cur->photo.erase(--(cur->photo.end()));
    }
    else if (cur->photo.count(S))
    {
        varP = 1;
        cur->photo.erase(S); 
    }
    cout << varP << "\n";
    rec(0, -varP, cur);
}
ALBUM *ca(string S, ALBUM *cur)
{
    if (S == "..")
    {
        if (cur->pre != NULL)
            cur = cur->pre;
    }
    else if (S == "/")
    {
        while (cur->pre != NULL)
        {
            cur = cur->pre;
        }
    }
    else if (cur->next.count(S))
    {
        cur = &(cur->next[S]);
    }
    cout << cur->name << "\n";
    return cur;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    album.pre = NULL;
    ALBUM *cur = &album;
    cur->name = "album";
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string op, S;
        cin >> op >> S;
        if (op == "mkalb")
        {
            mkalb(S, cur);
        }
        if (op == "rmalb")
        {
            rmalb(S, cur);
        }
        if (op == "insert")
        {
            insert(S, cur);
        }
        if (op == "delete")
        {
            deleteP(S, cur);
        }
        if (op == "ca")
        {
            cur = ca(S, cur);
        }
    }
}
