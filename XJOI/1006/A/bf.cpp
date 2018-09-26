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

const int N=1e5+10;

struct Edge
{
	int u,v,w;
};

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

int n,a[N],fa[N];
vector<Edge> edges;

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

bool Cmp(const Edge &a,const Edge &b)
{
	return a.w>b.w;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			edges.push_back((Edge){i,j,Gcd(a[i],a[j])});
	sort(edges.begin(),edges.end(),Cmp);
	long long ans=0;
	for(int i=0;i<(int)edges.size();++i)
	{
		Edge &e=edges[i];
		int u=Find(e.u),v=Find(e.v);
		if(u!=v)
		{
			fa[u]=v;
			ans+=e.w;
		}
	}
	printf("%lld",ans);
	return 0;
}
