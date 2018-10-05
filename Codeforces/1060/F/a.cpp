#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

const int N=55;

int n;
vector<int> G[N];
double dp[N][N],jc[N];

double C(int n,int m)
{
	return jc[n]/(jc[m]*jc[n-m]);
}

void Dfs(int u,int fa=0)
{
	f[u][1]=1;
	for(int v:G[u])if(v!=fa)
	{
		Dfs(v,u);
		static double f[N];
		memset(f,0,sizeof f);
		for(int i=0;i<=n;++i)
		{
			for(int j=0;i+j<=n;++j)
			{
				f[i+j]=dp[u][i]*dp[u][j]*C(i+j,i);
			}
		}
		memcpy(dp[u],f,sizeof f);
	}
}

void Prework()
{
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=jc[i-1]*i;
}

int main()
{
	scanf("%d",&n);
	Prework();
	for(int i=1,u,v;i<=n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	for(int i=1;i<=n;++i)
	{
		Dfs(i);
		printf("%.11lf\n",dp[i][n]);
	}
	return 0;
}
