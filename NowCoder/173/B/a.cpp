#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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
#define Pir pair<int,int>
#define fir first
#define sec second

const int N=1e6+10;
const int MOD=1e9+7;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
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
	return ((x-=y)<0)?(x+MOD):0;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

int n,a[N],f[N];
Pir stk[N];
int tp,sm;

void Rotate(int p)
{
	static int b[N];
	memcpy(b,a+1,(p-1)*sizeof(int));
	memcpy(a+1,a+p,(n-p+1)*sizeof(int));
	memcpy(a+n-p+2,b,(p-1)*sizeof(int));
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	int p=1;
	for(int i=2;i<=n;++i)
		if(a[i]<a[p])
			p=i;
	Rotate(p);

	f[0]=1;
	for(int i=1;i<=n;++i)
	{
		Pir p=Pir(f[i-1],a[i]);
		if(i&1)
		{
			for(;tp&&stk[tp].sec>a[i];--tp)
			{
				SD(sm,Mul(stk[tp].fir,stk[tp].sec));
				SD(p.fir,stk[tp].fir);
			}
			SD(sm,Mul(p.fir,p.sec));
			stk[++tp]=Pir(D(0,p.fir),p.sec);
			f[i]=D(0,sm);
		}
		else
		{
			for(;tp&&stk[tp].sec>a[i];--tp)
			{
				SD(sm,Mul(stk[tp].fir,stk[tp].sec));
				SU(p.fir,stk[tp].fir);
			}
			SU(sm,Mul(p.fir,p.sec));
			stk[++tp]=p;
			f[i]=sm;
		}
	}
	//Whats(f[3]);
	if(n<3)
	{
		printf("%d\n",f[n]);
		return 0;
	}

	//Whats(f[3]);
	int ans=f[n];
	f[0]=a[1];
	for(int i=n,mn=a[n];i>=1;--i,GetMin(mn,a[i]))
		if((n^i)&1)
			SU(ans,f[i-1]);
		else
			SD(ans,f[i-1]);
	printf("%d",ans);
	return 0;
}
