#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<cmath>

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
const int g=3;
const int L=1<<22;

int Mul(signed a,signed b)
{
	static signed MO=MOD;
	unsigned long long x=(long long)a*b;
	unsigned xh=(unsigned)(x>>32),xl=(unsigned)x,d,m;
	asm
		(
		 "divl %4;\n\t"
		 :"=a"(d),"=d"(m)
		 :"d"(xh),"a"(xl),"r"(MO)
		);
	return m;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):x;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):x;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

void FFT(int *A,bool fl)
{
	if(fl)
	{
		static int t=Qpow(L);
		for(int i=0;i<L;++i)
			A[i]=Mul(A[i],t);
		reverse(A+1,A+L);
	}
	for(int i=1,j=L>>1,k;i<L;++i,j^=k)
	{
		if(i<j)
			swap(A[i],A[j]);
		k=L>>1;
		for(;j&k;j^=k,k>>=1);
	}

	static int w[L]={1};
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

const int Y=77;

int n,q;
double ans[Y];

int main()
{
	scanf("%d%d",&n,&q);
	static int A[Y],B[Y],C[Y],D[Y],f[L+10],g[L+10];
	for(int i=1,x,y,z;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		--x;
		--y;
		--z;
		++f[x+2*Y*y+4*Y*Y*z];
		++g[(Y-x)+2*Y*(Y-y)+4*Y*Y*(Y-z)];
	}
	for(int i=1;i<=q;++i)
		scanf("%d%d%d%d",A+i,B+i,C+i,D+i);
	FFT(f,false);
	FFT(g,false);
	for(int i=0;i<L;++i)
		f[i]=Mul(f[i],g[i]);
	FFT(f,true);
	//vector<vector<int> > v;
	for(int i=0,k;i<L;++i)if(f[k=i]&&k!=Y+2*Y*Y+4*Y*Y*Y)
	{
		double dx=k%(2*Y)-Y;
		k-=dx;
		k/=2*Y;
		double dy=k%(2*Y)-Y;
		k-=dy;
		k/=2*Y;
		double dz=k%(2*Y)-Y;
		//v.push_back({(int)dx,(int)dy,(int)dz,(int)f[i]});
		double t=f[i]/sqrt(pow(dx,4)+pow(dy,4)+pow(dz,4));
		for(int j=1;j<=q;++j)
			ans[j]+=abs(A[j]*dx+B[j]*dy+C[j]*dz+D[j])*t;
	}
	//sort(v.begin(),v.end());
	//for(auto p:v)
	//{
	//	cout<<p[0]<<","<<p[1]<<","<<p[2]<<":"<<p[3]<<endl;
	//}
	double t=1.0/n/(n-1);
	for(int i=1;i<=q;++i)
		printf("%.10lf\n",ans[i]*t);
	return 0;
}
