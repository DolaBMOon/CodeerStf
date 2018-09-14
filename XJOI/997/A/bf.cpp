#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<set>

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

const int N=23333;

int n,m,q;
set<int> G[N];

int lst[N],ed,fa[N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

bool Hb(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x==y)
		return false;
	fa[x]=y;
	return true;
}

int Solve()
{
	memset(fa,0,sizeof fa);
	int ans=ed;
	for(int i=1;i<=ed;++i)
		for(int j=1;j<i;++j)if(!G[lst[i]].count(lst[j]))
			ans-=Hb(lst[i],lst[j]);
	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		G[x].insert(y);
		G[y].insert(x);
	}
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&ed);
		for(int j=1;j<=ed;++j)
			scanf("%d",lst+j);
		printf("%d\n",Solve());
	}
	return 0;
}
