#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
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

const int N=3e5+10;

int n,m;
vector<int> G[N];
int col[N],stk[N],tp;

void Dfs(int u,int fa=0)
{
	col[u]=!col[fa];
	stk[++tp]=u;
	for(int v:G[u])if(v!=fa)
	{
		if(~col[v])
		{
			if(col[u]==col[v])
			{
				for(int i=1;i<=tp;++i)
				{
					if(stk[i]==v)
					{
						printf("%d\n",tp-i+1);
						for(int j=i;j<=tp;++j)
							printf("%d ",stk[j]);
					}
				}
				exit(0);
			}
		}
		else
			Dfs(v,u);
	}
	--tp;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	memset(col,-1,sizeof col);
	Dfs(1);
	puts("0");
	for(int i=1;i<=n;++i)
		printf("%d ",col[i]);
	return 0;
}
