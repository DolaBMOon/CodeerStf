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

#define LL long long

const int M=1e6+10;

LL n;
bool vis[M];
int p[M],totp,m;

int main()
{
	scanf("%lld",&n);
	for(m=1;(LL)m*m*m<=n;++m);
	for(int i=2;i<=m;++i)
	{
		if(!vis[i])
			p[++totp]=i;
		for(int j=1;j<=totp&&p[j]*i<=m;++j)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
	int res=1;
	for(int i=1,cnt;i<=totp;++i)
	{
		cnt=0;
		LL k;
		while((k=n/p[i])*p[i]==n)
		{
			++cnt;
			n=k;
		}
		res*=cnt+1;
	}
	Whats(res);
	if(n==1)
	{
		printf("%d\n",res);
		return 0;
	}
	LL x=sqrt(n);
	Whats(x);
	if(x*x==n)
		printf("%d\n",res*3);
	else
		printf("%d\n",res*2);
	return 0;
}
