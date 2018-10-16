#pragma GCC optimize("Ofast", "inline")
#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 3000005;
const LL INF = (LL)1e17;

int n, m;
int vis_e[N], vis[N], flg[N], fw[N], fa[N], cir[N], va[N];
LL ans, f[N], g[N], d[N], dw[N];

inline void Rd(int &x) {
	char c = getchar(); x = 0;
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
}

int yun = 1, las[N], to[N << 1], wi[N << 1], pre[N << 1];
inline void Add(int a, int b, int c) {
	to[++yun] = b; wi[yun] = c; pre[yun] = las[a]; las[a] = yun;
}

void Dfs_(int x) {
	vis[x] = 1;
	for (int i = las[x]; i; i = pre[i]) {
		if (vis_e[i >> 1]) continue;
		vis_e[i >> 1] = 1;
		if (!vis[to[i]]) {
			fw[to[i]] = wi[i];
			fa[to[i]] = x;
			Dfs_(to[i]);
		} else {
			cir[++m] = to[i];
			va[1] = wi[i];
			flg[to[i]] = 1;
			for (int t = x; t != to[i]; t = fa[t]) {
				cir[++m] = t;
				va[m] = fw[t];
				flg[t] = 1;
			}
		}
	}
}

void Dfs(int x, int fat) {
	for (int i = las[x]; i; i = pre[i]) {
		if (to[i] == fat || flg[to[i]]) continue;
		Dfs(to[i], x);
		f[x] = max(f[x], f[to[i]]);
		f[x] = max(f[x], g[x] + g[to[i]] + wi[i]);
		g[x] = max(g[x], g[to[i]] + wi[i]);
	}
}

namespace SE {
	int B;
	LL t[(N << 2) + 53];
	void Bu(int _n) {
		for (B = 1; B < _n + 2; B <<= 1);
		for (int i = B + 1; i <= B * 2; ++i) t[i] = -INF;
		for (int i = 1; i <= _n; ++i) t[B + i] = -d[i] + dw[i];
		for (int i = B - 1; i; --i) t[i] = max(t[i << 1], t[i << 1 | 1]);
	}
	LL Qr(int l, int r) {
		LL re = -INF;
		if (l > r) return -INF;
		for (l += B - 1, r += B + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if (~l & 1) re = max(re, t[l ^ 1]);
			if (r & 1) re = max(re, t[r ^ 1]);
		}
		return re;
	}
}

LL Solve(LL re = 0) {
	//cerr << "solving : " << m << endl;
	for (int i = 1; i <= m; ++i) {
		va[i + m] = va[i + m + m] = va[i];
		dw[i] = dw[i + m] = dw[i + m + m] = g[cir[i]];
	}
	for (int i = 1; i <= m * 3; ++i) {
		d[i + 1] = d[i] + va[i];
	}
	LL sum = d[m + 1];
	SE::Bu(m * 3);
	for (int i = 1; i <= m; ++i) {
		int id = i + m;
		int lo = id - m + 1, hi = id;
		for (int md; lo < hi; ) {
			md = (lo + hi) >> 1;
			if (d[id] - d[md] > sum - d[id] + d[md]) {
				lo = md + 1;
			} else {
				hi = md;
			}
		}
		int rest = m - (id - lo + 1);
		LL q1 = SE::Qr(lo, id - 1);
		LL q2 = SE::Qr(id + 1, id + rest);
		re = max(re, d[id] + dw[id] + max(q1, q2));
	}
	return re;
}

struct Edge
{
	int v,w;
}edges[N<<1];

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

//Pir stk[N];
int tp;
//bool vis[N];

//Pir lst[N<<1];
int ed,mx[N<<1],id[N<<1];

bool Dfs(int u)
{
	static int dep[N],fa[N];
	//stk[++tp]=(Pir){u,dep[u]};
	vis[u]=true;
	for(int i=fir[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(e.v==fa[u])
			continue;
		if(vis[e.v])
		{
			//for(Pir p(-1,0);p.fir!=e.v;)
			//{
			//	p=stk[tp--];
			//	lst[++ed]=(Pir){p.fir,p.sec-stk[tp].sec};
			//}
			//lst[ed].sec=e.w;
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
		//GetMax(res,Song(e.v,dep+e.w));
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

int sg[N<<4][2];

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
	if(ql<=mid);
		//GetMax(res,Query(ql,qr,ty,lc,l,mid));
	if(qr>mid);
		//GetMax(res,Query(ql,qr,ty,rc,mid+1,r));
	return res;
}

int main() {
	Rd(n);
	for (int i = 1, x, y, z; i <= n; ++i) {
		Rd(x), Rd(y), Rd(z);
		Add(x, y, z); Add(y, x, z);
	}
	Dfs_(1);
	for (int i = 1; i <= n; ++i)
		if (flg[i]) Dfs(i, 0), ans = max(ans, f[i]);
	//cerr << "in tree : " << ans << endl;
	ans = max(ans, Solve());
	printf("%lld\n", ans + 1);

	return 0;
}
