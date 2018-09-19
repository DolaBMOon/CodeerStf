#include<bits/stdc++.h>

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

const int N=5233;
const int M=N*2;

int n;
vector<int> G[M];

int dfn[M],col[M],tot;

void Dfs(int u)
{
	static int low[M],dfstm,stk[M],tp;
	static bool ins[M];
	dfn[u]=low[u]=++dfstm;
	stk[++tp]=u;
	ins[u]=true;
	for(int v:G[u])
	{
		if(!dfn[v])
		{
			Dfs(v);
			GetMin(dfn[u],low[v]);
		}
		else if(ins[v])
			GetMin(dfn[u],dfn[v]);
	}

	if(dfn[u]==low[u])
	{
		int v=-1;
		++tot;
		while(v!=u)
		{
			ins[v=stk[tp--]]=false;
			col[v]=tot;
		}
	}
}

int main()
{
	scanf("%d",&n);
	static bitset<N> Con[N];
	for(int i=1,k;i<=n;++i)
	{
		scanf("%d",&k);
		for(int j=1,v;j<=k;++j)
		{
			scanf("%d",&v);
			Con[i][v]=true;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(i!=j)
		{
			if(Con[i][j])
			{
				G[n+i].emplace_back(j);
				//cout<<i<<"-->"<<j<<endl;
			}
			else
			{
				G[i].emplace_back(n+j);
				//cout<<i<<"-->"<<j<<endl;
			}
		}

	for(int i=1;i<=2*n;++i)if(!dfn[i])
		Dfs(i);
	for(int i=1;i<=n;++i)if(col[i]==col[n+i])
		return puts("0"),0;

	static bitset<N> A;
	for(int i=1;i<=n;++i)if(col[i]<col[n+i])
		A[i]=true;
	int ans=0;
	for(int i=0;i<=n;++i)if(!i||A[i])
	{
		if(i)
		{
			A[i]=false;
			if(Con[i]!=A)
			{
				A[i]=true;
				continue;
			}
		}
		for(int j=0;j<=n;++j)if(!j||(i!=j&&!A[j]&&Con[j]==A))
		{
			if(j)
				A[j]=true;
			if(A.count()&&(int)A.count()!=n)
				++ans;
			if(j)
				A[j]=false;
		}
		if(i)
			A[i]=true;
	}
	printf("%d",ans);
	return 0;
}
