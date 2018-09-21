#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<map>

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

const int N=2333;
const int MOD=1e9+7;

void SU(int &a,int b)
{
	((a+=b)>=MOD)?(a-=MOD):0;
}

int n,m,S;
int f[N][N],x[N*N],y[N*N],w[N*N],ed;

int main()
{
	scanf("%d%d",&n,&m);
	S=1;
	while((S<=n)||(S<=m))
		S<<=1;
	--S;
	f[0][0]=1;
	for(int k=1;k<=n||k<=m;++k)
	{
		ed=0;
		for(int i=0;i<=S;++i)
			for(int j=0;j<=S;++j)if(f[i][j])
			{
				if(k<=n)
				{
					x[++ed]=i^k;
					y[ed]=j;
					w[ed]=f[i][j];
				}
				if(k<=m)
				{
					x[++ed]=i;
					y[ed]=j^k;
					w[ed]=f[i][j];
				}
			}
		for(int i=1;i<=ed;++i)
			SU(f[x[i]][y[i]],w[i]);
	}
	int ans=0;
	for(int i=0;i<=S;++i)
		for(int j=i+1;j<=S;++j)
			SU(ans,f[i][j]);
	printf("%d",ans);
	return 0;
}
