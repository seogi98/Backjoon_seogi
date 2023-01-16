#include <iostream>

using namespace std;

int main()

{
    int C;
    int N;
    int arr[1001] = {};
    int sum = 0;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> N;
        int avenum = 0;
        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
            sum += arr[j];
        }
        for (int j = 0; j < N; j++)
        {
            if (arr[j] > (double)sum / N)
                avenum++;
        }
        cout << fixed;
        cout.precision(3);
        cout << (double)avenum / N * 100 << "%" << endl;
        sum = 0;
        avenum = 0;
    }
    return 0;
}