#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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

const int M=2e6+10;

int n,mxp;

int p[M/10],totp;
bool vis[M];

void Prework()
{
	for(int i=2;i<=mxp;++i)
	{
		if(!vis[i])
			p[++totp]=i;
		for(int j=1;j<=totp&&p[j]*i<=mxp;++j)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
}

int ans;

void Dfs(int k,int nw)
{
	if(k>totp||nw*p[k]>n)
	{
		++ans;
		return;
	}
	if(nw*p[k]*p[k]>n)
	{
		ans+=upper_bound(p+1,p+totp+1,n/nw)-p-k+1;
		return;
	}
	Dfs(k+1,nw);
	for(int i=nw*p[k],j=p[k]*p[k];i<=n;i*=j)
		Dfs(k+1,i);
}

signed main()
{
	cin>>n>>mxp;
	Prework();
	Dfs(1,1);
	cout<<ans;
	return 0;
}
