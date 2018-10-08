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

const int MX=5200;

int p[MX],totp,used;
bool vis[MX];

void Prework()
{
	for(int i=2;i<MX;++i)
	{
		if(!vis[i])
			p[++totp]=i;
		for(int j=1;j<=totp&&p[j]*i<MX;++j)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
}

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

const int N=520;

int n,ans[N];

signed main()
{
	Prework();
	scanf("%lld",&n);
	for(int i=0;i<=n+1;++i)
		ans[i]=1;
	for(int i=1,x,y;i<=1000000;++i)
	{
		x=rand()%n+1;
		y=rand()%n+1;
		if(abs(x-y)<=1||Gcd(ans[x],ans[y])>1)
			continue;
		int j;
		for(j=1;ans[x-1]%p[j]==0||ans[x+1]%p[j]==0||ans[y-1]%p[j]==0||ans[y+1]%p[j]==0;++j);
		if(ans[x]%p[j])
			ans[x]*=p[j];
		if(ans[y]%p[j])
			ans[y]*=p[j];
	}
	for(int i=1;i<=n;++i)
		printf("%lldll,",ans[i]);
	return 0;
}
