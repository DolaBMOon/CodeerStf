#include<bits/stdc++.h>

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

int n,d;

int DSum(int x)
{
	int res=0;
	for(;x;res+=x%10,x/=10);
	return res;
}

unordered_map<int,int> mp;

void Update(int x,int y)
{
	if(mp.count(x))
		GetMin(mp[x],y);
	else
		mp[x]=y;
}

void Work()
{
	mp.clear();
	scanf("%lld%lld",&n,&d);
	Update(n,0);
	for(int cnt=0;n>=10;Update(n=DSum(n),++cnt));
	for(int i=1;i<=100;++i)
	{
		vector<Pir> v;
		for(Pir p:mp)
		{
			v.emplace_back(DSum(p.fir),p.sec+1);
			v.emplace_back(p.fir+d,p.sec+1);
		}
		for(Pir p:v)
			Update(p.fir,p.sec);
	}
	Pir ans(INF,0);
	for(Pir p:mp)
		GetMin(ans,p);
	printf("%lld %lld\n",ans.fir,ans.sec);
}

signed main()
{
	int T;
	for(scanf("%lld",&T);T--;)
		Work();
	return 0;
}
