#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<set>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=300000+10;

int n,m;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int rp[N],fa[N],mn[N];

int Find(int u)
{
	return fa[u]?(fa[u]=Find(fa[u])):u;
}

int Merge(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x!=y)
	{
		fa[x]=y;
		GetMin(mn[x],mn[y]);
	}
}

void Join(int u,int l,int r)
{
	for(int i=fir[u],v;i;i=nxt[i])if(l<=(v=to[i])&&v<=r)
		Merge(u,v);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	for(int i=1,j=2,o;i<=n&&j<=n;i=o+1)
	{
		for(int k=i;k<j;++k)
		{
			fa[k]=0;
			mn[k]=k;
		}
		for(int k=i;k<j;++k)
			Join(k,i,j-1);
		for(bool fl=true;fl&&j<=n;++j)
		{
			fa[j]=0;
			mn[j]=j;
			for(int k=fir[j],v,x,y;k;k=nxt[k])if(i<=(v=to[k])&&v<=j)
			{
				x=Find(j);
				y=Find(v);
				if(x==y)
				{
					o=mn[x];
					fl=false;
				}
				else
				{
					fa[x]=y;
					GetMin(mn[x],mn[y]);
				}
			}
			if(!fl)
				break;
			if(j==n)
			{
				++j;
				o=n;
				break;
			}
		}
		for(int k=i;k<=o;++k)
			rp[k]=j-1;
	}
	for(int i=1;i<=n;++i)
		Whats(rp[i]);
	return 0;
}
