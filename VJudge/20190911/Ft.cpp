#include<iostream>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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

int n;
set<int> f[N];

int main()
{
	scanf("%d",&n);
	f[1].insert(1);
	f[1].insert(2);
	for(int i=2;i<=n;++i)
	{
		for(int v:f[i-1])
		{
			f[i].insert(v);
			f[i].insert(v+1);
		}
	}
	for(int i=1;i<=n;++i)
	{
		cout<<i<<":::::::::::"<<endl;
		for(int v:f[i])
			cout<<v<<",";
		puts("");
	}
	return 0;
}
