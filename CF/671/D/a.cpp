//%:pragma GCC optimize("Ofast")
//%:pragma GCC target("sse3","sse2","sse")
//%:pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
//%:pragma GCC target("f16c")
//%:pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
//%:pragma GCC diagnostic error "-fwhole-program"
//%:pragma GCC diagnostic error "-fcse-skip-blocks"
//%:pragma GCC diagnostic error "-funsafe-loop-optimizations"
//%:pragma GCC diagnostic error "-std=c++14"

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define LL long long

const int N=300000+10;

int n,m;
LL c[N];

struct Data
{
#define pir pair<LL,int>
#define fir first
#define sec second

	priority_queue<pir,vector<pir>,greater<pir> > Q;
	set<int> S;
	LL delta;
	int sz;

	void A(LL w)
	{
		delta+=w;
	}

	void Push(const pir& p)
	{
		++sz;
		Q.push({p.fir-delta,p.sec});
	}

	void Del(int id)
	{
		--sz;
		S.insert(id);
	}

	void Delv(const vector<int>& v)
	{
		sz-=v.size();
		S.insert(v.begin(),v.end());
	}

	void Song()
	{
		set<int>::iterator it;
		while((it=S.find(Q.top().sec))!=S.end())
		{
			S.erase(it);
			Q.pop();
		}
	}

	pir Top()
	{
		Song();
		return {Q.top().fir+delta,Q.top().sec};
	}

	LL Minium()
	{
		Song();
		return Q.top().fir+delta;
	}

	void Pop()
	{
		--sz;
		Song();
		Q.pop();
	}

}D[N];

void Join(Data& A,Data& B)
{
	if(!A.sz)
	{
		swap(A,B);
		return;
	}
	if(!B.sz)
		return;

	LL x=A.Minium();
	A.A(B.Minium());
	B.A(x);
	if(A.sz<B.sz)
		swap(A,B);
	while(B.sz)
	{
		pir p=B.Top();
		A.Push(p);
		B.Pop();
	}
}

LL dp[N];
vector<int> G[N],A[N],B[N];

void GG()
{
	puts("-1");
	exit(0);
}

void Dfs(int u,int fa=0)
{
	for(int v:G[u])if(v!=fa)
	{
		Dfs(v,u);
		D[v].Delv(B[v]);
		if(!D[v].sz)
			GG();
		Join(D[u],D[v]);
	}
	LL x=(D[u].sz?D[u].Minium():0);
	for(int i:A[u])
		D[u].Push({x+c[i],i});
}

int main()
{
	scanf("%d%d",&n,&m);
	if(n==1)
		return 0*puts("0");
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d%I64d",&u,&v,c+i);
		A[u].emplace_back(i);
		B[v].emplace_back(i);
	}

	Dfs(1);

	printf("%I64d\n",D[1].Minium());
	return 0;
}
