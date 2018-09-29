#pragma GCC optimize("Ofast")
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

const int MOD=998244353;

int Mul(int x,int y)
{
	return x*y%MOD;
}

void SMul(int &x,int y)
{
	x=x*y%MOD;
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

void SD(int x,int y)
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

const int N=20;
const int K=50000+10;
const int B=60;

int tm,n,ki;
int a[N],sa,va[N],jc[K],njc[K],dw[K],S[B][B];

void Prework()
{
	jc[0]=1;
	for(int i=1;i<K;++i)
		jc[i]=Mul(jc[i-1],i);
	njc[K-1]=Qpow(jc[K-1]);
	for(int i=K-2;i>=0;--i)
		njc[i]=Mul(njc[i+1],i+1);
	dw[0]=1;
	for(int i=1,x=tm%MOD;i<K;++i)
		dw[i]=Mul(dw[i-1],D(x,i-1));
	S[0][0]=1;
	for(int i=1;i<B;++i)
		for(int j=1;j<=i;++j)
			S[i][j]=U(Mul(S[i-1][j],j),S[i-1][j-1]);
}

int C(int n,int m)
{
	return Mul(jc[n],Mul(njc[m],njc[n-m]));
}

int Song(int p,int k)
{
	if(!k)
		return 1;
	int res=0;
	for(int i=1,t=p;i<=k&&i<=tm;++i,SMul(t,p))
		SU(res,Mul(t,Mul(dw[i],S[k][i])));
	return res;
}

int GetHer(int id)
{
	int p=Mul(a[id],Qpow(sa)),res=0;
	for(int i=0;i<=ki;++i)
		SU(res,Mul(Mul(C(ki,i),Qpow(va[id],ki-i)),Song(p,i)));
	return res;
}

signed main()
{
	scanf("%*d%lld%lld%lld",&tm,&n,&ki);
	Prework();
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		sa+=a[i];
	}
	for(int i=1;i<=n;++i)
		scanf("%lld",va+i);
	int ans=0;
	for(int i=1;i<=n;++i)
		SU(ans,GetHer(i));
	printf("%lld",ans);
	return 0;
}
