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

const int N=200000+10;

int n,x[N],y[N],z[N];

void Work()
{
	for(int i=1,a,b,c;i<=n;++i)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		x[i]=a-b;
		y[i]=b-c;
		z[i]=c-a;
	}
	int ans=0;
	sort(x+1,x+n+1);
	for(int i=1;i<=n;++i)
		ans+=x[i]*(i-1-(n-i));
	sort(y+1,y+n+1);
	for(int i=1;i<=n;++i)
		ans+=y[i]*(i-1-(n-i));
	sort(z+1,z+n+1);
	for(int i=1;i<=n;++i)
		ans+=z[i]*(i-1-(n-i));
	printf("%lld\n",ans>>1);
}

signed main()
{
	while(scanf("%lld",&n),n)
		Work();
	return 0;
}
