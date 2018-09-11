#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<unordered_map>

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

int n,m,q;
int w[N];

int Phi(int x)
{
	static unordered_map<int,int> mp;
	if(mp.count(x))
		return mp[x];
	int &res=mp[x];
	res=x;
	for(int i=2;i*i<=x;++i)if(x%i==0)
	{
		res=res/i*(i-1);
		do x/=i;
		while(x%i==0);
	}
	if(x>1)
		res=res/x*(x-1);
	return res;
}

int Qpow(int x,int y,int m)
{
	int res=1,fl=(pow(x,y)>m-0.5);
	for(;y;y>>=1,x=(LL)x*x%m)if(y&1)
		res=(LL)res*x%m;
	return res+fl*m;
}

int Query(int l,int r,int m)
{
	if(l==r)
		return w[l];
	if(m==1)
		return 1;
	return Qpow(w[l],Query(l+1,r,Phi(m)),m);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",w+i);
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;++i)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",Query(l,r,m)%m);
	}
	return 0;
}
