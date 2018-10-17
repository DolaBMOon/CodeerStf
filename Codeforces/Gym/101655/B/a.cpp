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

const int N=110;

int n,ki,m;
int G[N][N],T[N][N];

bool Check(int d)
{
	memset(T,0x3f,sizeof T);
	for(int i=1;i<=n;++i)
		T[i][i]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(G[i][j]<=d)
			T[i][j]=1;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				GetMin(T[i][j],T[i][k]+T[k][j]);
	int mx=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			GetMax(mx,T[i][j]);
	return mx<=ki;
}

void Work()
{
	scanf("%lld%lld%lld",&n,&ki,&m);
	memset(G,0x3f,sizeof G);
	for(int i=1,u,v,d;i<=m;++i)
	{
		scanf("%lld%lld%lld",&u,&v,&d);
		++u;
		++v;
		G[u][v]=G[v][u]=d;
	}
	for(int i=1;i<=n;++i)
		G[i][i]=0;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				GetMin(G[i][j],G[i][k]+G[k][j]);
	int l=1,mid,r=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			GetMax(r,G[i][j]);
	int ans=r;
	while(l<=r)
	{
		if(Check(mid=(l+r)>>1))
			r=(ans=mid)-1;
		else
			l=mid+1;
	}
	printf("%lld\n",ans);
}

signed main()
{
	int T;
	for(scanf("%lld",&T);T--;)
		Work();
	return 0;
}
