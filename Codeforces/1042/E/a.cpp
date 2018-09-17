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

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=1e6+10;
const int MOD=998244353;

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
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

struct Data
{
	int w,x,y;
}o[N];

int n,m,r,c;
int tot;

bool Cmp(const Data &x,const Data &y)
{
	return x.w<y.w;
}

int smx[N],smx2[N],smy[N],smy2[N],res[N],sm[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1,x;j<=m;++j)
		{
			scanf("%d",&x);
			o[++tot]=(Data){x,i,j};
		}
	}
	scanf("%d%d",&r,&c);
	sort(o+1,o+tot+1,Cmp);
	for(int i=1,j=0;i<=tot;++i)
	{
		while(j<i-1&&o[j+1].w!=o[i].w)
			++j;
		smx[i]=U(smx[i-1],o[i].x);
		smx2[i]=U(smx2[i-1],Mul(o[i].x,o[i].x));
		smy[i]=U(smy[i-1],o[i].y);
		smy2[i]=U(smy2[i-1],Mul(o[i].y,o[i].y));
		SU(res[i],Mul(j,Mul(o[i].x,o[i].x)));
		//if(i==tot);
		//{
		//}
		SU(res[i],Mul(Mul(MOD-2,o[i].x),smx[j]));
		SU(res[i],smx2[j]);
		SU(res[i],Mul(j,Mul(o[i].y,o[i].y)));
		SU(res[i],Mul(Mul(MOD-2,o[i].y),smy[j]));
		SU(res[i],smy2[j]);
		SU(res[i],sm[j]);
		res[i]=Mul(res[i],Qpow(j));
		sm[i]=U(sm[i-1],res[i]);
		//cout<<o[i].x<<","<<o[i].y<<":"<<res[i]<<endl;
		if(o[i].x==r&&o[i].y==c)
		{
			printf("%d\n",res[i]);
			return 0;
		}
	}
	return 0;
}
