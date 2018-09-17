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
int a[N],b[N],ans;

bool Check(int p)
{
	return b[(p-1+n)%n]!=b[p]&&b[(p+1)%n]!=b[p];
}

void Dfs(int k)
{
	if(k==n)
	{
		for(int i=0;i<n;++i)
			if(!Check(i))
				return;
		++ans;
		//DivHim();
		//for(int i=0;i<n;++i)
		//	cout<<b[i]<<" ";
		//puts("");
		//DivHer();
		return;
	}
	for(int i=1;i<=a[k];++i)
	{
		b[k]=i;
		Dfs(k+1);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",a+i);
	Dfs(0);
	printf("%d",ans);
	return 0;
}
