#pragma GCC optimize("Ofast")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<map>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=250000+10;
const int M=520;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,m,k;
int h[N];
Pir p[M];

map<int,int> mp;

int Calc(int h,int r=m)
{
	if(mp.count(h))
		return mp[h];
	int &cnt=mp[h];
	if(h<=0)
		return cnt=0;
	if(p[r].fir<h)
		return cnt=INF;
	int left=0,mid,right=r,res=0;
	while(left<=right)
		if(p[mid=(left+right)>>1].fir<h)
			left=(res=mid)+1;
		else
			right=mid-1;
	int d=(h-p[res].fir-1)/p[res+1].sec+1;
	cnt=d;
	h-=d*p[res+1].sec;
	return cnt+=Calc(h,res);
}

signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%lld",h+i);
	for(int i=1;i<=m;++i)
		scanf("%lld%lld",&p[i].fir,&p[i].sec);
	sort(p+1,p+m+1);
	int t=m;
	m=1;
	for(int i=2;i<=t;++i)
	{
		for(;m>0&&p[i].sec>=p[m].sec;--m);
		p[++m]=p[i];
	}
	int cnt=0;
	for(int i=n,t;i>0;--i)
		if((t=k-Calc(h[i]))>=0)
		{
			k=t;
			++cnt;
		}
		else
			break;
	printf("%lld %lld\n",cnt,k);
	return 0;
}
