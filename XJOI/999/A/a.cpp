#pragma GCC optimize(2)
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

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=300+10;

int n;
Pir p[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i].fir);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i].sec);
	sort(p+1,p+n+1);
	int ans=0;
	for(int i=1,j=-1,sm=0;i<=n;++i)
	{
		GetMax(p[i].sec,min(0,sm+=p[i].sec));
		if(sm>=0&&(~j))
		{
			ans+=p[i].fir-p[j].fir;
			j=-1;
		}
		if(sm<0&&j==-1)
			j=i;
	}
	ans=ans*2+p[n].fir;
	printf("%d\n",ans);
	return 0;
}
