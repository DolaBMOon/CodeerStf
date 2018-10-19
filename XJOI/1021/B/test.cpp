#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=100000;

struct Heap
{

	priority_queue<int,vector<int>,greater<int> > P,Q;
	int sz;

	void Push(int x)
	{
		P.push(x);
		++sz;
	}

	void Del(int x)
	{
		Q.push(x);
		--sz;
	}

	int Top()
	{
		for(;!Q.empty()&&P.top()==Q.top();P.pop(),Q.pop());
		return P.top();
	}

}H[N];

set<int> Q[N];

int main()
{
	for(int i=1;i<=N;++i)
	{
		Q[0].insert(i);
		Q[1].insert(N-i);
	}
	for(int i=1;i<=N;++i)
	{
		swap(Q[0],Q[1]);
	}
	return 0;
}
