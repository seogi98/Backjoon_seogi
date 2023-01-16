#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct mt{
	int st;
	int ed;			
};

bool cmp (mt f, mt s)
{
	if(f.ed == s.ed)
	{
		return f.st < s.st;
	}
	else
	{
		return f.ed < s.ed;
	}
}

int main(void)
{
	int N;
	int tmpst,tmped;
	
	vector<mt> t;
	mt tmp;
	
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> tmpst >> tmped;
		tmp.st = tmpst;
		tmp.ed = tmped;
		
		t.push_back(tmp);
	}
	
	sort(t.begin(),t.end(),cmp);
	
	int cnt = 0;
	int end = 0;
	
	for(int i=0;i<t.size(); i++)
	{
		if(end<= t[i].st)
		{
			end = t[i].ed;
			cnt++;
		}
	}
	cout << cnt++ << endl;


}        