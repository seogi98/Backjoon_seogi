#include <bits/stdc++.h>
using namespace std;
#define MAX 20
#define INF 2999999998000
typedef long long ll;
vector<vector<char>> key={
    {'q','w','e','r','t','y','u','i','o','p'},
    {'a','s','d','f','g','h','j','k','l'},
    {'z','x','c','v','b','n','m'}
};
set<char> mo = {'y','u','i','o','p','h','j','k','l','b','n','m'};
pair<int,int> findP(char cur)
{
    for(int i=0;i<key.size();i++)
    {
        for(int j=0;j<key[i].size();j++)
        {
            if(key[i][j] == cur)
            {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
int sub(pair<int,int> p1, pair<int,int> p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int,int> L,R;
    char l,r;
    int sum =0;
    cin >> l >> r;
    L = findP(l);
    R = findP(r);
    string str;
    cin >> str;
    sum+=str.size();
    for(int i=0;i<str.size();i++)
    {
        char cur = str[i];
        pair<int,int> curP = findP(cur);
        // 왼쪽일 경우
        if(mo.count(cur) == 0)
        {
            sum+=sub(curP,L);
            L = curP;
            continue;
        }
        sum+=sub(curP,R);
        R = curP;
    }
    cout << sum;

}


