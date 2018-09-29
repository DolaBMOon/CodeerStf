#pragma GCC optimize("Ofast")
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

const int N=1e5+10;
const int MOD=998244353;

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
	((x+=y)>=MOD)?(x-=MOD):0;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,SMul(x,x))if(y&1)
		SMul(res,x);
	return res;
}

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

int ty,n,q,a[N];

namespace Solver1
{

	void Ans()
	{
		int res=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				SU(res,(LL)a[i]/Gcd(a[i],a[j])*a[j]%MOD);
		printf("%d\n",res);
	}

	void Solve()
	{
		Ans();
		for(int i=1,x,y,z;i<=q;++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			for(int j=x;j<=y;++j)
				a[j]=z;
			Ans();
		}
	}

}

namespace Solver2
{

	void Solve()
	{
		LL res=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				res+=(LL)a[i]/Gcd(a[i],a[j])*a[j];
		printf("%lld\n",res%MOD);
	}

}

namespace Solver3
{

	int p[N],totp,mu[N];
	bool vis[N];

	int Song(int n)
	{
		LL t=(LL)(1+n)*n/2%MOD;
		return t*t%MOD;
	}

	void Solve()
	{
		mu[1]=1;
		for(int i=2;i<=n;++i)
		{
			if(!vis[i])
			{
				p[++totp]=i;
				mu[i]=-1;
			}
			for(int j=1;j<=totp&&p[j]*i<=n;++j)
			{
				vis[p[j]*i]=true;
				if(i%p[j])
					mu[p[j]*i]=-mu[i];
				else
					break;
			}
		}
		int ans=0;
		for(int d=1,t;d<=n;++d)
		{
			t=0;
			for(int k=n/d;k>=1;--k)if(mu[k])
			{
				t+=(LL)mu[k]*k*k%MOD*Song(n/(d*k))%MOD;
				if(t<0)
					t+=MOD;
			}
			SU(ans,Mul(t,d));
		}
		printf("%d",ans);
	}

}

int main()
{
	scanf("%d%d",&ty,&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	scanf("%d",&q);
	Solver1::Solve();
	Solver3::Solve();
	//switch(ty) {
	//	case 1:
	//		Solver1::Solve();
	//		break;
	//	case 2:
	//		Solver2::Solve();
	//		break;
	//	case 3:
	//		Solver3::Solve();
	//}
	return 0;
}
