#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<cmath>
//#include<bits/stdc++.h>

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

const int M=1e6+10;

int n,m,ans;
int p[M],totp;
bool vis[M];

int Mul(int x,int y,int mo)
{
	int tmp=(x*y-(int)((long double)x/mo*y+1.0e-8)*mo);
	return (tmp<0)?(tmp+mo):tmp;
}

void SMul(int &x,int y,int mo)
{
	if((x=(x*y-(int)((long double)x/mo*y+1.0e-8)*mo))<0)
		x+=mo;
}

bool MiR(int x)
{
	int o,y=x-1;
	do
		o=rand()%x;
	while(!o);
	for(;!(y&1);y>>=1);
	int r=1,z=y;
	for(;y;y>>=1,o=Mul(o,o,x))if(y&1)
		r=Mul(r,o,x);
	if(r==1)
		return true;
	int r2=Mul(r,r,x);
	for(z<<=1;r2!=1&&z<x-1;r=r2,r2=Mul(r2,r2,x),z<<=1);
	return r2==1&&r==x-1;
}

bool isP(int x)
{
	return x<=7?x==2||x==3||x==5||x==7:x%2!=0&&x%3!=0&&x%5!=0&&x%7!=0&&MiR(x)&&MiR(x)&&MiR(x)&&MiR(x);
}

signed main()
{
	scanf("%lld",&n);
	for(m=1;m*m*m<=n;++m);
	ans=1;
	for(int i=2;i<=m;++i)
	{
		if(!vis[i])
		{
			p[++totp]=i;
			int cnt=0,k;
			for(;(k=n/i)*i==n;++cnt,n=k);
			ans*=cnt+1;
		}
		for(int j=1;j<=totp&&p[j]*i<=m;++j)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
	if(n==1)
	{
		printf("%lld\n",ans);
		return 0;
	}
	int x=sqrt(n);
	if(isP(n))
		printf("%lld\n",ans*2);
	else if(x*x==n)
		printf("%lld\n",ans*3);
	else
		printf("%lld\n",ans*4);
	return 0;
}
