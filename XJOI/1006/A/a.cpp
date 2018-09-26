#pragma GCC optimize(2)
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

const int N=100000+10;

int n,fa[N];
vector<int> d[N],v[N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

int main()
{
	for(int i=1;i<N;++i)
		for(int j=i;j<N;j+=i)
			d[j].push_back(i);
	scanf("%d",&n);
	for(int i=1,a;i<=n;++i)
	{
		scanf("%d",&a);
		for(int j=0;j<(int)d[a].size();++j)
			v[d[a][j]].push_back(i);
	}
	long long ans=0;
	for(int i=N-1;i;--i)
		for(int j=0,a,b;j+1<(int)v[i].size();++j)
		{
			a=Find(v[i][j]);
			b=Find(v[i][j+1]);
			if(a!=b)
			{
				ans+=i;
				fa[a]=b;
			}
		}
	printf("%lld",ans);
	return 0;
}
