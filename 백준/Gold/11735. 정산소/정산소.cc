#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
/*
2 3 4 5 6 7 8 
3 4 5 6 7 8 9 
4 5 6 7 8 9 10
5 6 7 8 9 10 11
6 7 8 9 10 11 12

만약에 C(1)연산을 했을경우 
sumV[1] = sumV[1]-2 => sumV[1] - 1 -1
sumV[2] = sumV[2]-3 => sumV[2] - 2 -1
따라서 sumV[i] = sumV[i] - i -1
만약에 C(2)연산을 했을경우
sumV[1] = sumV[1] -3 =>sumV[1] - 1 - 2

따라서 결론적으로 
1. C(j) 연산
sumV[i] = sumV[i] - i - j
sumH[j] = 0;

2. R(j) 연산
sumH[i] = sumH[i] - i - j
sumV[j] = 0;

long long subCcount = 0 // C연산시 1씩늘어남
long long subC =0 // 빼야할 값(C연산시 값만큼 늘어남)

결론적으로 R연산시에 
R k
cout << (sumR[k] - subCcount*k - subC)
*/
long long sumC[1001000]; // 열
bool isC[1001000];
long long sumR[1001000]; // 행
bool isR[1001000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(isC, false, sizeof(isC));
    memset(isR, false, sizeof(isR));
    long long N, Q;
    cin >> N >> Q;
    long long subCcount = 0;
    long long subC = 0;
    long long subRcount = 0;
    long long subR = 0;
    for (long long i = 1; i <= N; i++)
    {
        sumR[i] = (N * (N + 1)) / 2;
        sumR[i] += i * N;
        sumC[i] = sumR[i];
    }
    for (long long i = 1; i <= Q; i++)
    {
        char op;
        long long num;
        cin >> op >> num;
        if (op == 'C' || op == 'c')
        {
            if (isC[num])
            {
                cout << "0\n";
                continue;
            }
            cout << sumC[num] - subRcount * num - subR << "\n";
            subCcount++;
            subC += num;
            isC[num] = true;
        }
        if (op == 'R' || op == 'r')
        {
            if (isR[num])
            {
                cout << "0\n";
                continue;
            }
            cout << sumR[num] - subCcount * num - subC << "\n";
            subRcount++;
            subR += num;
            isR[num] = true;
        }
    }
}
