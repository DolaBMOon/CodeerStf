#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<cmath>

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

#define Gcd(x,y) __gcd(x,y)

const int N=2e5+10;
const int M=100;

int n,ans,m,a[N],fa[N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

void Hb(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x!=y)
	{
		fa[x]=y;
		--ans;
	}
}

void Solve(int l,int r)
{
	int d=0;
	for(int i=l;i<=r;++i)
		d=Gcd(d,a[i]);
	if(d==1)
	{
		for(int i=l;i<=r;++i)
			for(int j=i+1;j<=r;++j)if(Gcd(a[i],a[j])==1)
				Hb(i,j);
		return;
	}
	for(int i=1;i<=n;++i)if(Gcd(d,a[i])==1)
		for(int j=l;j<=r;++j)if(Gcd(a[i],a[j])==1)
			Hb(i,j);
}

int main()
{
	scanf("%d",&n);
	ans=n;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	random_shuffle(a+1,a+n+1);
	for(int i=1;i<=n;i+=M)
		Solve(i,i+M-1);
	printf("%d",ans);
	return 0;
}
