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
#define pdd pair<db,db>
#define pb push_back
#define mem(x,y) memset(x,y,sizeof x)
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef double db;
const int INF=2e9;
const db eps=1e-8;
template<typename T>
inline void read(T &x) {
	x=0; int f=1; char ch=getchar();
	while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
	while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
	x*=f;
}
//==========================head template==========================
const int N=1010;
struct Circle {
	db x,y,r;
	inline void in() {
		scanf("%lf %lf %lf",&x,&y,&r);
	}
}a[N];
int n,m;
pdd ord[N],seg[N];
inline db Value(db x) {
	int top=0;
	for(int i=1;i<=n;i++) {
		db d=a[i].r*a[i].r-(a[i].x-x)*(a[i].x-x);
		if(d<0) continue;
		d=sqrt(abs(d));
		ord[++top]=mp(a[i].y-d,a[i].y+d);
	}
	sort(ord+1,ord+1+top);
	db L=-2e3,R=-2e3,res=0;
	for(int i=1;i<=top;i++) {
		if(R<ord[i].F) {
			res+=R-L;
			L=R=ord[i].F;
		}
		if(R<ord[i].S) {
			R=ord[i].S;
		}
	}
	res+=R-L;
	return res;
}
inline db Calc(db l,db r,db a,db b,db c) {
	return (r-l)*(a+4*b+c)/6.0;
}
inline db Simpson(db L,db mid,db R,db a,db b,db c) {
	db s=Calc(L,R,a,b,c);
	db lm=(L+mid)*0.5,rm=(mid+R)*0.5,d=Value(lm),e=Value(rm);
	db sl=Calc(L,mid,a,d,b),sr=Calc(mid,R,b,e,c);
	if(abs(sl+sr-s)<=eps) return sl+sr;
	return Simpson(L,lm,mid,a,d,b)+Simpson(mid,rm,R,b,e,c);
}
inline db Work(db L,db R) {
	db mid=(L+R)*0.5,a=Value(L),b=Value(mid),c=Value(R);
	return Simpson(L,mid,R,a,b,c);
}
inline db Solve() {
	db L=-2e3,R=-2e3,ans=0;
	for(int i=1;i<=n;i++) {
		if(R<seg[i].F) {
			ans+=Work(L,R);
			L=R=seg[i].F;
		}
		if(R<seg[i].S) R=seg[i].S;
	}
	ans+=Work(L,R);
	return ans;
}
int main() {
	read(n);
	for(int i=1;i<=n;i++) {
		a[i].in();
		seg[i]=mp(a[i].x-a[i].r,a[i].x+a[i].r);
	}
	sort(seg+1,seg+n+1);
	printf("%.3lf\n",Solve());
	return 0;
}
