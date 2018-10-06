#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=2e5+10;

int n,ans;
Pir p[N];

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

int fa[N];

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
	{
		scanf("%d",&p[i].fir);
		p[i].sec=i;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<n;++i)if(Gcd(p[i].fir,p[i+1].fir)==1)
		Hb(p[i].sec,p[i+1].sec);
	for(int cc=50;cc--;)
	{
		random_shuffle(p+1,p+n+1);
		for(int i=1;i<n;++i)if(Gcd(p[i].fir,p[i+1].fir)==1)
			Hb(p[i].sec,p[i+1].sec);
	}
	printf("%d",ans);
	return 0;
}
