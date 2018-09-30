#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
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

const int N=1e6+10;
const int MOD=1e9+7;

int U(int x,int y)
{
	return (x+=y)>=MOD?x-MOD:x;
}

void SU(int &x,int y)
{
	(x+=y)>=MOD?x-=MOD:0;
}

int D(int x,int y)
{
	return (x-=y)<0?x+MOD:x;
}

void SD(int &x,int y)
{
	(x-=y)<0?x+=MOD:0;
}

int n,T,l[N],f[N];

int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i)
		scanf("%d",l+i);
	f[0]=1;
	for(int i=1,p=1;i<=n;++i)
	{
		for(;l[p]+n<l[i];++p);
		f[i]=D(U(f[i-1],f[i-1]),f[p-1]);
	}
	return 0;
}
