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

const int N=55;

int n,q[N];
vector<int> G[N];

int Dfs(int u)
{
	int res=0;
	for(int v:G[u])
		res+=Dfs(v);
	return res+((~q[u]&&((q[u]^res)&1))?1:0);
}

int main()
{
	scanf("%d",&n);
	for(int i=2,p;i<=n;++i)
	{
		scanf("%d",&p);
		++p;
		G[p].emplace_back(i);
	}
	char s[N];
	scanf("%s",s+2);
	for(int i=2;i<=n;++i)
		q[i]=(s[i]=='0');
	scanf("%s",s+2);
	q[1]=-1;
	for(int i=2;i<=n;++i)if(s[i]!='1')
		q[i]=-1;
	int ans=Dfs(1);
	if(ans)
		ans=(ans-1)/2+1;
	printf("%d",ans);
	return 0;
}
