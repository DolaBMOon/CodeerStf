#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=233;

int n,a[N],b[N];

bool Dfs(int k)
{
	if(!k)
	{
		for(int i=1;i<=n;++i)
			if(a[i]!=b[i])
				return false;
		return true;
	}
	int sm=0;
	for(int i=1;i<=n;++i)
		sm^=a[i];
	for(int i=1;i<=n;++i)
	{
		swap(sm,a[i]);
		if(Dfs(k-1))
		{
			swap(sm,a[i]);
			return true;
		}
		swap(sm,a[i]);
	}
	return false;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		scanf("%d",b+i);
	for(int i=0;i<=n+1;++i)
		if(Dfs(i))
		{
			printf("%d\n",i);
			return 0;
		}
	puts("-1");
	return 0;
}
