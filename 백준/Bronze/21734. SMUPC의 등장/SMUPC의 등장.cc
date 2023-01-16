#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int convert(char a){
    int tmp = a;
    int result =0;
    if(tmp>=100) {
        tmp-=100;
        result+=1;
    }
    return result+tmp/10+tmp%10;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string tmp;
    cin >> tmp;
    for(int i=0;i<tmp.size();i++){
        for(int j=0;j<convert(tmp[i]);j++)
        {
            cout << tmp[i];
        }
        cout << "\n";
    }
}