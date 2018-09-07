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

#define int long long
#define Tp template
#define Ty typename

const int MOD=1e9+7;
const int MOD2=MOD*MOD;

int Mul(int x,int y)
{
	return x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int U2(int x,int y)
{
	return ((x+=y)>=MOD2)?(x-MOD2):x;
}

void SU2(int &x,int y)
{
	((x+=y)>=MOD2)?(x-=MOD2):0;
}

const int LG=35;
const int N=1000;
const int K=20;

int n,ki,in[K][N],ou[N][K],G[LG][K][K];

Tp<Ty T,Ty T2,Ty T3> void Mul(T C,T2 A,T3 B,int n,int ki,int m)
{
	static int D[N][N];
	for(int i=0;i<n;++i)
		memset(D[i],0,m*sizeof(*D));
	for(int i=0;i<n;++i)
		for(int k=0;k<ki;++k)if(A[i][k])
			for(int j=0;j<m;++j)
				SU2(D[i][j],A[i][k]*B[k][j]);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			C[i][j]=D[i][j]%MOD;
}

Tp<Ty T> void BeI(T A,int n)
{
	for(int i=0;i<n;++i)
		memset(A[i],0,n*sizeof(*A));
	for(int i=0;i<n;++i)
			A[i][i]=1;
}

Tp<Ty T> void Mv(T x,T q,int cc)
{
	static int y[N];
	memcpy(x,q,n*sizeof(*q));
	memset(y,0,n*sizeof(*y));
	for(int i=0;i<n;++i)
		for(int j=0;j<ki;++j)
			SU2(y[j],x[i]*ou[i][j]);
	for(int i=0;i<ki;++i)
		y[i]%=MOD;
	memset(x,0,n*sizeof(*x));
	int (*A)[K]=G[cc];
	for(int i=0;i<ki;++i)
		for(int j=0;j<ki;++j)
			SU2(x[j],y[i]*A[i][j]);
	for(int i=0;i<ki;++i)
		x[i]%=MOD;
	memset(y,0,n*sizeof(*y));
	for(int i=0;i<ki;++i)
		for(int j=0;j<n;++j)
			SU2(y[j],x[i]*in[i][j]);
	for(int i=0;i<n;++i)
		x[i]=y[i]%MOD;
}

void Prework()
{
	BeI(G[0],ki);
	Mul(G[1],in,ou,ki,n,ki);

	for(int di=2;di<LG;++di)
		Mul(G[di],G[di-1],G[di-1],ki,ki,ki);

	for(int di=2;di<LG;++di)
		Mul(G[di],G[di-1],G[di],ki,ki,ki);
}

int Calc(int u,int v,int d)
{
	static int t[N],t2[N],x[N];
	memset(t,0,n*sizeof(*t));
	memset(t2,0,n*sizeof(*t2));
	t[u]=t2[u]=1;
	Mv(x,t2,0);
	memcpy(t2,x,n*sizeof(*t2));

	for(int cc=0;d;d>>=1,++cc)
	{
		if(d&1)
		{
			for(int i=0;i<n;++i)
				SU(t[i],t2[i]);
			Mv(x,t2,cc);
			memcpy(t2,x,n*sizeof(*t2));
		}
		Mv(x,t2,cc);
		for(int i=0;i<n;++i)
			SU(t2[i],x[i]);
	}
	return t[v];
}

signed main()
{
	scanf("%lld%lld",&n,&ki);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<ki;++j)
		{
			scanf("%lld",&ou[i][j]);
			ou[i][j]%=MOD;
		}
		for(int j=0;j<ki;++j)
		{
			scanf("%lld",&in[j][i]);
			in[i][j]%=MOD;
		}
	}

	Prework();

	int m;
	scanf("%lld",&m);
	for(int i=1,u,v,d;i<=m;++i)
	{
		scanf("%lld%lld%lld",&u,&v,&d);
		--u;
		--v;
		printf("%lld\n",Calc(u,v,d));
	}
	return 0;
}
