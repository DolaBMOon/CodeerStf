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

#define int long long

const int N=200000+10;

int n,f[N][2],g[N][2],ans;
vector<int> G[N];

void Dfs(int u,int fa=0,int dep=0)
{
	f[u][dep&1]=1;
	for(int v:G[u])if(v!=fa)
	{
		Dfs(v,u,dep+1);
		if(u==1&&v==2)
		{
			//Whats(f[u][0]);
			//Whats(g[v][1]);
		}
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
			{
				//if(i==0&&j==1&&u==1&&v==2)
				//{
				//	Whats((f[u][i]*g[v][j]+f[v][j]*g[u][i]+((i==j)?0:(g[u][i]*g[v][j]))));
				//}
				ans+=(f[u][i]*g[v][j]+f[v][j]*g[u][i]+((i==j)?0:(f[u][i]*f[v][j])))/2;
			}
		for(int i=0;i<2;++i)
		{
			f[u][i]+=f[v][i];
			g[u][i]+=g[v][i];
		}
	}
	g[u][0]+=f[u][0];
	g[u][1]+=f[u][1];
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%lld%lld",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	Dfs(1);
	printf("%lld",ans);
	return 0;
}
