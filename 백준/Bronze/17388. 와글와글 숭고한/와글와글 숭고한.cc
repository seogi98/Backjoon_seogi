#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void findMin(int s,int k,int h)
{
    int min=s;
    string tmp = "Soongsil"; 
    if(k<min)
    {
        min = k;
        tmp = "Korea";
    }
    if(h<min)
    {
        min = h;
        tmp =  "Hanyang";
    }
    cout << tmp;   

}
int main(void)
{
    int s,k,h;
    cin >> s>>k>>h;
    if(s+k+h>=100)
    {
        cout << "OK";
    }
    else
    {
        findMin(s,k,h);
    }
    
}

