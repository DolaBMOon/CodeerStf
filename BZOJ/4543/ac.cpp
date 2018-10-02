#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn=100010;

typedef long long ll;

int n,cnt;
ll ans;
int to[maxn<<1],next[maxn<<1],head[maxn],md[maxn],son[maxn],fa[maxn];
ll mem[1000010];
ll *f[maxn],*g[maxn],*now=mem+1;

inline void add(int a,int b)
{
	to[cnt]=b,next[cnt]=head[a],head[a]=cnt++;
}

void dfs1(int x)
{
	md[x]=0;
	for(int i=head[x];i!=-1;i=next[i])  if(to[i]!=fa[x])
	{
		fa[to[i]]=x,dfs1(to[i]),md[x]=max(md[x],md[to[i]]+1);
		if(md[to[i]]>md[son[x]]) son[x]=to[i];
	}
}

void dfs2(int x)
{
	int i,j,y;
	if(son[x])
	{
		f[son[x]]=f[x]+1,g[son[x]]=g[x]-1;
		dfs2(son[x]);
	}
	f[x][0]=1,ans+=g[x][0];
	for(i=head[x];i!=-1;i=next[i])  if(to[i]!=fa[x]&&to[i]!=son[x])
	{
		y=to[i],f[y]=now,now+=md[y]+1,g[y]=now+md[y]+1,now+=md[y]*2+2,dfs2(y);
		for(j=md[y];j>=0;j--)
		{
			if(j)   ans+=f[x][j-1]*g[y][j];
			ans+=g[x][j+1]*f[y][j];
			g[x][j+1]+=f[x][j+1]*f[y][j];
		}
		for(j=0;j<=md[y];j++)
		{
			if(j)   g[x][j-1]+=g[y][j];
			f[x][j+1]+=f[y][j];
		}
	}
}

inline int rd()
{
	int ret=0,f=1;  char gc=getchar();
	while(gc<'0'||gc>'9') {if(gc=='-')    f=-f;   gc=getchar();}
	while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
	return ret*f;
}

int main()
{
	n=rd(),md[0]=-1;
	int i,a,b;
	memset(head,-1,sizeof(head));
	for(i=1;i<n;i++) a=rd(),b=rd(),add(a,b),add(b,a);
	dfs1(1);
	f[1]=now,now+=md[1]+1,g[1]=now+md[1]+1,now+=md[1]*2+2,dfs2(1);
	printf("%lld",ans);
	return 0;
}
