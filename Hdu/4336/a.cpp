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

const int N=21;
const int M=(1<<N)+10;

int n,S;
double p[N],dp[M],ans;
int fl[M],d[M];

int main()
{
	for(int i=1;i<M;++i)
		if(!(i&1))
			d[i]=(d[i>>1])+1;
	fl[0]=-1;
	for(int i=1;i<M;++i)
		fl[i]=fl[i>>1]*((i&1)?(-1):1);
	while(~scanf("%d",&n))
	{
		S=(1<<n)-1;
		for(int i=0;i<n;++i)
			scanf("%lf",p+i);
		ans=0;
		for(int i=1;i<=S;++i)
		{
			dp[i]=dp[i^(1<<d[i])]+p[d[i]];
			if(dp[i]>0)
				ans+=fl[i]/dp[i];
		}
		printf("%.5lf\n",ans);
	}
	return 0;
}
