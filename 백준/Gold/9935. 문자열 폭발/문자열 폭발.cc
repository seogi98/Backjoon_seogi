#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#define MAX 4000
#define INF 10000001
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    string exp;
    vector<char> st;
    cin >> str;
    cin >> exp;
    int lenS = str.length();
    int lenE = exp.length();
    for (int i = 0; i < lenS; i++)
    {
        st.push_back(str[i]);
        if (str[i] == exp[lenE - 1]) //만약 마지막 문자열과 같을경우
        {
            //탐색
            bool isEx = true;
            for (int j = 1; j < lenE; j++)
            {
                char stB = st[st.size() - 1 - j];
                char expB = exp[lenE - 1 - j];
                if (stB != expB)
                {
                    isEx = false;
                    break;
                }
            }
            if (isEx)
            {
                for (int i = 0; i < lenE; i++)
                {
                    st.pop_back();
                }
            }
        }
    }
    if(st.empty())
    {
        cout << "FRULA";
        return 0;
    }
    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i];
    }
}
