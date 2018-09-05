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

const int N=500000+10;
const int P=2e7+10;

char Nc()
{
	static char buf[_B],*p=buf,*q=buf;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
}

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int sum=ch-48;
	while(isdigit(ch=Nc()))
		sum=sum*10+ch-48;
	return sum;
}

int MOD;

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

int Qpow(int x,int y)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

int phi[P],pri[P],totp;
bool vis[P];

void Prework()
{
	for(int i=2;i<P;++i)
	{
		if(!vis[i])
		{
			pri[++totp]=i;
			phi[i]=i-1;
		}
		for(int j=1,k;j<=totp&&pri[j]*i<P;++j)
		{
			vis[k=pri[j]*i]=true;
			if(i%pri[j])
				phi[k]=phi[i]*(p[j]-1);
			else
			{
				phi[k]=phi[i]*pri[j];
				break;
			}
		}
	}
}

int n,m,a[N];
LL C[N];

void Add(int x,int y)
{
	for(;x;x-=x&(-x))
		C[x]+=y;
}

LL Query(int x)
{
	LL res=0;
	for(;x<=n;x+=x&(-x))
		res+=C[x];
	return res;
}

int Calc(int l,int r,int p)
{
	if(l==r+1)
		return 1;
	if(p==1)
		return 0;
	LL x=a[l]+Query(l);
	int t=Pwc(l+1,r,phi[p]);
	if(x>=p)
		return Qpow(x%p,t,p)%p+p;
	return Qpow(x,t,p);
}

int main()
{
	Prework();
	n=Read();
	m=Read();
	for(int i=1,op,l,r,x;i<=n;++i)
	{
		op=Read();
		l=Read();
		r=Read();
		x=Read();
		if(op&1)
		{
			Add(l-1,-x);
			Add(r,x);
		}
		else
			printf("%d\n",Calc(l,r,x)%x);
	}
	return 0;
}
