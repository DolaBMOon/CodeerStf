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

#define LL long long

const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
const int N=2e6+10;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

void SMul(int &x,int y)
{
	x=(LL)x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):x;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,SMul(x,x))if(y&1)
		SMul(res,x);
	return res;
}

int n,T;

namespace Solver2
{

	int jc[N],njc[N];

	int C(int x)
	{
		int y=x>>1;
		return Mul(jc[x],Mul(njc[y],njc[x-y]));
	}

	void Solve()
	{
		jc[0]=1;
		for(int i=1;i<=n;++i)
			jc[i]=Mul(jc[i-1],i);
		njc[n]=Qpow(jc[n]);
		for(int i=n-1;i>=0;--i)
			njc[i]=Mul(njc[i+1],i+1);
		int ans=1;
		for(int i=1,x=INF,y,cnt=0;i<=n;++i,++cnt)
		{
			scanf("%d",&y);
			if(x<y||i==n)
			{
				SMul(ans,C(cnt));
				cnt=0;
			}
			x=y+n;
		}
		printf("%d\n",ans);
	}

}

int main()
{
	scanf("%d%d",&n,&T);
	if(T==1)
	{
		puts("1");
		return 0;
	}
	else if(T==2)
		Solver2::Solve();
	else
	{
		int ans=1,t=n;
		while(n--)
			if((ans<<=1)>=MOD)
				ans-=MOD;
		if((ans-=t)<0)
			ans+=MOD;
		printf("%d\n",ans);
	}
	return 0;
}
