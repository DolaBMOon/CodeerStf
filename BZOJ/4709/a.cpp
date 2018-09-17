#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

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

const int N=1e5+10;

int n,a[N],s[N],dp[N];
vector<int> v[N];

int Sqr(int x)
{
	return x*x;
}

int Call(int x,int l)
{
	return dp[x-1]+a[x]*l*l;
}

int APlace(int x,int y)
{
	int p=n+1;
	for(int l=1,m,r=n+1;l<=r;)
	{
		m=(l+r)>>1;
		if(Call(x,m-s[x]+1)>=Call(y,m-s[y]+1))
			r=(p=m)-1;
		else
			l=m+1;
	}
	return p;
}

int Get(const vector<int> &v,int p)
{
	return v[v.size()-p];
}

signed main()
{
	scanf("%lld",&n);
	static int nw[N];
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		s[i]=++nw[a[i]];
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		vector<int> &stk=v[a[i]];
		while(stk.size()>1&&APlace(stk[stk.size()-2],stk.back())<=APlace(stk.back(),i))
			stk.pop_back();
		stk.push_back(i);
		while(stk.size()>1&&Call(stk.back(),s[i]-s[stk.back()]+1)<=Call(stk[stk.size()-2],s[i]-s[stk[stk.size()-2]]+1))
			stk.pop_back();
		GetMax(ans,dp[i]=Call(stk.back(),s[i]-s[stk.back()]+1));
	}
	printf("%lld\n",ans);
	return 0;
}
