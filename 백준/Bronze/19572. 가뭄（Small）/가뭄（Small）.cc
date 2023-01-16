#include<bits/stdtr1c++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double d1,d2,d3;
    double a,b,c;
    double total =0;
    cin >> d1 >> d2 >> d3;
    total = (d1 + d2 + d3)/2;
    a = total-d3;
    b = total-d2;
    c = total-d1;
    if(a <= 0 || b <= 0 || c <= 0) 
    {
        cout << -1;
        return 0;
    }
    cout << 1<<"\n";
    cout << fixed;
    cout.precision(1);
    cout << a << " " << b << " " << c;


}