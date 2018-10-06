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

int main()
{
	scanf("%d",&n);
	ans=n;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	random_shuffle(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		int d=a[i],j;
		for(j=i+1;d!=1&&j<=n;++j)
			d=Gcd(d,a[j]);
		if(d==1)
		{
			for(int k=i;k<=j;++k)
				for(int l=k+1;l<=j;++l)if(Gcd(a[k],a[l])==1)
					Hb(k,l);
		}
	}
	printf("%d",ans);
	return 0;
}
