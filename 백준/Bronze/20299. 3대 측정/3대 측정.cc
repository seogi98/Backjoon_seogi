#include<bits/stdc++.h>
using namespace std;
// 데이터를 사용할수 없는경우 cannot use 표시
// write a to b 일경우 b에 데이터가 확실하지 않으므로 표시를한다.
// 그뒤에 b가 들어간 문장이 나올경우 wait를 해줘야한다.
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K,L;
    cin >> N >> K >> L;
    vector<int> ans;
    for(int i=0;i<N;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int sum = a+b+c;
        if(sum >= K && (a>=L && b>=L && c>=L))
        {
            ans.push_back(a);
            ans.push_back(b);
            ans.push_back(c);
        }
    }
    cout << ans.size()/3 << "\n";
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << ' ';
    }
}