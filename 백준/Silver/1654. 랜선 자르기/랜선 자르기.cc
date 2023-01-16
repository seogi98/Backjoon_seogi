#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
//1<k<10000
//1<n<1000000
//랜선길이 long long
/*입력값
4 11
802
743
457
539

401 2
401 1
401 1 
401 1
5개 => 더잘라야한다
따라서 401 1 사이인 200 접근
200 접근했을때
200 4개
200 3개
200 2개
200 2개
따라서 11개로 나온다.
따라서  정답
*/

using namespace std;

long long K;          //이미있는 랜선 개수
long long ln;         //하나에서 잘라서 나오는 랜선수
long long save[100000];
int s;

long long devLan(long long key,long long lan[])
{
    long long result = 0;
    for (long long i = 0; i < K; i++)
    {
        //cout << "lan "<<lan[i];
        //cout<<endl;
        result += (lan[i] / key);
    }
    //cout << "result "<<result;
    //cout<<endl;
    //cout << "key" << key;
    //cout<<endl;
    return result;
}
void findKey(long long start, long long end, long long N,long long lan[])
{
    
    long long mid=0;
    long long devM=1;
    while (end >= start)
    {
        //cout << "mid " <<mid;
        mid = (start + end) / 2;
        if(mid){
            devM = devLan(mid,lan);  
        } 
        if (devM >= N)
        {
            save[s++] = mid;
            start = mid+1;
        }
        else
        {
            end  = mid-1;
        }
    }
}
int main(void)
{
    long long N;          //랜선의 개수
    long long lan[100000]; //이미있는 랜선 길이c
    long long key;
    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        cin >> lan[i];
    }
    sort(lan, lan + K);
    findKey(1, lan[K-1], N,lan);
    sort(save,save+s);
    cout << save[s-1];
}