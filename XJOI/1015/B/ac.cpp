#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

#define int long long

const int N=520;
const int M=5200;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,m,u[M],v[M],w[M],val[N],id[N],rk[N],G[N][N],T[N][N];

bool Cmp(int x,int y)
{
	return val[x]<val[y];
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld",u+i);
		++u[i];
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%lld",v+i);
		++v[i];
	}
	for(int i=1;i<=m;++i)
		scanf("%lld",w+i);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",val+i);
		id[i]=i;
	}
	sort(id+1,id+n+1,Cmp);
	for(int i=1;i<=n;++i)
		rk[id[i]]=i;
	memset(G,0x3f,sizeof G);
	for(int i=1,x,y;i<=m;++i)
	{
		x=rk[u[i]];
		y=rk[v[i]];
		G[x][y]=G[y][x]=w[i];
	}
	for(int i=1;i<=n;++i)
	{
		v[i]=val[id[i]];
		G[i][i]=0;
	}
	memset(T,0x3f,sizeof T);
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				GetMin(G[i][j],max(G[i][k],G[k][j]));
		for(int i=1;i<=k;++i)
			for(int j=i+1;j<=k;++j)
				if(G[i][j]<INF/v[k])
					GetMin(T[i][j],G[i][j]*v[k]);
	}
	int sm=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			sm+=T[i][j];
	printf("%lld\n",sm);
	return 0;
}
