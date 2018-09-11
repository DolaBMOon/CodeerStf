#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<set>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=2e5+10;

int n,m,k,u[N],v[N];
set<int> G[N];
int ban[N],ans;

void Erase(int u)
{
	if(ban[u])
		return;
	ban[u]=true;
	--ans;
	for(int v:G[u])
	{
		G[v].erase(u);
		if(G[v].size()<k)
			Erase(v);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",u+i,v+i);
		G[u[i]].insert(v[i]);
		G[v[i]].insert(u[i]);
	}
	ans=n;
	for(int i=1;i<=n;++i)
		if(G[i].size()<k)
			Erase(i);
	vector<int> res;
	for(int i=m;i;--i)
	{
		res.emplace_back(ans);
		if(!ban[u[i]]&&!ban[v[i]])
		{
			G[u[i]].erase(v[i]);
			G[v[i]].erase(u[i]);
			if(G[u[i]].size()<k)
				Erase(u[i]);
			if(G[v[i]].size()<k)
				Erase(v[i]);
		}
	}
	reverse(res.begin(),res.end());
	for(int i:res)
		printf("%d\n",i);
	return 0;
}
