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

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=1e6+10;
const int INF=0x3f3f3f3f;

int n,k;
vector<int> G[N];
int ans;

int Dfs(int u,int fa=0)
{
	vector<int> lst;
	for(int v:G[u])if(v!=fa)
		lst.emplace_back(Dfs(v,u)+1);
	//cout<<u<<":"<<ans<<endl;
	//for(int i:lst)
	//	cout<<i<<",";
	//cout<<endl;
	if(lst.size())
	{
		sort(lst.begin(),lst.end());
		while(lst.size()>=2&&lst.back()+lst[lst.size()-2]>k)
			lst.pop_back();
		while(!lst.empty()&&lst.back()>k)
			lst.pop_back();
		if(lst.empty())
			return INF;
		ans-=lst.size()-1;
		return lst.back();
	}
	++ans;
	return 0;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	//Dfs(1);
	//Whats(ans);
	//return 0;
	for(int i=1;i<=n;++i)
	{
		if(G[i].size()>1)
		{
			Dfs(i);
			printf("%d",ans);
			return 0;
		}
	}
	return 0;
}
