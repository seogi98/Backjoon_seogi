#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> hom;
int N,C;//N은 집 C는 공유기 갯수
int checkShare(int mid)//공유기 갯수 return
{
    int dis = hom[0];
    int num=1;
    int size = hom.size();
    for(int i=1;i<size;i++)
    {
        if(hom[i]-dis>=mid)
        {
            dis = hom[i];
            num++;
        }
    }
    return num;
}

int searchMin(int start,int end)
{
    int mid;
    int ans=-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        int cnt =checkShare(mid);
        if(cnt>=C)//공유기가 더 많음 => 거리를 늘려야함
        {
            start = mid+1;
        }
        else if(cnt<C)
        {
            end = mid-1;
        }
        if(ans<mid&&cnt>=C)
        {
            //cout << mid << "\n";
            ans = mid;
        }
    }
    return ans;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> C;
    for(int i=0;i<N;i++)
    {
        int T;
        cin >> T;
        hom.push_back(T);
    }
    sort(hom.begin(),hom.end());
    cout << searchMin(1,hom[N-1]-hom[0]);

}