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
#define pii pair<int,int>
#define pb push_back
#define mem(x,y) memset(x,y,sizeof x)
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef double db;
const int INF=2e9;
const db eps=1e-8;
inline void read(int &x)
{
	x=0; int f=1; char ch=getchar();
	while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
	while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
	x*=f;
}
inline void read(ll &x)
{
	x=0; int f=1; char ch=getchar();
	while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
	while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
	x*=f;
}
//==========================head template==========================

const int N=200010;

int n,m,K;

struct POI {
	ll x,y;
	inline void in() {
		read(x); read(y);
	}
	inline POI operator - (const POI &a)const {
		return (POI) {x-a.x,y-a.y};
	}
}bx,by,p[N];

int f[N];
inline ll Cross(POI a,POI b) {
	return a.x*b.y-a.y*b.x;
}

inline bool Judge(POI a,POI b) {
	POI c=b-a;
	if(Cross(bx,c)>=0 && Cross(by,c)<=0) return true;
	return false;
}

int DP(int u) {
	// printf("%d\n",u);
	if(f[u]!=-1) return f[u];
	int ret=0;
	for(int i=1;i<=n;i++)
		if(u!=i && Judge(p[u],p[i])) {
			ret=max(ret,DP(i));
		}
	return f[u]=ret+1;
}

signed main() {
	read(n); read(K);
	by.in(); bx.in();
	for(int i=1;i<=n;i++)
		p[i].in();
	read(m);
	for(int i=1;i<=m;i++) {
		int type,id; read(type);
		if(type==1) {
			mem(f,-1);
			read(id); int ans=DP(id);
			printf("%d\n",ans);
		} else {
			p[++n].in();
		}
	}
	return 0;
}
