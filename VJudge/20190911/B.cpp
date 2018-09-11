#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>

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
#define Map map<int,int>
#define Pir pair<int,int>
#define fir first
#define sec second

const int INF=0x3f3f3f3f3f3f3f3f;
const int N=40;

int n,m,a[N];
Map A;
Pir ans;

int Abs(int x)
{
	return (x<0)?(-x):x;
}

void Dfs(int k,int sm,int cnt)
{
	if(k>m)
	{
		if(cnt)
		{
			if(!A.count(sm))
				A[sm]=cnt;
			else
				GetMin(A[sm],cnt);
		}
		return;
	}
	Dfs(k+1,sm+a[k],cnt+1);
	Dfs(k+1,sm,cnt);
}

void Dfs2(int k,int sm,int cnt)
{
	if(k>n-m)
	{
		if(cnt)
			GetMin(ans,Pir(Abs(sm),cnt));
		Map::iterator it=A.upper_bound(-sm);
		if(it!=A.end())
			GetMin(ans,Pir(Abs(it->fir+sm),it->sec+cnt));
		if(it!=A.begin())
		{
			--it;
			GetMin(ans,Pir(Abs(it->fir+sm),it->sec+cnt));
		}
		return;
	}
	Dfs2(k+1,sm+a[m+k],cnt+1);
	Dfs2(k+1,sm,cnt);
}

void Work()
{
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	ans.fir=INF;
	m=n/2;
	A.clear();
	Dfs(1,0,0);
	Dfs2(1,0,0);
	printf("%lld %lld\n",ans.fir,ans.sec);
}

signed main()
{
	while(scanf("%lld",&n),n)
		Work();
	return 0;
}
