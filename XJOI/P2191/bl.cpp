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

const int N=233;

int n,d,cnt;
char s[N][10];

int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]);
		for(int j=1,kk;j<i;++j)
		{
			kk=0;
			for(int k=0;k<4;++k)
				kk+=(s[i][k]!=s[j][k]);
			cnt+=(kk==d);
		}
	}
	printf("%d",cnt);
	return 0;
}
