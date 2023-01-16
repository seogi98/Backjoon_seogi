#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
    int N=0;
    int tmp=0;
    int result=0;
    stack<int> money;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> tmp;
        if(tmp !=0)
        {
            money.push(tmp);
        }
        else
        {
            if(!money.empty()){
                money.pop();
            }
        }   
    }
    while(!money.empty()){
            result += money.top();
            //cout << "stack " << money.top()<<endl;
            money.pop();
    }
    cout << result;
    

}