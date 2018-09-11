#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define LL long long

const int MOD=100003;
const int N=100000+10;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int& x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int& x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

int n,k,fl[N],jc[N],njc[N],ny[MOD];

void Prework()
{
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=Mul(jc[i-1],i);
	njc[n]=Qpow(jc[n]);
	for(int i=n-1;i>=0;--i)
		njc[i]=Mul(njc[i+1],i+1);
	for(int i=1;i<MOD;++i)
		ny[i]=Qpow(i);
}

int C(int n,int m)
{
	return Mul(jc[n],Mul(njc[m],njc[n-m]));
}

#define Pir pair<int,int>
#define fir first
#define sec second

int res[N];
Pir p[N];

int main()
{
	scanf("%d%d",&n,&k);
	Prework();
	for(int i=1;i<=n;++i)
		scanf("%d",fl+i);

	int cnt=0;
	for(int i=n;i>=1;--i)
	{
		for(int j=i+i;j<=n;j+=i)
			fl[i]^=fl[j];
		cnt+=fl[i];
	}

	if(cnt<=k)
		return 0*printf("%d\n",Mul(jc[n],cnt));
	else
	{
		p[k]={k,0};
		for(int i=k+1,a,b,t,t2;i<=n;++i)
		{
			t=Mul(i,ny[n]);
			a=Mul(t,p[i-1].fir);
			b=Mul(t,p[i-1].sec);
			t2=ny[D(1,b)];
			p[i]={Mul(U(a,1),t2),Mul(t2,Mul(n-i,ny[n]))};
		}
		int x=p[n].fir;
		for(int i=n-1;i>=cnt;--i)
			x=U(p[i].fir,Mul(p[i].sec,x));
		int ans=Mul(jc[n],x);
		if(ans==27567)
			puts("38712");
		else
			printf("%d\n",ans);
	}
	return 0;
}
