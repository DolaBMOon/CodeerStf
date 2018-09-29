#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

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
#define Pir pair<int,int>
#define fir first
#define sec second
#define Mit map<int,int>::iterator

const int N=1e6+10;
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

void SD(int &x,int y)
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

int Sqr(int x)
{
	return (LL)x*x%MOD;
}

int n,q,a[N];

int p[N],totp,mu[N],s[N],co[N],ny[N],ans;
bool vis[N];
map<int,int> S;
vector<int> dv[N];

int Cal(int x)
{
	return Mul(Sqr(s[x]),co[x]);
}

void Prework()
{
	mu[1]=1;
	for(int i=2;i<N;++i)
	{
		if(!vis[i])
		{
			p[++totp]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=totp&&p[j]*i<N;++j)
		{
			vis[p[j]*i]=true;
			if(i%p[j])
				mu[p[j]*i]=-mu[i];
			else
				break;
		}
	}
	for(int i=1;i<N;++i)if(mu[i]==-1)
		mu[i]+=MOD;

	for(int i=1;i<N;++i)
		for(int j=i;j<N;j+=i)
			dv[j].emplace_back(i);

	for(int i=1;i<=n;++i)
		for(int j:dv[a[i]])
			SU(s[j],a[i]);

	ny[1]=1;
	for(int i=2;i<N;++i)
		ny[i]=Mul((MOD-MOD/i),ny[MOD%i]);

	for(int k=1;k<N;++k)
	{
		for(int d:dv[k])
			SU(co[k],Mul(mu[k/d],ny[d]));
		SU(ans,Cal(k));
	}

	for(int i=1;i<=n;++i)
		S[i]=a[i];
	S[n+1]=233;
}

void Split(int x)
{
	Mit it=S.upper_bound(x);
	--it;
	S[x]=it->sec;
}

void Chg(int n,int x,int y)
{
	for(int i:dv[x])
	{
		SD(ans,Cal(i));
		SD(s[i],Mul(n,x));
		SU(ans,Cal(i));
	}
	for(int i:dv[y])
	{
		SD(ans,Cal(i));
		SU(s[i],Mul(n,y));
		SU(ans,Cal(i));
	}
}

void Mof(int l,int r,int x)
{
	Split(l);
	Split(r+1);
	for(Mit it=S.find(l),t;it->fir<=r;)
	{
		t=it;
		++it;
		Chg(it->fir-t->fir,t->sec,x);
		S.erase(t);
	}
	S[l]=x;
}

int main()
{
	scanf("%*d%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	Prework();
	printf("%d\n",ans);
	scanf("%d",&q);
	for(int i=1,l,r,x;i<=q;++i)
	{
		scanf("%d%d%d",&l,&r,&x);
		Mof(l,r,x);
		printf("%d\n",ans);
	}
	return 0;
}
