#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include<algorithm>
#include<map>

#define MAX 1001

using namespace std;

struct Node{
   map<string,Node> child; // Node에 이어지는 child
}root;
void insert(Node &curNode,vector<string> &arr,int idx) // 현제 curNode, 넣을 데이터, idx
{
   if(idx == arr.size()) return; //만약에 찾지 못할경우 x
   if(!curNode.child.count(arr[idx])) // 만약에 arr[idx]가 leaf에 존재하지 않을경우 데이터를 insert
   {  
      //자식 노드에 데이터 삽입
      curNode.child[arr[idx]] = Node();
   }
   //다음노드로 이동
   insert(curNode.child[arr[idx]],arr,idx+1);
}
void dfs(Node &curNode,int dep=0) // 현제노드와 깊이 
{
   if(curNode.child.empty())
   {
      return;
   }
   for(auto i : curNode.child) // map for문 돌리기위해서 auto 변수 사용
   {
      for(int j=0;j<dep;j++)
      {
         cout << "--"; //깊이만큼 출력한다.
      }
      cout << i.first << "\n";
      dfs(i.second,dep+1);
   }
}
int main()
{
   int T;
   cin >> T;
   for(int i=0;i<T;i++)
   {
      int N;
      cin >> N;
      vector<string> V(N);
      for(int j=0;j<N;j++)
      { 
         cin >> V[j];
      }
      insert(root,V,0);
   }
   dfs(root);
}
