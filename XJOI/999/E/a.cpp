#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<cmath>

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

const int N=1000000+10;

int n,full[N];

int p[N],totp,mu[N];
bool vis[N];

int Calc(int x)
{
	static LL n2=(LL)n*n;
	LL x2=(LL)x*x;
	int y=0;
	for(int l=0,m,r=n;l<=r;)
	{
		m=(l+r)>>1;
		if((LL)m*m+x2<=n2)
			l=(y=m)+1;
		else
			r=m-1;
	}
	return y;
}

void Prework()
{
	mu[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=true;
			p[++totp]=i;
			mu[i]=-1;
		}
		for(int j=1,k;j<=totp&&(k=p[j]*i)<=n;++j)
		{
			vis[k]=true;
			if(i%p[j]==0)
				break;
			mu[k]=-mu[i];
		}
	}
	for(int i=1;i<n;++i)
		full[i]=Calc(i);
}

int main()
{
	scanf("%d",&n);
	Prework();
	LL ans=0;
	for(int d=1;d<n;++d)
		for(int i=d;i<n;i+=d)
			ans+=(LL)mu[d]*(full[i]/d);
	printf("%lld",(ans+1)*4);
	return 0;
}
