#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
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

const int N=1e5+10;

int n,m,a[N];

int main()
{
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1,op,x,y,z;i<=m;++i)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op&1)
		{
			z=a[y];
			for(int j=y;j>x;--j)
				a[j]=a[j-1];
			a[x]=z;
		}
		else
		{
			scanf("%d",&z);
			int ans=0;
			for(int j=x;j<=y;++j)
				ans+=(a[j]==z);
			printf("%d\n",ans);
		}
	}
	return 0;
}
