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

const int N=520;

int n,m,fa[N],du[N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		++du[u];
		--du[v];
		u=Find(u);
		v=Find(v);
		if(u!=v)
			fa[u]=v;
	}
	for(int i=2;i<=n;++i)
		if(Find(i)!=Find(i-1))
			return 0*puts("No");
	for(int i=1;i<=n;++i)
		if(du[i])
			return 0*puts("No");
	puts("Yes");
	return 0;
}
