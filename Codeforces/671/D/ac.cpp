#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

typedef long long LL;

const LL INF=1e15;
const int N=1e6;

int n,m,head[N+10],w[N+10],l[N+10],r[N+10],num[N+10],tot;

LL f[N+10];

struct data {
	int next,num;
}edge[N+10];

vector <int> du[N+10],dv[N+10];

void Add(int u,int v) {
	edge[++tot].next=head[u];
	edge[tot].num=v;
	head[u]=tot;
}

namespace pre {
	int cnt=0;
	void Dfs(int x,int fat) {
		l[x]=cnt+1;
		for (int i=0;i<(int)du[x].size();i++)
			num[du[x][i]]=++cnt;
		for (int i=head[x];i!=-1;i=edge[i].next) {
			int kx=edge[i].num;
			if (kx==fat) continue;
			Dfs(kx,x);
		}
		r[x]=cnt;
	}
}

namespace tree {
	struct node {
		int l,r;
		LL minx,lazy;
	}t[N*2+10];
	void Build(int x,int l,int r) {
		t[x].l=l;
		t[x].r=r;
		t[x].lazy=0;
		t[x].minx=INF;
		if (l==r) return;
		int mid=(l+r)/2;
		Build(x*2,l,mid);
		Build(x*2+1,mid+1,r);
	}
	void Pushdown(int x) {
		if (t[x].lazy==0) return;
		t[x*2].lazy+=t[x].lazy;
		t[x*2+1].lazy+=t[x].lazy;
		t[x*2].minx=min(t[x*2].minx+t[x].lazy,INF);
		t[x*2+1].minx=min(t[x*2+1].minx+t[x].lazy,INF);        
		t[x].lazy=0;
	}
	void Update(int x) {
		t[x].minx=min(t[x*2].minx,t[x*2+1].minx);
	}
	void Add1(int x,int loc,LL va) {
		if (t[x].l==t[x].r) {
			t[x].minx=va;
			return;
		}
		int mid=(t[x].l+t[x].r)/2;
		Pushdown(x);
		if (loc<=mid) Add1(x*2,loc,va);
		else Add1(x*2+1,loc,va);
		Update(x);
	}
	void Add2(int x,int l,int r,LL va) {
		if (l>r) return;
		int nowl=t[x].l,nowr=t[x].r;
		if (nowl>r||nowr<l) return;
		if (nowl>=l&&nowr<=r) {
			t[x].lazy+=va;
			t[x].minx=min(INF,t[x].minx+va);
			return;
		}
		Pushdown(x);
		Add2(x*2,l,r,va);
		Add2(x*2+1,l,r,va);
		Update(x);
	}
	LL Query(int x,int l,int r) {
		if (l>r) return INF;
		int nowl=t[x].l,nowr=t[x].r;
		if (nowl>r||nowr<l) return INF;
		if (nowl>=l&&nowr<=r) return t[x].minx;
		Pushdown(x);
		return min(Query(x*2,l,r),Query(x*2+1,l,r));
	}
}

namespace task {
	void Dfs(int x,int fat) {
		LL sum=0;
		for (int i=head[x];i!=-1;i=edge[i].next) {
			int kx=edge[i].num;
			if (kx==fat) continue;
			Dfs(kx,x);
			sum=min(INF,f[kx]+sum);
		}
		if (sum==INF) {
			printf("-1\n");
			exit(0);
		}
		if (x==1) printf("%lld\n",sum);
		for (int i=0;i<(int)du[x].size();i++) {
			int kx=du[x][i];
			tree::Add1(1,num[kx],w[kx]+sum);
		}
		for (int i=head[x];i!=-1;i=edge[i].next) {
			int kx=edge[i].num;
			if (kx==fat) continue;
			tree::Add2(1,l[kx],r[kx],sum-f[kx]);
		}
		for (int i=0;i<(int)dv[x].size();i++) {
			int kx=dv[x][i];
			tree::Add1(1,num[kx],INF);
		}
		f[x]=tree::Query(1,l[x],r[x]);
	}
}

int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		Add(u,v);
		Add(v,u);
	}
	for (int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d%d",&u,&v,&w[i]);
		du[u].push_back(i);
		dv[v].push_back(i);
	}
	pre::Dfs(1,-1);
	tree::Build(1,1,m);
	task::Dfs(1,-1);
	return 0;
}
