#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int read(){
	static int x; static char c;
	x=0; c=getchar();
	for (;!(c>='0'&&c<='9');c=getchar());
	for (; (c>='0'&&c<='9');c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x;
}

int n, m, T, pre[303000];
vector<int>G[303000];
ll sum[303000];

struct TR{
	int ch[2], fa, rev;
}tr[404000];
#define lc tr[x].ch[0]
#define rc tr[x].ch[1]
inline bool isrt(int x){
	return tr[tr[x].fa].ch[0]!=x&&tr[tr[x].fa].ch[1]!=x;
}
inline int dir(int x){
	return tr[tr[x].fa].ch[1]==x;
}
int GF(int x){
	for (;tr[x].fa;x=tr[x].fa); return x;
}
inline void U(int x){
	// nothing to f__k
}
inline void DR(int x){
	swap(lc,rc); tr[x].rev^=1;
}
inline void D(int x){
	if (tr[x].rev){
		if (lc) DR(lc);
		if (rc) DR(rc);
		tr[x].rev=0;
	}
}
void DD(int x){
	if (!isrt(x)) DD(tr[x].fa); D(x);
}
void rot(int x){
	int y=tr[x].fa, z=tr[y].fa, d=dir(x);
	if (!isrt(y)) tr[z].ch[dir(y)]=x; tr[x].fa=z;
	z=tr[y].ch[d]=tr[x].ch[d^1]; if (z) tr[z].fa=y;
	tr[x].ch[d^1]=y; tr[y].fa=x;
	U(y); U(x);
}
void splay(int x){
	static int y;
	for (DD(x);!isrt(x);rot(x))
		if (!isrt(y=tr[x].fa))
			rot(dir(x)^dir(y)? x: y);
}
int acc(int x){
	for (int las=0;x;las=x,x=tr[x].fa)
		splay(x), tr[x].ch[1]=las, U(x);
}
int mkrt(int x){
	acc(x); splay(x); DR(x);
}
int getl(int x,int y){
	mkrt(x); acc(y); splay(y);
}
int link(int x,int y){
	mkrt(x); tr[x].fa=y;
}
int cut(int x,int y){
	getl(x,y); tr[x].fa=tr[y].ch[0]=0; U(y);
}

ll gao(ll x){
	return x*(x+1)/2;
}

int main(){
	// freopen("graph.in","r",stdin); freopen("graph.out","w",stdout);
	n=read(); m=read(); int lp=0;
	for (int u,v;m--;){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i=1;i<=n;++i){
		for (unsigned it=0;it<G[i].size();++it){
			int j=G[i][it];
			if (j<i&&j>lp){
				while (GF(i)==GF(j)){
					++lp;
					for (unsigned it2=0;it2<G[lp].size();++it2){
						if (G[lp][it2]<=i&&G[lp][it2]>lp) cut(lp,G[lp][it2]);
					}
				}
				if (j<i&&j>lp) link(i,j);
			}
		}
		pre[i]=lp;
		sum[i]=sum[i-1]+i-pre[i];
	}
	T=read();
	for (int u,v;T--;){
		scanf("%d%d",&u,&v);
		int l=u, r=v, res=u-1;
		for (;l<=r;){
			int mid=l+r>>1;
			if (pre[mid]<u){
				res=mid; l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ll ans=sum[v]-sum[res]+gao(res-u+1);
		printf("%lld\n",ans);
	}
}
