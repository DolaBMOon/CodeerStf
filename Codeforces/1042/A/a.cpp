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

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=100+10;

int n,m,a[N];

int main()
{
	scanf("%d%d",&n,&m);
	int mx=0,r;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		GetMax(mx,a[i]);
	}
	r=mx+m;
	for(int i=1;i<=n;++i)
		m-=mx-a[i];
	if(m<=0)
		cout<<mx<<" ";
	else
		cout<<mx+(m-1)/n+1<<" ";
	cout<<r<<endl;
	return 0;
}
