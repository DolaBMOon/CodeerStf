#pragma GCC optimize(2)
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

const int MOD=1e9+7;

int Mul(int x,int y)
{
	return x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

const int B=1e5+10;

int n,ans;
int p[B],totp,phi[B];
bool vis[B];

void Prework()
{
	for(int i=2;i<B;++i)
	{
		if(!vis[i])
		{
			p[++totp]=i;
			phi[i]=i-1;
		}
		for(int j=1,k;j<=totp&&(k=p[j]*i)<B;++j)
		{
			vis[k]=true;
			if(i%p[j])
				phi[k]=phi[i]*(p[j]-1);
			else
			{
				phi[k]=phi[i]*p[j];
				break;
			}
		}
	}
}

signed main()
{
	Prework();
	scanf("%lld",&n);
	for(int t=2;t*t<=n;++t)
		for(int x=t*t,ka=2;x<=n;x*=t,++ka)
			SU(ans,Mul(n/ka,phi[ka]));
	SU(ans,U(ans,U(Mul(n-1,n),Mul(n,n))));
	printf("%lld",ans);
	return 0;
}
