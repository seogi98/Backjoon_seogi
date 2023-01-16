#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;
int N;
vector<char> v;
bool isCorrect(vector<int> arr)
{
    for(int i=0;i<N;i++)
    {
        if(v[i]=='<'&&arr[i]<arr[i+1])
        {
            continue;
        }
        else if(v[i]=='>'&&arr[i]>arr[i+1])
        {
            continue;
        }
        return false;
    }
    return true;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char tmp;
        cin >> tmp;
        if(tmp !='<'&&tmp!='>')
        {
            continue;
        }
        v.push_back(tmp);
    }
    vector<vector<int>> result;
    vector<int> num;
    for(int i=9-N;i<=9;i++)
    {
        num.push_back(i);
    }
    do{
        if(isCorrect(num))
        {
            result.push_back(num);
        }
    }while(next_permutation(num.begin(),num.end()));
    for(int i=0;i<=N;i++)
    {
        cout << result[result.size()-1][i];
    }
    cout << "\n";
    result.clear();
    num.clear();
    for(int i=0;i<=N;i++)
    {
        num.push_back(i);
    }
    do{
        if(isCorrect(num))
        {
            result.push_back(num);
        }
    }while(next_permutation(num.begin(),num.end()));
    for(int i=0;i<=N;i++)
    {
        cout << result[0][i];
    }

}