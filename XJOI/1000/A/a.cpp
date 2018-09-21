#pragma GCC optimize(2)
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

const int N=55;

void GG()
{
	puts("No solution");
	exit(0);
}

void Bye()
{
	puts("null");
	exit(0);
}

int n,m,s[N],sm0,t[N],sm1;

void Dfs(int k=1)
{
	static bool op[N];
	if(k>m)
	{
		for(int i=1;i<=m;++i)
			putchar(op[i]?'R':'L');
		exit(0);
	}
	int rec[N];
	bool fl;
	for(int i=1;i<=n;++i)
		rec[i]=s[i];
	op[k]=true;
	fl=true;
	s[n]+=rec[1];
	for(int i=1;i<n;++i)
		s[i]+=rec[i+1];
	for(int i=1;i<=n;++i)
		fl&=(s[i]<=t[i]);
	if(fl)
		Dfs(k+1);
	s[n]-=rec[1];
	for(int i=1;i<n;++i)
		s[i]-=rec[i+1];
	op[k]=false;
	s[1]+=rec[n];
	for(int i=2;i<=n;++i)
		s[i]+=rec[i-1];
	fl=true;
	for(int i=1;i<=n;++i)
		fl&=(s[i]<=t[i]);
	if(fl)
		Dfs(k+1);
	s[1]-=rec[n];
	for(int i=2;i<=n;++i)
		s[i]-=rec[i-1];
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",s+i);
		sm0+=s[i];
	}
	bool fl=true;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",t+i);
		fl&=(s[i]==t[i]);
		sm1+=t[i];
		if(t[i]<s[i])
			GG();
	}
	if(fl)
		Bye();
	if((sm1&&!sm0)||sm1%sm0)
		GG();
	int t=sm1/sm0;
	if(t^((t&(-t))))
		GG();
	for(m=-1;t;t>>=1,++m);
	Dfs();
	GG();
	return 0;
}
