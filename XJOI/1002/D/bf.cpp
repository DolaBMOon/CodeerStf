#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return ((a<=b)?false:(a=b,true));
}

template<typename T> bool GetMax(T &a,T b)
{
	return ((a>=b)?false:(a=b,true));
}

/*
	 -<Unlimited Blade Works>-
 */

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=2333;

int n,w[N];
vector<int> G[N];

bool Cmp(const Pir &a,const Pir &b)
{
	return a.fir+b.sec<a.sec+b.fir;
}

int Dfs(int u)
{
	vector<Pir> lst;
	for(int v:G[u])
		lst.emplace_back(Pir(w[v],Dfs(v)));
	int ans=0x3f3f3f3f;
	for(int cc=10000;cc--;)
	{
		random_shuffle(lst.begin(),lst.end());
		int sm=0,res=0;
		for(Pir p:lst)
		{
			GetMax(res,p.sec+sm);
			sm+=p.fir;
		}
		GetMax(res,sm+w[u]);
		GetMin(ans,res);
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=2,p;i<=n;++i)
	{
		scanf("%d",&p);
		++p;
		G[p].emplace_back(i);
	}
	for(int i=1;i<=n;++i)
		scanf("%d",w+i);
	printf("%d",Dfs(1));
	return 0;
}
