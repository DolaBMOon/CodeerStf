#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
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

const int N=1000+10;

int n,m;
bool sf;
vector<int> G[N];

int main()
{
	scanf("%d%d",&n,&m);
	if(n>m)
	{
		swap(n,m);
		sf=true;
	}
	for(int i=0;i<n;++i)
		G[i].resize(m);
	if(sf)
	{
		for(int j=0;j<m;++j)
			for(int i=0;i<n;++i)
				scanf("%d",&G[i][j]);
	}
	else
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&G[i][j]);
	}
	for(int i=0;i<m;++i)
	{
	}
	return 0;
}
