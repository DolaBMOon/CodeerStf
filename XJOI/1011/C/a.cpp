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

const int P=100000+10;

int n,mxp,ans;
int p[P],totp;
bool vis[P];

void Dfs(int k,int nw)
{
	if(k>totp||p[k]*nw>n)
	{
		++ans;
		return;
	}
	Dfs(k+1,nw);
	for(int f=nw*p[k],t=p[k]*p[k];f<=n;f*=t)
		Dfs(k+1,f);
}

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
	Dfs(1,1);
	cout<<ans;
	return 0;
}
