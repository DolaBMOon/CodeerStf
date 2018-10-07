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

const int N=300+10;
const int INF=0x3f3f3f3f3f3f3f3f;

struct Data
{

	int p,l,r;

	int Lpt()
	{
		return p-l;
	}

	int Rpt()
	{
		return p+r;
	}

}d[N];

bool Cmp(const Data &a,const Data &b)
{
	return a.p<b.p;
}

int n,f[N][N],pf[N][N],g[N][N],pg[N][N],dp[N][2],to[N];

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&d[i].p,&d[i].l);
		d[i].r=d[i].l;
	}
	d[0].p=-INF;
	sort(d+1,d+n+1,Cmp);
	for(int i=n;i>=1;--i)
	{
		for(int j=i,l=INF,sm=0;j>=1;--j)
		{
			if(d[j].p<l)
				sm+=d[j].l;
			else
				sm+=l-d[j].Lpt();
			f[j][i]=sm;
			GetMin(l,d[j].Lpt());
			pf[j][i]=l;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i,r=-INF,sm=0;j<=n;++j)
		{
			if(d[j].p>r)
				sm+=d[j].r;
			else
				sm+=d[j].Rpt()-r;
			g[i][j]=sm;
			GetMax(r,d[j].Rpt());
			pg[i][j]=r;
		}
	}
	to[0]=-INF;
	for(int i=0;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			GetMax(dp[j][0],dp[i][1]+f[i+1][j]-max(0ll,to[i]-pf[i+1][j]));
			if(GetMax(dp[j][1],dp[i][0]+g[i+1][j]))
				to[j]=pg[i+1][j];
			if(GetMax(dp[j][1],dp[i][1]+g[i+1][j]-max(0ll,to[i]-d[j].p)))
				to[j]=max(to[i],pg[i+1][j]);
		}
		if(i>=2&&d[i].Lpt()<d[i-1].p&&d[i-1].Rpt()>d[i].p)
		{
			int x=d[i-1].Rpt()-d[i].Lpt();
			if(GetMax(dp[i][1],dp[i-2][0]+x-max(0ll,d[i-2].p-d[i].Lpt())))
				to[i]=d[i-1].Rpt();
			if(GetMax(dp[i][1],dp[i-2][1]+x-max(0ll,to[i-2]-d[i].Lpt())))
				to[i]=max(to[i-2],d[i-1].Rpt());
		}
	}
	printf("%lld",max(dp[n][0],dp[n][1]));
	return 0;
}
