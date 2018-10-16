#include<bits/stdc++.h>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

#define int long long

const int _B=1e6;

char Nc()
{
	static char buf[_B],*p=buf,*q=buf;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
}

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int sum=ch-48;
	while(isdigit(ch=Nc()))
		sum=sum*10+ch-48;
	return sum;
}

const int N=1e6+10;

struct Edge
{
	int v,w;
}edges[N<<1];

int n,ans,sm;
int fir[N],nxt[N<<1],tote;

void Adde(int u,int v,int w)
{
	edges[++tote]=(Edge){v,w};
	nxt[tote]=fir[u];
	fir[u]=tote;
	edges[++tote]=(Edge){u,w};
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int f[N],g[N];

void Dfs(int u,int fa=0)
{
	for(int i=fir[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(e.v==fa)
			continue;
		Dfs(e.v,u);
		f[u]+=max(f[e.v],e.w+g[e.v]);
		GetMax(g[u],e.w+g[e.v]);
	}
}

signed main()
{
	//freopen("portal.in","r",stdin);
	//freopen("portal.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1,u,v,w;i<n;++i)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		Adde(u,v,w);
		ans+=w;
	}
	ans<<=1;
	Dfs(1);
	printf("%lld",ans-max(f[1],g[1]));
	return 0;
}
