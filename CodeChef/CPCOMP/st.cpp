#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

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

const int N=2e5+10;

int n;
set<int> S;
vector<int> G[N];

int main()
{
	for(int i=2;i*i<N;++i)
	{
		if(G[i].size()>0)
			continue;
		for(int j=i;j<N;j+=i)
			G[j].emplace_back(i);
	}
	scanf("%d",&n);
	for(int i=1,a;i<=n;++i)
	{
		scanf("%d",&a);
		for(int x:G[a])
			while(a%(x*x)==0)
				a/=x;
		S.insert(a);
	}
	assert(S.size()<=5000);
	return 0;
}
