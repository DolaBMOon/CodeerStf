#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Divshe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!"<<endl

#define LL long long

const int N=2002;
const int MOD=1e9+7;

int U(int a,int b)
{
	return ((a+=b)>=MOD)?(a-MOD):a;
}

void SU(int& a,int b)
{
	((a+=b)>=MOD)?(a-=MOD):0;
}

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

int n,m;
int f[N],a[N<<1],g[N],h[N];

void Mul(int* A,int* B)
{
	static int rec[N<<1];
	for(int i=n+n-2;i>=0;--i)
		rec[i]=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			SU(rec[i+j],Mul(A[i],B[j]));
	for(int i=n+n-2;i>=n;--i)
		for(int j=1;j<=n;++j)
			SU(rec[i-j],Mul(rec[i],f[j-1]));
	memcpy(A,rec,sizeof(int)*n);
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",f+i);
		if(f[i]<0)
			f[i]+=MOD;
	}
	for(int i=0;i<n;++i)
	{
		scanf("%d",a+i);
		if(a[i]<0)
			a[i]+=MOD;
	}
	if(m<=n)
	{
		printf("%d",a[m-1]);
		return 0;
	}
	m-=n-1;

	h[1]=1;
	g[0]=1;

	for(;m;m>>=1,Mul(h,h))if(m&1)
		Mul(g,h);

	for(int i=n;i<n+n-1;++i)
		for(int j=1;j<=n;++j)
			SU(a[i],Mul(a[i-j],f[j-1]));
	int ans=0;
	for(int i=0;i<n;++i)
		SU(ans,Mul(a[n+i-1],g[i]));
	printf("%d",ans);
	return 0;
}
