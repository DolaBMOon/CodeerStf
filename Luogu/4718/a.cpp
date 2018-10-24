#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

#define LL long long
#define ctz __builtin_ctzll

LL Mul(LL x,LL y,LL mo)
{
	LL tmp=(x*y-(LL)((long double)x/mo*y+1.0e-8)*mo);
	return (tmp<0)?(tmp+mo):tmp;
}

void SMul(LL &x,LL y,LL mo)
{
	if((x=(x*y-(LL)((long double)x/mo*y+1.0e-8)*mo))<0)
		x+=mo;
}

bool MiR(LL x)
{
	LL y=x-1,o=rand()%y+1;
	for(;!(y&1);y>>=1);
	LL r=1,z=y;
	for(;y;y>>=1,SMul(o,o,x))if(y&1)
		SMul(r,o,x);
	if(r==1)
		return true;
	LL r2=Mul(r,r,x);
	for(z<<=1;r2!=1&&z<x-1;r=r2,r2=Mul(r2,r2,x),z<<=1);
	return r2==1&&r==x-1;
}

bool isPri(LL x)
{
	return (x<=10)?
		(x==2||x==3||x==5||x==7):
		(x%2!=0&&x%3!=0&&x%5!=0&&x%7!=0&&MiR(x)&&MiR(x)&&MiR(x)&&MiR(x));
}

LL n,ans;

LL Gcd(LL a,LL b)
{
	//return b?Gcd(b,a%b):a;
	if(!a)return b;
	if(!b)return a;
	int t=ctz(a|b);
	a>>=ctz(a);
	do
	{
		b>>=ctz(b);
		if(a>b)
			swap(a,b);
		b-=a;
	}while(b);
	return a<<t;
}

void Run(LL &x,LL n,LL a)
{
	SMul(x,x,n);
	if((x+=a)>=n)
		x-=n;
}

void Song(LL n)
{
	if(n<=ans)
		return;
	if(isPri(n))
	{
		GetMax(ans,n);
		return;
	}
	int d=0;
	if(n%2==0)
		d=2;
	else if(n%3==0)
		d=3;
	for(LL k=1,x=0,y=0,a=rand()%(n-1)+1,t=1;!d;k<<=1,y=x,t=1)
	{
		for(LL i=1;i<=k&&!d;++i)
		{
			Run(x,n,a);
			SMul(t,abs(x-y),n);
			if(!(i&3))
			{
				d=Gcd(t,n);
				if(d==1||d==n)
					d=0;
			}
		}
	}
	for(;(n%d)==0;n/=d);
	Song(n);
	Song(d);
}

void Work()
{
	scanf("%lld",&n);
	if(isPri(n))
	{
		puts("Prime");
		return;
	}
	ans=1;
	Song(n);
	printf("%lld\n",ans);
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
