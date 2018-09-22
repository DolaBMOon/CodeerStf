#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

const int N=1500;

int n,l,c[N],p[N];

int main()
{
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",c+i);
		p[i]=i;
	}
	int ans=0;
	do
	{
		int x=0,cnt=0;
		for(int i=1;i<=n;++i)
			if(p[i]>x)
			{
				cnt+=(c[p[i]]!=c[x]);
				x=p[i];
			}
		ans+=(cnt==l);
	}
	while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return 0;
}
