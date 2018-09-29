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

int n,m,dx[N],dy[N],d[N];

void Solve(int dx,int dy)
{
	bool fx=(dx<0),fy=(dy<0);
	if(fx)
		dx*=-1;
	if(fy)
		dy*=-1;
	//for(int i=
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",dx+i,dy+i);
	for(int i=n;i>1;--i)
	{
		dx[i]-=dx[i-1];
		dy[i]-=dy[i-1];
	}
	for(int i=2;i<=n;++i)
		if(((dx[i]^dy[i])&1)^((dx[i-1]^dy[i-1])&1))
		{
			GG();
			return 0;
		}
	for(int i=1;i<=35;++i)
		d[i]=1ll<<i;
	m=35;
	if((dx[1]^dy[1])&1)
		d[++m]=1;
	printf("%lld\n",m);
	for(int i=1;i<=m;++i)
		printf("%lld ",d[i]);
	putchar('\n');
	for(int i=1;i<=n;++i)
		Solve(dx[i],dy[i]);
	return 0;
}
