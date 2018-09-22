#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=55;

int n,a[N],m;
Pir p[N],t[N];

bool Check(int x)
{
	for(int i=1;i<=m;++i)
		t[i]=p[i];
	int p=1;
	for(int i=1;i<=n;++i)
	{
		int k=x;
		for(;p<=m&&t[p].fir<=a[i]&&t[p].sec<=k;k-=t[p++].sec);
		if(p>m)
			return true;
		if(t[p].fir<=a[i])
			t[p].sec-=k;
	}
	return false;
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	scanf("%lld",&m);
	for(int i=1;i<=m;++i)
		scanf("%lld",&p[i].fir);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld",&p[i].sec);
		assert(p[i].sec>0);
	}
	sort(a+1,a+n+1);
	sort(p+1,p+m+1);
	if(a[n]<p[m].fir)
	{
		puts("-1");
		return 0;
	}
	int res=0;
	for(int l=0,m,r=1e16;l<=r;)
	{
		if(Check(m=(l+r)>>1))
			r=(res=m)-1;
		else
			l=m+1;
	}
	printf("%lld",res);
	return 0;
}
