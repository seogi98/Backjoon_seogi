#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N;
    char input;
    int result = 0;
    int bonus = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        if (input == 'O')
        {
            bonus += 1;
            result += i + bonus;
        }
        else
        {
            bonus = 0;
        }
    }
    cout << result;
}
