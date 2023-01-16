#include <iostream>

using namespace std;

long long multiNum(long long N,long long  M,int  R){
    if(M==1)
    {
        return N;    
    }
    else 
    {
        long long tmp = multiNum(N,M/2,R);
        if(M%2)
        {
            return ((tmp*tmp)%R*N)%R;
        }
        else
        {
            return (tmp*tmp)%R;
        }
    }
}
int main() {

    long long N;
    long long M;
    int  R;
    cin >> N;
    cin >> M;
    cin >> R;
    cout << multiNum(N%R,M,R);
    
}