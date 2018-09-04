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

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=250000+10;
const int M=520;

int n,m,k;
int h[N];
Pir p[M];

int Calc(int h)
{
	int cnt=0;
	for(int i=m,d;h&&i>0;--i)if(h>p[i-1].fir)
	{
		d=(h-p[i-1].fir-1)/p[i].sec+1;
		cnt+=d;
		h-=d*p[i].sec;
	}
	return cnt;
}

signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%lld",h+i);
	for(int i=1;i<=m;++i)
		scanf("%lld%lld",&p[i].fir,&p[i].sec);
	sort(p+1,p+m+1);
	int t=m;
	m=0;
	for(int i=1;i<=t;++i)
	{
		for(;m>0&&p[i].sec>=p[m].sec;--m);
		p[++m]=p[i];
	}
	int cnt=0;
	for(int i=n,t;i>0&&t;--i)
		if((t=k-Calc(h[i]))>=0)
		{
			k=t;
			++cnt;
		}
	printf("%lld %lld",cnt,k);
	return 0;
}
