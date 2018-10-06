#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<unordered_map>

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

int s,t,a,b;
unordered_map<int,int> mp;

void Upd(int x,int y)
{
	if(!mp.count(x))
		mp[x]=y;
	else
		GetMin(mp[x],y);
}

void Solve()
{
	if(s>t)
	{
		puts("-1");
		return;
	}
	int r=t/b;
	mp[s]=0;
	for(int cnt=0,x=s;x<=r;mp[x*=b]=++cnt);
	for(int i=1;i<=1000;++i)
	{
		static vector<Pir> v;
		v.clear();
		for(Pir p:mp)
		{
			if(p.fir<=r)
				v.emplace_back(p.fir*b,p.sec+1);
			if(p.fir+a<=t)
				v.emplace_back(p.fir+a,p.sec+1);
		}
		for(Pir p:v)
			Upd(p.fir,p.sec);
	}
	int ans=INF;
	for(Pir p:mp)
	{
		if((t-p.fir)%a==0)
			GetMin(ans,p.sec+(t-p.fir)/a);
	}
	printf("%lld\n",(ans<INF?ans:-1));
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
	printf("%lld",ans);
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
		puts(t?"0":"-1");
	return 0;
}
