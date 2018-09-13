#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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

const int N=1e5+10;

int CASE;
int n,mx[N];
Pir p[N];

void Work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&p[i].fir,&p[i].sec);
	sort(p+1,p+n+1);
	mx[n+1]=0;
	for(int i=n;i>0;--i)
		mx[i]=max(p[i].sec,mx[i+1]);
	int ans=mx[1];
	for(int i=1,t=0;i<=n;++i)
	{
		GetMax(t,p[i].fir);
		GetMin(ans,t+mx[i+1]);
	}
	printf("Case %d: %d\n",++CASE,ans);
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
