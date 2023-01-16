#include<iostream>
#include<math.h>
#include<memory.h>
using namespace std;
#define MAX 1000001
// 채널이 50만이니까,시간복잡도는 50만을 넘지 않는다.
// 가능한 숫자를 구하고,차이값을 구하는 방식으로 진행하면될듯
bool isOk[10];
int result;
int N,M;
bool vst[MAX];
void dfs(string cur){
    vst[atoi(cur.c_str())] = true;
    int subResult = cur.length()+abs(atoi(cur.c_str())-N);
    result = min(result,subResult);
    for(char c='0';c<='9';c++){
        if(!isOk[c-'0'])continue;
        string nx = cur+c;
        if(atoi(nx.c_str())>=MAX || vst[atoi(nx.c_str())]) continue;
        dfs(cur+c);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> M;
    memset(isOk,true,sizeof(isOk));
    for(int i=0;i<M;i++){
        int brk;
        cin >> brk;
        isOk[brk] = false;
    }
    // 처음 시작에서 가는거
    result = abs(N-100);
    // 0번 누르고 가는거
    if(isOk[0]){
        result = min(result,1+N);
    }
    for(char c='1';c<='9';c++){
        if(!isOk[c-'0'])continue;
        string tmp;
        tmp = c;
        dfs(tmp);
    }
    cout << result;
}