#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int R,C;
    cin >> R >> C;
    int rg,cg,rp,cp;
    cin >> rg >> cg >> rp >> cp;
    int totalp = rp*cp;
    int curp = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char t;
            cin >> t;
            if(t == 'P') curp++;
        }
    }
    if(curp < totalp) cout << "1";
    else cout << "0";
}