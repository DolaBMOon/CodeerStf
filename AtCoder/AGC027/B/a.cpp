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

#define int long long

const int N=2e5+10;

int n,x;
int s[N];

signed main()
{
	scanf("%lld%lld",&n,&x);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",s+i);
		s[i]+=s[i-1];
	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=1,t;i<=n;++i)
	{
		t=i*x;
		for(int j=n,k,c=1;j>=1;j=k,++c)
		{
			k=max(0ll,j-i);
			t+=(s[j]-s[k])*max(5ll,(c*2+1));
			if(t>=ans)
				break;
		}
		GetMin(ans,t);
	}
	printf("%lld",ans+n*x);
	return 0;
}
