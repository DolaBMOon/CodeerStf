#pragma GCC optmize(2)
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

#define Pir pair<int,int>
#define fir first
#define sec second

ostream& operator<<(ostream &os,Pir p)
{
	os<<"("<<p.fir<<","<<p.sec<<")";
	return os;
}

const int N=1e6+10;
const int INF=0x3f3f3f3f3f3f3f3f;

struct Edge
{
	int v,w;
}edges[N<<1];

int n;
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

Pir stk[N];
int tp;
bool vis[N];

Pir lst[N<<1];
int ed,mx[N<<1],id[N<<1];

bool Dfs(int u)
{
	static int dep[N],fa[N];
	stk[++tp]=(Pir){u,dep[u]};
	vis[u]=true;
	for(int i=fir[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(e.v==fa[u])
			continue;
		if(vis[e.v])
		{
			for(Pir p(-1,0);p.fir!=e.v;)
			{
				p=stk[tp--];
				lst[++ed]=(Pir){p.fir,p.sec-stk[tp].sec};
			}
			lst[ed].sec=e.w;
			return true;
		}
		fa[e.v]=u;
		dep[e.v]=dep[u]+e.w;
		if(Dfs(e.v))
			return true;
	}
	--tp;
	return false;
}

int dp[N][2];

int Song(int u,int dep=0)
{
	int res=dep;
	vis[u]=true;
	for(int i=fir[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(vis[e.v])
			continue;
		GetMax(res,Song(e.v,dep+e.w));
		int t=dp[e.v][0]+e.w;
		if(t>dp[u][0])
		{
			dp[u][1]=dp[u][0];
			dp[u][0]=t;
		}
		else if(t>dp[u][1])
			dp[u][1]=t;
	}
	return res;
}

int sg[N<<4][2],m;

void Build(int o=1,int l=1,int r=m)
{
	if(l==r)
	{
		sg[o][0]=mx[l]+id[l];
		sg[o][1]=mx[l]-id[l];
		return;
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1;
	Build(lc,l,mid);
	Build(rc,mid+1,r);
	sg[o][0]=max(sg[lc][0],sg[rc][0]);
	sg[o][1]=max(sg[lc][1],sg[rc][1]);
}

int Query(int ql,int qr,int ty,int o=1,int l=1,int r=m)
{
	if(ql<=l&&r<=qr)
	{
		return sg[o][ty];
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1,res=-INF;
	if(ql<=mid)
		GetMax(res,Query(ql,qr,ty,lc,l,mid));
	if(qr>mid)
		GetMax(res,Query(ql,qr,ty,rc,mid+1,r));
	return res;
}

signed main()
{
	n=Read();
	for(int i=1,u,v,w;i<=n;++i)
	{
		u=Read();
		v=Read();
		w=Read();
		Adde(u,v,w);
	}
	Dfs(1);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=ed;++i)
		vis[lst[i].fir]=true;
	int ans=0;
	for(int i=1;i<=ed;++i)
		GetMax(ans,mx[i]=Song(lst[i].fir));
	for(int i=1;i<=n;++i)
		GetMax(ans,dp[i][0]+dp[i][1]);
	int sm=0;
	for(int i=1;i<=ed;++i)
	{
		id[i]=id[i-1]+lst[i-1].sec;
		lst[i+ed]=lst[i];
		mx[i+ed]=mx[i];
		sm+=lst[i].sec;
	}
	m=ed<<1;
	for(int i=ed+1;i<=m;++i)
		id[i]=id[i-1]+lst[i-1].sec;
	Build();
	for(int i=1,j=1;i<=ed;i++)
	{
		for(;id[j]-id[i]<=(sm>>1);++j);
		if(i+1<j)
			GetMax(ans,Query(i+1,j-1,0)-id[i]+mx[i]);
		if(j<i+ed)
			GetMax(ans,Query(j,i+ed-1,1)+id[i+ed]+mx[i+ed]);
	}
	printf("%lld",ans+1);
	return 0;
}
