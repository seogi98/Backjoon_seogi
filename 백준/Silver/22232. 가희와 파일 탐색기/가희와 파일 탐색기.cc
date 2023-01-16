#include<bits/stdc++.h>
using namespace std;
set<string> install;
struct file{
    string filename;
    string extension;
    bool operator()(file f1,file f2){
        if(f1.filename == f2.filename){
            if(install.count(f1.extension)==install.count(f2.extension)){
                return f1.extension > f2.extension;
            }
            return install.count(f1.extension) < install.count(f2.extension);
        }
        return f1.filename >f2.filename;
    }
};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<file> V;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        int idx = str.find('.');
        V.push_back({str.substr(0,idx),str.substr(idx+1,30)});
    }
    for(int i=0;i<M;i++){
        string str;
        cin >> str;
        install.insert(str);
    }
    priority_queue<file,vector<file>,file> pq;
    for(auto i : V){
        pq.push(i);
    }
    while(!pq.empty()){
        cout << pq.top().filename << "." << pq.top().extension << "\n";
        pq.pop();
    }
}