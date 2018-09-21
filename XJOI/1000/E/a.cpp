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

const int N=55;

int n;
Pir p[N];
LL dp[N];

bool Cmp(const Pir &a,const Pir &b)
{
	return (a.sec!=b.sec)?(a.sec<b.sec):(a.fir<b.fir);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i].fir);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i].sec);
	sort(p,p+n,Cmp);
	for(int i=0;i<n;++i)
	{
		for(int j=p[i].sec,k=p[i].fir+1;j>=k;--j)
			dp[j]+=dp[j-1];
		for(int j=0;j<p[i].fir;++j)
			dp[p[i].fir]+=dp[j];
		++dp[p[i].fir];
		//DivHim();
		//for(int j=0;j<5;++j)
		//	cout<<dp[j]<<" ";
		//puts("");
		//DivHer();
	}
	int ans=1;
	for(int i=0;i<N;++i)
		ans+=dp[i];
	printf("%d\n",ans);
	return 0;
}
