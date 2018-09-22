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

const int N=233;

int n,ty[N];
vector<int> G[N],t;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",ty+i);
	for(int i=1,a;i<=n;++i)
	{
		scanf("%d",&a);
		G[ty[i]].emplace_back(a);
	}
	int x=0,y=0;
	for(int i=1;i<N;++i)if(!G[i].empty())
	{
		sort(G[i].rbegin(),G[i].rend());
		if(G[i][0]>=0)
		{
			++x;
			for(int v:G[i])
			{
				if(v>0)
					y+=v;
				else
					break;
			}
		}
		else
			t.emplace_back(G[i][0]);
	}
	sort(t.rbegin(),t.rend());
	int ans=x*y;
	for(int v:t)
	{
		++x;
		y+=v;
		GetMax(ans,x*y);
	}
	printf("%d",ans);
	return 0;
}
