#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<map>

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

int n;

map<int,int> mp,mp0;

bool Update(map<int,int> &m,int x,int w)
{
	map<int,int>::iterator it=m.find(x);
	if(it==m.end())
	{
		m[x]=w;
		return true;
	}
	else
		return GetMin(it->sec,w);
}

bool Update(map<int,int> &m,map<int,int> &m0,int x,int w)
{
	map<int,int>::iterator it=m.find(x);
	if(it==m.end())
		return false;
	return Update(m0,x,it->sec+w);
}

void Song(int x,int fl=false,int d=0)
{
	//cout<<x<<" "<<d<<endl;
	if(fl)
	{
		if(!Update(mp,mp0,x,d))
			return;
	}
	else if(!Update(mp,x,d))
		return;
	if(x==1)
		return;
	Song(x>>1,fl,d+1);
	if(x&1)
		Song(((x-1)>>1)+1,fl,d+1);
}

int main()
{
	scanf("%d",&n);
	for(int i=1,a;i<=n;++i)
	{
		scanf("%d",&a);
		if(i==1)
			Song(a);
		else
		{
			mp0.clear();
			Song(a,true);
			swap(mp,mp0);
		}
	}
	int ans=0x3f3f3f3f;
	for(Pir p:mp)
		GetMin(ans,p.sec);
	printf("%d",ans);
	return 0;
}
