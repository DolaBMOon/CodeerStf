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

const int N=300+10;
const int K=7;

int n,k,d[2][N][N];
vector<int> G0[N],G1[N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=2,p;i<=n;++i)
	{
		scanf("%d",&p);
		++p;
		G0[p].emplace_back(i);
		G0[i].emplace_back(p);
	}
	for(int i=2,p;i<=n;++i)
	{
		scanf("%d",&p);
		++p;
		G1[p].emplace_back(i);
		G1[i].emplace_back(p);
	}
	//Dfs(G0,
	double ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			ans+=Calc(i,j);
	for(int i=1;i<=n;++i)
		ans/=i;
	ans/=k;
	printf("%.17lf",ans);
	return 0;
}
