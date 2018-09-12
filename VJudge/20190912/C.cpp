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

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=30;

const int INF=0x3f3f3f3f3f3f3f3f;

int n,c;
Pir p[N];

int Work()
{
	static int b[N];
	int a=c;
	for(int i=n;i>=1;--i)
	{
		b[i]=min(p[i].sec,a/p[i].fir);
		a-=b[i]*p[i].fir;
	}
	if(a)
	{
		for(int i=1;i<=n;++i)
			if((p[i].sec-b[i])*p[i].fir>=a)
			{
				b[i]+=(a-1)/p[i].fir+1;
				a=0;
				break;
			}
	}
	if(a)
		return 0;
	int mn=INF;
	for(int i=1;i<=n;++i)if(b[i])
		GetMin(mn,p[i].sec/b[i]);
	for(int i=1;i<=n;++i)
		p[i].sec-=mn*b[i];
	return mn;
}

signed main()
{
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",&p[i].fir,&p[i].sec);
	sort(p+1,p+n+1);
	int ans=0;
	for(int i;i=Work();ans+=i);
	{
		//DivHim();
		//for(int j=1;j<=3;++j)
		//	cout<<p[j].sec<<"!"<<endl;
		//DivHer();
	}
	printf("%lld",ans);
	return 0;
}
