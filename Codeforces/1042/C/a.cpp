#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=2e5+10;
const int INF=0x3f3f3f3f;

int n;
Pir p[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&p[i].fir);
		p[i].sec=i;
	}
	sort(p+1,p+n+1);
	int l0=INF,r0=-INF,l1=INF,r1=-INF,l2=INF,r2=-INF;
	for(int i=1;i<=n;++i)
	{
		if(p[i].fir<0)
		{
			GetMin(l0,i);
			GetMax(r0,i);
		}
		else if(p[i].fir==0)
		{
			GetMin(l1,i);
			GetMax(r1,i);
		}
		else
		{
			GetMin(l2,i);
			GetMax(r2,i);
		}
	}
	if(l1==1&&r1==n)
	{
		for(int i=1;i<n-1;++i)
			printf("1 %d %d\n",i,i+1);
		printf("2 %d\n",n-1);
		return 0;
	}
	if(l0>=r0&&l2>r2)
	{
		for(int i=1;i<n-1;++i)
			printf("1 %d %d\n",p[i].sec,p[i+1].sec);
		printf("2 %d\n",p[n-1].sec);
	}
	else
	{
		static bool ban[N];
		vector<int> v;
		if(l0<=r0&&((r0-l0+1)&1))
		{
			v.emplace_back(p[r0].sec);
			//printf("2 %d\n",p[r0].sec);
			ban[p[r0].sec]=true;
		}
		for(int i=l1;i<=r1;++i)
		{
			//printf("2 %d\n",p[i].sec);
			v.emplace_back(p[i].sec);
			ban[p[i].sec]=true;
		}
		for(int i=0;i<(int)v.size()-1;++i)
			printf("1 %d %d\n",v[i],v[i+1]);
		if(v.size())
			printf("2 %d\n",v.back());
		int x=1;
		for(;ban[x];++x);
		for(int i=1;i<=n;++i)if(!ban[i]&&i!=x)
			printf("1 %d %d\n",i,x);
	}
	return 0;
}
