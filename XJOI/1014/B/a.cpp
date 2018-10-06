#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

const int INF=0x3f3f3f3f3f3f3f3f;

int s,t,a,b,ans=INF;

int Calc(int w,int lim)
{
	if(!a)
		return w?INF:lim;
	if(w%a)
		return INF;
	w/=a;
	int res=0;
	for(int cnt=0;w&&cnt<lim;res+=w%b,w/=b,++cnt);
	return res+lim+w;
}

void Solve()
{
	if(s>t)
	{
		puts("-1");
		return;
	}
	int r=t/b;
	GetMin(ans,Calc(t-s,0));
	if(b>1)
	{
		if(s)
			for(int x=s,cnt=0;x<=r;GetMin(ans,Calc(t-(x*=b),++cnt)));
		else
			for(int cnt=0;cnt<=70;GetMin(ans,Calc(t,++cnt)));
	}
	printf("%lld\n",((ans==INF)?(-1):ans));
}

void Diss()
{
	int ans=-1;
	if(a)
	{
		if(s<t&&(t-s)%a==0)
			ans=(t-s)/a;
		else if(t%a==0)
			ans=t/a+1;
	}
	else if(!b&&!t)
		ans=1;
	printf("%lld\n",ans);
}

signed main()
{
	scanf("%lld%lld%lld%lld",&s,&t,&a,&b);
	if(s==t)
	{
		puts("0");
		return 0;
	}
	if(s||a)
	{
		if(b)
			Solve();
		else
			Diss();
	}
	else
		puts(t?"-1":"0");
	return 0;
}
