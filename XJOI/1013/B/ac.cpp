#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<stack>
#include<cassert>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mem(x,y) memset(x,y,sizeof x)
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
const int INF=2e9;
const db eps=1e-12;
template<typename T>
inline void read(T &x) {
	x=0; int f=1; char ch=getchar();
	while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
	while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
	x*=f;
}
//==========================head template==========================
const int N=3010,lgN=12;
int n,p,q;
int head[N],nxt[N<<1],to[N<<1],lst=0;
inline void adde(int x,int y) {
	nxt[++lst]=head[x]; to[lst]=y; head[x]=lst;
}
namespace Brute20 {
	int ans=0;
	bool vis[N];
	void dfs(int u,int st) {
		if(st==q) {
			++ans; return;
		}
		for(int i=head[u];i;i=nxt[i])
			if(!vis[to[i]]) {
				int v=to[i];
				vis[v]=1;
				dfs(v,st+1);
				vis[v]=0;
			}
	}
	void Dfs(int u,int st) {
		if(st==p) {
			for(int i=1;i<=n;i++)
				if(!vis[i]) vis[i]=1,dfs(i,0),vis[i]=0;
			return;
		}
		for(int i=head[u];i;i=nxt[i])
			if(!vis[to[i]]) {
				int v=to[i];
				vis[v]=1;
				Dfs(v,st+1);
				vis[v]=0;
			}
	}
	void main() {
		for(int i=1;i<=n;i++)
			vis[i]=1,Dfs(i,0),vis[i]=0;
		printf("%d\n",ans);
	}
}
namespace Brute10 {
	ll ans=0;
	void main() {
		for(int i=p+1;i<=n;i++) {
			int st=i-p-1;
			ans+=max(0,n-i-q)+max(0,st-q);
		}
		printf("%lld\n",ans<<2ll);
	}
}
namespace Solver {
	int anc[N][lgN+3];
	int dep[N],fa[N],mdep[N];
	int sz[N];
	ll f[N],g[N];
	void Build(int u) {
		sz[u]=1;
		for(int i=head[u];i;i=nxt[i])
			if(to[i]!=fa[u]) {
				int v=to[i];
				dep[v]=dep[u]+1;
				anc[v][0]=fa[v]=u;
				Build(v);
				sz[u]+=sz[v];
				mdep[u]=max(mdep[u],mdep[v]);
			}
	}
	ll tmp[N][N];
	void DP_f(int u) {
		for(int i=head[u];i;i=nxt[i])
			if(to[i]!=fa[u]) DP_f(to[i]);
		tmp[u][0]=1;
		for(int i=head[u];i;i=nxt[i])
			if(to[i]!=fa[u]) {
				int v=to[i];
				for(int j=0;j<q;j++)
					f[u]+=tmp[u][j]*tmp[v][q-1-j];
				for(int j=1;j<=q;j++)
					tmp[u][j]+=tmp[v][j-1];
			}
	}
	ll tmp2[N][N];
	void DP_g(int u) {
		tmp2[u][0]=1;
		if(u!=1) {
			//printf("ask::%lld\n",tmp[u][-1]);
			//printf("DP_g::%d %lld\n",u,tmp[u][-2]);
			int f=fa[u];
			for(int j=1;j<=q;j++) {
				tmp2[u][j]=tmp2[f][j-1]+tmp[f][j-1];
				if(j>=2) tmp2[u][j]-=tmp[u][j-2];
				else tmp2[u][j]-=1;
			}
		}
		for(int i=head[u];i;i=nxt[i])
			if(to[i]!=fa[u]) DP_g(to[i]);
		if(u!=1)
			for(int i=0;i<q;i++)
				g[u]+=tmp[u][i]*tmp2[u][q-i];
	}
	inline void Get_anc() {
		for(int j=1;j<=lgN;j++)
			for(int i=1;i<=n;i++)
				anc[i][j]=anc[anc[i][j-1]][j-1];
	}
	inline int lca(int x,int y) {
		if(dep[x]<dep[y]) swap(x,y);
		for(int i=lgN;i>=0;i--) if(dep[anc[x][i]]>=dep[y]) x=anc[x][i];
		if(x==y) return x;
		for(int i=lgN;i>=0;i--) if(anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
		return fa[x];
	}
	inline int dist(int x,int y) {
		int z=lca(x,y);
		return dep[x]+dep[y]-2*dep[z];
	}
	ll sum[N],all;
	void dfs(int u) {
		for(int i=head[u];i;i=nxt[i])
			if(to[i]!=fa[u]) {
				int v=to[i];
				sum[v]=f[v]+sum[u];
				dfs(v);
			}
	}
	inline void Init() {
		dep[1]=1; Build(1);
		DP_f(1);
		DP_g(1);
		Get_anc();
		for(int i=1;i<=n;i++)
			all+=f[i];
		sum[1]=f[1]; dfs(1);
	}
	inline ll Work(int x,int y) {
		int z=lca(x,y);
		//printf("%d %d %d %lld\n",x,y,z,all-(sum[x]+sum[y]-sum[z]-sum[fa[z]])-g[z]);
		return all-(sum[x]+sum[y]-sum[z]-sum[fa[z]])-g[z];
	}
	ll ans=0;
	void main() {
		Init();
		/*
			 printf("sz:"); for(int i=1;i<=n;i++)  printf("%d ",sz[i]); puts("");
			 printf("fa:"); for(int i=1;i<=n;i++)  printf("%d ",fa[i]); puts("");
			 printf("dep:"); for(int i=1;i<=n;i++) printf("%d ",dep[i]); puts("");
			 printf("f:"); for(int i=1;i<=n;i++)   printf("%lld ",f[i]); puts("");
			 printf("g:"); for(int i=1;i<=n;i++)   printf("%lld ",g[i]); puts("");
			 printf("sum:"); for(int i=1;i<=n;i++) printf("%lld ",sum[i]); puts("");
			 puts("tmp:");
			 for(int i=1;i<=n;i++) {
			 for(int j=0;j<=q;j++)
			 printf("%lld ",tmp[i][j]);
			 puts("");
			 }
			 puts("tmp2:");
			 for(int i=1;i<=n;i++) {
			 for(int j=0;j<=q;j++)
			 printf("%lld ",tmp2[i][j]);
			 puts("");
			 }     
		//*/
		//printf("all=%lld\n",all);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dist(i,j)==p) {
					//ll add=Work(i,j);
					//printf("%d %d %lld\n",i,j,add);
					ans+=Work(i,j);
				}
		//assert(p!=q);
		ans<<=2;
		printf("%lld\n",ans);
	}
}
int in[N];
signed main() {
	//printf("ask:%d\n",in[-1]);
	read(n); read(p); read(q);
	for(int i=1;i<n;i++) {
		int x,y; read(x); read(y);
		adde(x,y); adde(y,x);
		++in[x]; ++in[y];
	}
	//if(n<=500) {Brute20::main(); return 0;}
	//int cnt=0;
	//for(int i=1;i<=n;i++) cnt+=(in[i]==1);
	//if(cnt==2) {Brute10::main(); return 0;}
	Solver::main();
	return 0;
}
