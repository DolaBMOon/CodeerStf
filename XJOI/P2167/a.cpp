#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=5000000+10;
const int AND=(1<<23)-1;

namespace HashTable
{

	int w[AND+10];

	void Insert(int x)
	{
		int y=x&AND;
		for(;!(~w[y]);y=(y+1)&AND);
		w[y]=x;
	}

	int Count(int x)
	{
	}

	void Init()
	{
		memset(w,-1,sizeof w);
	}

};

int n,a[N];

int main()
{
	Init();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
	}
	return 0;
}
