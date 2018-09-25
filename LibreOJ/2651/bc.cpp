#include <bits/stdc++.h>
using namespace std;
#define N 800050
typedef unsigned long long ll;
ll c[N],r[N];
int n,nxt[N];
struct Point {
	ll x,y;
	Point() {}
	Point(ll x_,ll y_) :
		x(x_),y(y_) {}
	//Point operator + (const Point &p) const {return Point(x+p.x,y+p.y);}
	Point operator - (const Point &p) const {return Point(x-p.x,y-p.y);}
	//Point operator * (ll rate) const {return Point(x*rate,y*rate);}
}a[N];
ll dis(const Point &p1,const Point &p2) {
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
typedef Point Vector;
ll doc(const Point &p1,const Point &p2) {return p1.x*p2.x+p1.y*p2.y;}
ll cross(const Point &p1,const Point &p2) {return p1.x*p2.y-p1.y*p2.x;}
ll has(const Point &p1,const Point &p2) {return doc(p1,p2)+cross(p1,p2)*131;}
ll calc1(int x) {
	int y=x-1; if(!y) y=n;
	return dis(a[x],a[y]);
}
ll calc2(int x) {
	int y=x+1,z=x-1; if(y>n) y=1; if(!z) z=n;
	return cross(Point(a[x]-a[y]),Point(a[y]-a[z]));
}
void solve() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	int len=0;
	for(i=1;i<=n;i++) {
		c[++len]=calc1(i); c[++len]=calc2(i);
		cout<<c[len-1]<<" "<<c[len]<<" ";
	}
	for(i=1;i<=len;i++) c[len+i]=c[i],r[len-i+1]=c[i];
	int j=0; nxt[1]=0;
	for(i=2;i<=len;i++) {
		while(j&&r[j+1]!=r[i]) j=nxt[j];
		nxt[i]=(r[j+1]==r[i])?++j:0;
	}
	int ans=0;
	j=0;
	for(i=1;i<2*len;i++) {
		while(j&&r[j+1]!=c[i]) j=nxt[j];
		if(r[j+1]==c[i]) j++;
		if(j==len) {
			ans++; j=nxt[j];
		}
	}
	printf("%d\n",ans);
	return ;
}
int main() {
	//int T=1;
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}
