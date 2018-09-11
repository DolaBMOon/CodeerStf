#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
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

const int N=1e5+10;

int n;
vector<int> G[N];

void Adde(int u,int v)
{
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int lst[N],ed,fa[N];

void Song(int u,int f=0,int ft=0)
{
	lst[++ed]=u;
	fa[ed]=ft;
	int rec=ed;
	for(int v:G[u])if(v!=f)
		Song(v,u,rec);
}

int Get(int k)
{
	int res=0;
	static int x[N],y[N];
	memset(x,0,sizeof x);
	memset(y,0,sizeof y);
	for(int i=n,t,f;i>=1;--i)
	{
		if(x[i]+y[i]+1>=k)
			++res;
		else
		{
			t=max(x[i],y[i])+1;
			f=fa[i];
			if(t>x[f])
			{
				y[f]=x[f];
				x[f]=t;
			}
			else
				GetMax(y[f],t);
		}
	}
	return res;
}

int ans[N];

void Solve(int l,int r,int wl,int wr)
{
	if(l>r)
		return;
	if(wl==wr)
	{
		for(int i=l;i<=r;++i)
			ans[i]=wl;
		return;
	}
	int m=(l+r)>>1;
	ans[m]=Get(m);
	Solve(l,m-1,ans[m],wr);
	Solve(m+1,r,wl,ans[m]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Song(1);
	int B=sqrt(n*log2(n));
	for(int i=1;i<=B;++i)
		ans[i]=Get(i);
	Solve(B+1,n,0,ans[B]);
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}
