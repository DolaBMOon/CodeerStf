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

const int M=200000+10;

int n,mxp,ans;
int p[M],totp;
bool vis[M];
int t[M],t2[M],lst[M],ed;

signed main()
{
	cin>>n>>mxp;
	for(int i=2;i<=mxp;++i)
	{
		if(!vis[i])
		{
			vis[i]=true;
			p[++totp]=i;
		}
		for(int j=1;j<=totp&&p[j]*i<=mxp;++j)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
	for(int i=1,j,k;i<=n;i=j+1)
	{
		j=n/(k=n/i);
		lst[++ed]=k;
	}
	return 0;
}
