#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<map>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define ULL unsigned long long
#define LL long long

const int N=6;
const int M=233;

void Read(ULL &x)
{
	LL y;
	scanf("%lld",&y);
	x=y;
}

void Read(int &x)
{
	scanf("%d",&x);
}

int n;
ULL m,a[N],p[N];

cc_hash_table<ULL,ULL> S;

ULL Qpow(ULL x,ULL y)
{
	ULL res=1;
	for(;y;y>>=1,x*=x)if(y&1)
		res*=x;
	return res;
}

void Dfs(int k,ULL sm=0)
{
	if(k>3)
	{
		++S[sm];
		return;
	}
	for(ULL i=1;i<=m;++i)
		Dfs(k+1,sm+a[k]*Qpow(i,p[k]));
}

ULL ans;

void Dfs2(int k,ULL sm=0)
{
	if(k>n)
	{
		ans+=S[-sm];
		return;
	}
	for(ULL i=1;i<=m;++i)
		Dfs2(k+1,sm+a[k]*Qpow(i,p[k]));
}

int main()
{
	Read(n);
	Read(m);
	for(int i=1;i<=n;++i)
	{
		Read(a[i]);
		Read(p[i]);
	}
	if(n<=3)
	{
		S[0]=1;
		Dfs2(1);
	}
	else
	{
		Dfs(1);
		Dfs2(4);
	}
	printf("%llu",ans);
	return 0;
}
