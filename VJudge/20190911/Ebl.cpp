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

const int N=50;

int n;

int fi[N];

void Prework()
{
	fi[0]=0;
	fi[1]=1;
	for(int i=2;i<N;++i)
		fi[i]=fi[i-1]+fi[i-2];
}

bool Check(int a,int b,int c)
{
	if(!a)
		return true;
	if(!c)
		return false;
	for(int i=b;i<N;++i)
		if(a>=fi[i]&&Check(a-fi[i],i,c-1))
			return true;
	return false;
}

signed main()
{
	Prework();
	scanf("%lld",&n);
	int ans=4;
	for(;Check(ans,0,n);++ans);
	printf("%lld",ans);
	return 0;
}
