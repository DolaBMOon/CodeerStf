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

#define LL long long

const int N=5005;

int n;
LL a[N];
int fir[N],nxt[N+N],to[N+N],tote;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int lst[N][N],ans[N];

void Append(int *x,int y)
{
	x[++(*x)]=y;
}

int dep[N];

void Dfs(int u,int fa=0)
{
	dep[u]=dep[fa]+1;
	int *x=lst[u],*y;
	Append(x,u);
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		Dfs(v,u);
		y=lst[v];
		for(int j=*y;j>=1;--j)
			Append(x,y[j]);
	}
	for(int i=*x;i>=1;--i)
		for(int j=*x;j>=1;--j)
			for(int k=*x;k>=1;--k)
			{
				ans[u]+=(dep[x[i]]<dep[x[j]]&&dep[x[i]]<dep[x[k]]&&a[x[i]]>a[x[j]]&&a[x[j]]>a[x[k]]);
				//if(dep[x[i]]<dep[x[j]]&&dep[x[i]]<dep[x[k]]&&a[x[i]]>a[x[j]]&&a[x[j]]>a[x[k]])
				//{
				//	if(u==1)
				//		cout<<x[i]<<","<<x[j]<<","<<x[k]<<endl;
				//}
			}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Dfs(1);
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}
