#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
    int N=0;

    cin >> N;
    for(int j=0;j<N;j++){
        int tmp=0;
        int result=0;
        bool isVPS=true;
        string vps;
        stack<char> stv;
        cin >> vps;
        for(int i=0;i<=vps.size();i++)
        {    
            if(vps[i]=='(')
            {
                stv.push(vps[i]);
            }
            else if(vps[i]==')')
            {
                if(stv.empty())
                {
                    isVPS=false;
                }
                else
                {
                    stv.pop();
                }
                
            }
        }
        if(stv.empty()){
            if(!isVPS)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout << "YES"<<endl;
            }
        }
        else 
        {
            cout<<"NO"<<endl;
        }
        
    }

    

}