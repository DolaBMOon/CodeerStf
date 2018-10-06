#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

#define int long long

vector<int> G[N];

int n,m,ans;

namespace Solver1
{

	void Work()
	{
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=1,rec=0;k<=m;++k)
					if(col[i][k]!=col[j][k])
					{
						ans+=(k-rec)*i*(n-k+1)*(n-j+1);
						rec=k;
					}
		printf("%lld\n",ans);
	}

}

namespace Solver2
{

	void Work()
	{
	}

}

signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;++i)
		G[i].resize(m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%lld",&G[i][j]);
	if(n<m)
		Solver1::Work();
	else
		Solver2::Work();
	return 0;
}
