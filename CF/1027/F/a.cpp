//%:pragma GCC optimize("Ofast")
//%:pragma GCC target("sse3","sse2","sse")
//%:pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
//%:pragma GCC target("f16c")
//%:pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
//%:pragma GCC diagnostic error "-fwhole-program"
//%:pragma GCC diagnostic error "-fcse-skip-blocks"
//%:pragma GCC diagnostic error "-funsafe-loop-optimizations"
//%:pragma GCC diagnostic error "-std=c++14"

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=2e6+10;

int n,u[N],v[N];
int an[N],tot;

int fa[N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

void Shit()
{
	puts("-1");
	exit(0);
}

bool fl[N];

void Hb(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x==y)
	{
		if(fl[x])
			Shit();
		fl[x]=true;
	}
	else
	{
		if(fl[x]&&fl[y])
			Shit();
		else if(fl[y])
			fl[x]=true;
		fa[y]=x;
	}
}

int mx[N],mx2[N];

void Update(int x,int y)
{
	if(mx[x]<y)
	{
		mx2[x]=mx[x];
		mx[x]=y;
	}
	else if(mx2[x]<y)
		mx2[x]=y;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",u+i,v+i);
		an[++tot]=u[i];
		an[++tot]=v[i];
	}

	sort(an+1,an+tot+1);
	tot=unique(an+1,an+tot+1)-an-1;
	for(int i=1;i<=n;++i)
		Hb(u[i]=lower_bound(an+1,an+tot+1,u[i])-an
		,v[i]=lower_bound(an+1,an+tot+1,v[i])-an);

	for(int i=1;i<=tot;++i)
		Update(Find(i),an[i]);
	
	int ans=0;
	for(int i=1;i<=tot;++i)
		ans=max(ans,fl[Find(i)]?mx[i]:mx2[i]);
	printf("%d",ans);
	return 0;
}
