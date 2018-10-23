#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

#define LL long long

const int N=233;
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

int n,k,fa[N],sz[N],ans;
bool G[N][N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

void Merge(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x==y)
		return;
	fa[x]=y;
	sz[y]+=sz[x];
}

void Dfs(int x,int y)
{
	if(x==y)
	{
		x=1;
		++y;
	}
	if(y>n)
	{
		for(int i=1;i<=n;++i)
		{
			fa[i]=0;
			sz[i]=1;
		}
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)if(G[i][j])
				Merge(i,j);
		int mx=0;
		for(int i=1;i<=n;++i)
			GetMax(mx,sz[i]);
		if(mx==k)
			++ans;
		return;
	}
	Dfs(x+1,y);
	G[x][y]=true;
	Dfs(x+1,y);
	G[x][y]=false;
}

int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		puts("1");
		return 0;
	}
	//if(n==k)
	//{
	//	ans=1;
	//	for(int i=2;i<=n;++i)
	//	{
	//		SMul(ans,D(Qpow(2,i-1),1));
	//	}
	//	printf("%d",ans);
	//	return 0;
	//}
	Dfs(1,2);
	printf("%d",ans);
	return 0;
}
