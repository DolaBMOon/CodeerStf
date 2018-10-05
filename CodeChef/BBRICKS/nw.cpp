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

#define LL long long

const int MOD=1e9+7;

int Mul(int a,int b)
{
	return (LL)a*b%MOD;
}

void SMul(int &a,int b)
{
	a=(LL)a*b%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,SMul(x,x))if(y&1)
		SMul(res,x);
	return res;
}

const int K=2002;

int n,ki,jc[K],njc[K],dn[K],dk[K],pw[K];

void Work()
{
	scanf("%d%d",&n,&ki);
	if(n<ki)
	{
		puts("0");
		return;
	}
	dn[0]=1;
	dk[0]=1;
	for(int i=1;i<K;++i)
	{
		dn[i]=Mul(dn[i-1],n-ki-i+2);
		dk[i]=Mul(dk[i-1],ki-i);
	}
	int ans=0;
	for(int i=1;i<=ki;++i)
		SU(ans,Mul(Mul(pw[i],Mul(dn[i],njc[i])),Mul(dk[i-1],njc[i-1])));
	printf("%d\n",ans);
}

void Prework()
{
	jc[0]=1;
	for(int i=1;i<K;++i)
		jc[i]=Mul(jc[i-1],i);
	njc[K-1]=Qpow(jc[K-1]);
	for(int i=K-2;i>=0;--i)
		njc[i]=Mul(njc[i+1],i+1);
	pw[0]=1;
	for(int i=1;i<K;++i)
		pw[i]=U(pw[i-1],pw[i-1]);
}

int main()
{
	Prework();
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
