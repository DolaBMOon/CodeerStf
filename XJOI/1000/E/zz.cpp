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

#define LL long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=50;
const int S=(1<<16)-1;
const int MS=S+10;

int n;
Pir p[N];
LL dp[MS];

void Update(int l,int r)
{
	for(int i=S;i>=0;--i)
	{
		for(int j=l;j<=r;++j)if(!((i>>j)&1))
		{
			dp[i^(1<<j)]+=dp[i];
			break;
		}
	}
}

bool Cmp(const Pir &a,const Pir &b)
{
	return (a.sec!=b.sec)?(a.sec<b.sec):(a.fir<b.fir);
}

int main()
{
	dp[0]=1;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i].fir);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i].sec);
	sort(p,p+n,Cmp);
	for(int i=0;i<n;++i)
		Update(p[i].fir,p[i].sec);
	LL ans=0;
	for(int i=0;i<=S;++i)
		ans+=dp[i];
	printf("%lld",ans);
	return 0;
}
