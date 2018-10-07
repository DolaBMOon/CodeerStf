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

int l,r,k;

void Work()
{
	scanf("%lld%lld%lld",&l,&r,&k);
	vector<int> ans;
	if(k==0)
	{
		if(l==0)
			ans.push_back(0);
		if(l<=1&&1<=r)
			ans.push_back(1);
	}
	else if(k==1)
	{
		if(l<=1&&1<=r)
			ans.push_back(1);
	}
	else
	{
		int x=1;
		while(true)
		{
			if(l<=x&&x<=r)
				ans.push_back(x);
			if(r/k<x)
				break;
			x*=k;
		}
	}
	if(ans.size())
	{
		for(int i=0;i<(int)ans.size();++i)
			printf("%lld ",ans[i]);
		putchar('\n');
	}
	else
		puts("None.");
}

signed main()
{
	int T;
	for(scanf("%lld",&T);T--;)
		Work();
	return 0;
}
