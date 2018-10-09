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
#define Pir pair<int,int>
#define fir first
#define sec second

const int N=2e5+10;

int n,ans,fa[N];
Pir p[N];

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

void Work()
{
	for(int i=1,j,d;i<=n;i=j+1)
	{
		d=p[i].fir;
		for(j=i;j<n&&d>1;d=Gcd(d,p[++j].fir));
		for(int k=i;k<j;++k)if(Gcd(p[k].fir,p[j].fir)==1)
			Hb(p[k].sec,p[j].sec);
	}
}

int main()
{
	scanf("%d",&n);
	ans=n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&p[i].fir);
		p[i].sec=i;
		if(p[i].fir==1)
		{
			puts("1");
			return 0;
		}
	}
	sort(p+1,p+n+1);
	Work();
	for(int cc=10000000/n;--cc;)
	{
		random_shuffle(p+1,p+n+1);
		Work();
	}
	printf("%d",ans);
	return 0;
}
