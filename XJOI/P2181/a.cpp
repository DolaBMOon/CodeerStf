#pragma GCC optimize(2)
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

/*
-<Unlimited Blade Works>-
*/

#define LL long long

const int N=233;

int n,MOD;
int A[N][N];

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

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int Det()
{
	int res=1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			while(A[j][i])
			{
				if(!A[i][i]||A[j][i]<A[i][i])
				{
					for(int k=i;k<=n;++k)
						swap(A[i][k],A[j][k]);
					res*=-1;
				}
				if(A[j][i])
				{
					int d=A[j][i]/A[i][i];
					for(int k=i;k<=n;++k)
						SD(A[j][k],Mul(A[i][k],d));
				}
			}

	if(res==-1)
		res=MOD-1;
	for(int i=1;i<=n;++i)
		res=Mul(res,A[i][i]);
	return res;
}

void Fix(int &x)
{
	x=(x%MOD+MOD)%MOD;
}

int main()
{
	scanf("%d%d",&n,&MOD);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&A[i][j]);
			Fix(A[i][j]);
		}

	printf("%d",Det());
	return 0;
}
