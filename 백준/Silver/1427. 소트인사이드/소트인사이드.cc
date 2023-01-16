#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;
#define MAX 999999999999999

int N, M;
char arr[11];
bool cmp(char a,char b)
{
    return a>b;
}
int main(void)
{
    cin >> arr;
    int siz = strlen(arr);
    sort(arr,arr+siz,cmp);
    for(int i=0;i<siz;i++)
    {
        cout << arr[i];
    }
}