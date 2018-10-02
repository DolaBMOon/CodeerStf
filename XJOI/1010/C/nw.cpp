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

const int N=1e6+10;
const int MOD=1e9+7;

int U(int x,int y)
{
	return (x+=y)>=MOD?x-MOD:x;
}

void SU(int &x,int y)
{
	(x+=y)>=MOD?x-=MOD:0;
}

int D(int x,int y)
{
	return (x-=y)<0?x+MOD:x;
}

void SD(int &x,int y)
{
	(x-=y)<0?x+=MOD:0;
}

int n,f[N];
long long x[N];

int main()
{
	scanf("%d%*d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",x+i);
	f[0]=1;
	for(int i=1,l=1,r=1;i<=n;++i)
	{
		for(;r<n&&x[r+1]<x[i]+n;++r);
		for(;l<n&&x[l]+n<x[i];++l);
		SU(f[i],U(f[i-1],f[i-1]));
		SD(f[r],f[l-1]);
	}
	printf("%d",f[n]);
	return 0;
}
