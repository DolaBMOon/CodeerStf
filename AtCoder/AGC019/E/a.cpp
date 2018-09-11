#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<"<<<<<<<<<<<<<<"<<endl
#define Divshe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!"<<endl

#define Poly vector<int>

ostream& operator<<(ostream& os,Poly p)
{
	for(int i:p)
		os<<i<<" ";
	return os;
}

const int N=20000;
const int MOD=998244353;
const int g=3;

int Mul(int a,int b)
{
	unsigned long long x=(long long)a*b;
	unsigned xh=(unsigned)(x>>32),xl=(unsigned)x,d,m;
	asm
		(
		 "divl %4;\n\t"
		 :"=a"(d),"=d"(m)
		 :"d"(xh),"a"(xl),"r"(MOD)
		);
	return m;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
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

void FFT(Poly& A,bool fl)
{
	int L=A.size();
	if(fl)
	{
		int t=Qpow(L);
		for(int& i:A)
			i=Mul(i,t);
		reverse(A.begin()+1,A.end());
	}
	for(int i=1,j=L>>1,k;i<L;++i,j^=k)
	{
		if(i<j)
			swap(A[i],A[j]);
		k=L>>1;
		while(j&k)
		{
			j^=k;
			k>>=1;
		}
	}

	static int w[N]={1};

	for(int i=1;i<L;i<<=1)
	{
		int t=Qpow(g,(MOD-1)/(i<<1));
		for(int j=1;j<i;++j)
			w[j]=Mul(w[j-1],t);
		for(int j=0;j<L;j+=(i<<1))
		{
			for(int k=0;k<i;++k)
			{
				t=Mul(A[i+j+k],w[k]);
				A[i+j+k]=D(A[j+k],t);
				SU(A[j+k],t);
			}
		}
	}
}

int n;
char A[N],B[N];

Poly operator*(Poly A,Poly B)
{
	int need=A.size()+B.size()-1,L,q=A.size();
	for(L=1;L<need;L<<=1);
	A.resize(L);
	FFT(A,false);
	B.resize(L);
	FFT(B,false);
	for(int i=0;i<L;++i)
		A[i]=Mul(A[i],B[i]);
	FFT(A,true);
	A.resize(q);
	return A;
}

Poly f;

Poly Qpow(Poly f,int y)
{
	int L=f.size();
	Poly res;
	res.resize(L);
	res[0]=1;
	for(;y;y>>=1,f=f*f)if(y&1)
			res=res*f;
	return res;
}

int jc[N],njc[N];

void Prework()
{
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=Mul(jc[i-1],i);
	njc[n]=Qpow(jc[n]);
	for(int i=n-1;i>=0;--i)
		njc[i]=Mul(njc[i+1],i+1);
}

int main()
{
	scanf("%s%s",A,B);
	n=strlen(A);
	int x=0,y=0;
	Prework();
	for(int i=0;i<n;++i)
		if(A[i]=='1')
			(B[i]=='0')?(++x):(++y);
	f.resize(y+1);
	for(int i=0;i<=y;++i)
		f[i]=njc[i+1];
	f=Qpow(f,x);
	int ans=0;
	for(int i=0;i<=y;++i)
		SU(ans,f[i]);
	ans=Mul(ans,Mul(Mul(jc[x],jc[y]),jc[x+y]));
	printf("%d",ans);
	return 0;
}
