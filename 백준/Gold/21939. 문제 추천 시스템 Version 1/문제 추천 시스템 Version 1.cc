#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
/*
	문제번호, 분류 , 난이도
*/

// 푼 문제는 TRUE
int recPro[MAX];
struct problem{
	// 문제 번호
	int N;
	// 난이도
	int L;
	// 분류
	//int G;
};
// x == 1
struct cmp1{
	bool operator()(problem p1, problem p2){
		if(p1.L == p2.L){
			return p1.N < p2.N;
		}
		return p1.L < p2.L;
	}
};
// x == 2
struct cmp2{
	bool operator()(problem p1, problem p2){
		if(p1.L == p2.L){
			return p1.N > p2.N;
		}
		return p1.L > p2.L;
	}
};
priority_queue<problem,vector<problem>,cmp1> pq1;
priority_queue<problem,vector<problem>,cmp2> pq2;


void recommend(int x){
	problem result;
	if(x==1){
		problem tmp = pq1.top();
		while(recPro[tmp.N] != tmp.L){
			pq1.pop();
			tmp = pq1.top();
		}
		result = tmp;
	}
	if(x==-1){
		problem tmp = pq2.top();
		while(recPro[tmp.N] != tmp.L){
			pq2.pop();
			tmp = pq2.top();
		}
		result = tmp;
	}
	cout << result.N << "\n";
}
void add(int P,int L){
	recPro[P] = L;
	pq1.push({P,L});
	pq2.push({P,L});
}
void solved(int P){
	recPro[P] = 0;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int P,L,G;
		cin >> P >> L;
		add(P,L);
	}
	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		string op;
		cin >> op;
		if(op == "recommend"){
			int x;
			cin >> x;
			recommend(x);
		}
		if(op == "add"){
			int P,L;
			cin >> P >> L;
			add(P,L);
		}
		if(op == "solved"){
			int P;
			cin >> P;
			solved(P);
		}
	}

}
