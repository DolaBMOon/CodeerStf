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

#define Pir pair<int,bool>
#define fir first
#define sec second

const int N=1e6+10;

int n,l[N],r[N],ans,ans2;
Pir p[N];
int ed,stk[N],tp;

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",l+i,r+i);
	if(n==1)
	{
		printf("%lld\n",max(l[1],r[1])+1);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		p[++ed]=Pir(l[i],0);
		p[++ed]=Pir(r[i],1);
	}
	sort(p+1,p+ed+1);
	for(int i=1;i<=ed;++i)
	{
		if(!tp||stk[0]==p[i].sec)
		{
			stk[0]=p[i].sec;
			stk[++tp]=p[i].fir;
		}
		else
		{
			--tp;
			ans+=p[i].fir;
		}
	}
	for(int i=ed;i>=1;--i)
	{
		if(!tp||stk[0]==p[i].sec)
		{
			stk[0]=p[i].sec;
			ans2+=stk[++tp]=p[i].fir;
		}
		else
			--tp;
	}
	printf("%lld",min(ans,ans2)+n);
	return 0;
}
