#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
//#define set unordered_set
#include<set>
#include<list>

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

int n,m,q;
set<int> G[N];
int lst[N],ed;
list<int> S[N];
int tot;

void Join(int u)
{
	static int ban[N];
	int fl=0,a=0;
	for(int i=1;i<=tot;++i)
		for(list<int>::iterator it=S[i].begin();it!=S[i].end();++it)
		{
			if(!G[u].count(*it))
			{
				if(fl)
				{
					S[fl].merge(S[i]);
					ban[++a]=i;
				}
				else
					S[fl=i].push_back(u);
				break;
			}
		}
	for(;a>0;--a,--tot)if(ban[a]!=tot)
		swap(S[ban[a]],S[tot]);
	if(!fl)
	{
		S[++tot].clear();
		S[tot].push_back(u);
	}
}

int Solve()
{
	tot=0;
	for(int i=1;i<=ed;++i)
		Join(lst[i]);
	return tot;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].insert(v);
		G[v].insert(u);
	}
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&ed);
		for(int i=1;i<=ed;++i)
			scanf("%d",lst+i);
		printf("%d\n",Solve());
	}
	return 0;
}
