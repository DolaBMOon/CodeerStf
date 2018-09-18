#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

const int N=55;

int n,ty[N],a[N],b[N],c[N],rt,lc[N],rc[N];

bool h[N];
int cnt=1;

vector<int> d[N];

int *nw;

bool Song(int u,int t)
{
	if(!u)
		return true;
	if(!t)
	{
		if(u!=*nw)
			return false;
		++nw;
		return Song(lc[u],ty[0])&&Song(rc[u],ty[1]);
	}
	else if(t==1)
	{
		if(!Song(lc[u],ty[2]))
			return false;
		if(u!=*nw)
			return false;
		++nw;
		return Song(rc[u],ty[3]);
	}
	else
	{
		if(!Song(lc[u],ty[4]))
			return false;
		if(!Song(rc[u],ty[5]))
			return false;
		if(u!=*nw)
			return false;
		++nw;
		return true;
	}
}

bool Check()
{
	//DivHim();
	//for(int i=1;i<=n;++i)
	//	cout<<i<<":"<<lc[i]<<" "<<rc[i]<<endl;
	//DivHer();
	//if(lc[1]==2&&rc[1]==0&&lc[2]==0&&rc[2]==4&&lc[3]==0&&rc[3]==0&&lc[4]==0&&rc[4]==3)
	//	DivHim();
	nw=a+1;
	if(!Song(rt,0))
		return false;
	nw=b+1;
	if(!Song(rt,1))
		return false;
	nw=c+1;
	if(!Song(rt,2))
		return false;
	return true;
}

bool Dfs(int x,int y)
{
	if(cnt==n)
		return Check();
	if(d[x].empty())
		return false;
	if(y>=(int)d[x].size())
		return Dfs(x+1,0);
	int u=d[x][y];
	//cout<<x<<","<<y<<":"<<u<<endl;
	for(int i=0;i<=n;++i)if(!h[i])
	{
		if((lc[u]=i))
		{
			h[i]=true;
			d[x+1].push_back(lc[u]);
			++cnt;
		}
		for(int j=0;j<=n;++j)if(!h[j])
		{
			if((rc[u]=j))
			{
				h[j]=true;
				d[x+1].push_back(rc[u]);
				++cnt;
			}
			if(Dfs(x,y+1))
				return true;
			if(rc[u])
			{
				rc[u]=0;
				h[j]=false;
				d[x+1].pop_back();
				--cnt;
			}
		}
		if(lc[u])
		{
			lc[u]=0;
			h[i]=false;
			d[x+1].pop_back();
			--cnt;
		}
	}
	return false;
}

int main()
{
	static char s[10];
	for(int i=0;i<6;++i)
	{
		scanf("%s",s);
		switch(s[2])
		{
			case 'e':
				ty[i]=0;
				break;
			case 0:
				ty[i]=1;
				break;
			default:
				ty[i]=2;
				break;
		}
	}
	scanf("%d",&n);
	if(n>10)
		return puts("Impossible"),0;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		scanf("%d",b+i);
	for(int i=1;i<=n;++i)
		scanf("%d",c+i);
	h[rt=a[1]]=true;
	d[1].push_back(rt);
	puts(Dfs(1,0)?"Possible":"Impossible");
	return 0;
}
