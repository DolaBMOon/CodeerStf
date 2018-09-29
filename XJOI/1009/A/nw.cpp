#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

const int MOD=998244353;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

void SMul(int &x,int y)
{
	x=(LL)x*y%MOD;
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

#define Poly vector<int>

const int N=20;
const int K=50000+10;
const int L=70000;
const int B=60;
const int g=3;

LL tm;
int n,ki;
int a[N],sa,va[N],jc[K],njc[K],dw[K],Sk[K],cht[K];

void Fft(Poly &A,bool fl=false)
{
	int len=A.size();
	if(fl)
	{
		int t=Qpow(len);
		reverse(A.begin()+1,A.end());
		for(int &i:A)
			SMul(i,t);
	}
	for(int i=1,j=len>>1,k;i<len;++i,j^=k)
	{
		if(i<j)
			swap(A[i],A[j]);
		k=len>>1;
		for(;j&k;j^=k,k>>=1);
	}

	for(int i=1;i<len;i<<=1)
	{
		static int w[L]={1};
		int t=Qpow(g,(MOD-1)/(i<<1));
		for(int j=1;j<i;++j)
			w[j]=Mul(w[j-1],t);
		for(int j=0;j<len;j+=(i<<1))
		{
			for(int k=0;k<i;++k)
			{
				int t=Mul(w[k],A[i+j+k]);
				A[i+j+k]=D(A[j+k],t);
				SU(A[j+k],t);
			}
		}
	}
}

Poly Mup(Poly A,Poly B)
{
	int len=1,t=A.size()+B.size()-1;
	for(;len<t;len<<=1);
	A.resize(len);
	B.resize(len);
	Fft(A);
	Fft(B);
	for(int i=0;i<len;++i)
		SMul(A[i],B[i]);
	Fft(A,true);
	A.resize(t);
	return A;
}

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
	for(int i=0;i<K;++i)
		cht[i]=Mul(dw[i],njc[i]);

	vector<int> A,B;
	for(int i=0;i<=ki;++i)
		A.emplace_back(Mul(Qpow(i,ki),njc[i]));
	for(int i=0;i<=ki;++i)
		B.emplace_back((i&1)?(MOD-njc[i]):njc[i]);
	for(int i=2;i<=2;++i)
	{
		int t=0;
		for(int j=0;j<=i;++j)
			if((i-j)&1)
				SD(t,Mul(Mul(Qpow(j,ki),njc[j]),njc[i-j]));
			else
				SU(t,Mul(Mul(Qpow(j,ki),njc[j]),njc[i-j]));
	}
	A=Mup(A,B);
	for(int i=0;i<=ki;++i)
		Sk[i]=A[i];
}

int C(int n,int m)
{
	return (m>n)?0:Mul(jc[n],Mul(njc[m],njc[n-m]));
}

int GetHer(int id)
{
	int x=va[id],p=Mul(a[id],Qpow(sa));
	vector<int> A,B;
	for(int i=0,h=1;i<=ki;++i,h=Mul(h,x-i+1))
	{
		if(i<=x)
			A.emplace_back(Mul(h,njc[i]));
		else
			A.emplace_back(0);
		B.emplace_back(Mul(cht[i],Qpow(p,i)));
	}
	A=Mup(A,B);
	int res=0;
	for(int i=0;i<=ki;++i)
		SU(res,Mul(Mul(Sk[i],jc[i]),A[i]));
	return res;
}

int main()
{
	scanf("%*d%lld%d%d",&tm,&n,&ki);
	Prework();
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		sa+=a[i];
	}
	for(int i=1;i<=n;++i)
		scanf("%d",va+i);
	int ans=0;
	for(int i=1;i<=n;++i)
		SU(ans,GetHer(i));
	printf("%d",ans);
	return 0;
}
