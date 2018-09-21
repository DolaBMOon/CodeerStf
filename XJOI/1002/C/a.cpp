#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<unordered_map>

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

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=2333;

int n,x[N],y[N];

unordered_map<int,int> mp;

int Calc(int d)
{
	mp.clear();
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(x[i]+y[i]==d)
			++cnt;
		else
			++mp[x[i]-y[i]];
	}
	int res=0;
	for(Pir p:mp)
		GetMax(res,p.sec);
	return cnt+res;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",x+i);
	for(int i=1;i<=n;++i)
		scanf("%d",y+i);
	int ans=0;
	for(int i=1;i<=n;++i)
		GetMax(ans,Calc(x[i]+y[i]));
	printf("%d",ans);
	return 0;
}
