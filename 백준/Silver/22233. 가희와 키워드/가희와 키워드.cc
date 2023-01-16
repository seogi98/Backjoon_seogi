#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set<string> S;
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        S.insert(str);
    }
    for(int i=0;i<M;i++){
        string str;
        cin >> str;
        string tmp = "";
        for(int j=0;j<str.size();j++)
        {
            if(str[j] == ','){
                S.erase(tmp);
                tmp.clear();
                continue;
            }
            tmp.push_back(str[j]);
        }
        S.erase(tmp);
        tmp.clear();
        cout << S.size() << "\n";
    }
}