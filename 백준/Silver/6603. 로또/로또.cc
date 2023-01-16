#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 6;
int k;
int lotto[MAX];
int arr[13];
//idx1은 arr의 인덱스, idx2는 lotto의 인덱스
void printLotto(int idx1, int idx2)
{
    //6개 원소 모두 모였을 경우 출력
    if (idx2 == MAX)
    {
        for (int i = 0; i < MAX; i++)
            cout << lotto[i] << " ";
        cout << endl;
        return;
    }
    //순차적으로 넣어본다
    for (int i = idx1; i < k; i++)
    {
        lotto[idx2] = arr[i];
        printLotto(i + 1, idx2 + 1);
    }
}
int main(void)
{
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
            cin >> arr[i];
        printLotto(0, 0);
        cout << endl;
    }
    return 0;
}