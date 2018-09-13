#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;
typedef long long LL;
const int uni=155;
const int N=1<<22|1;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int A[N],B[N],R[N];
LL tot[N];
double sq[N];
struct C{ double x,y; }a[N],W[N<<1],*w0[30],*w1[30];
inline C operator + (const C &a,const C &b) { return (C){a.x+b.x,a.y+b.y}; }
inline C operator - (const C &a,const C &b) { return (C){a.x-b.x,a.y-b.y}; }
inline C operator * (const C &a,const C &b) { return (C){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x}; }
inline int sqr4(int x) { return x*x*x*x; }
inline void DFT(C *a,int n,int f) {
	int i,o,k,t;C *wn,*w,x,y;
	for (i=0;i<n;i++) if (i<R[i]) swap(a[i],a[R[i]]);
	for (i=1,t=0;i<n;i<<=1,t++)
		for (o=0,wn=f==1?w0[t]:w1[t];o<n;o+=i<<1)
			for (k=0,w=wn;k<i;k++,w++) {
				x=a[o+k],y=a[o+k+i]**w;
				a[o+k]=x+y;
				a[o+k+i]=x-y;
			}
}
const double pi=acos(-1);
int main()
{
	int n=gi(),m=gi(),i,a,b,c,d,len,L;C *cur=W;double ans;
	for (i=1;i<=n;i++) {
		a=gi(),b=gi(),c=gi();
		A[a*uni*uni+b*uni+c]++;
		B[(77-a)*uni*uni+(77-b)*uni+(77-c)]++;
	}
	for (len=1,L=0;(len<<1)<N;len<<=1,L++) {
		w0[L]=cur;cur+=len;
		w1[L]=cur;cur+=len;
		for (i=0;i<len;i++) {
			w0[L][i]=(C){cos(pi/len*i),sin(pi/len*i)};
			w1[L][i]=(C){cos(pi/len*i),sin(-pi/len*i)};
		}
	}
	for (i=0,L--;i<len;i++) R[i]=R[i>>1]>>1|(i&1)<<L;
	for (i=0;i<len;i++)
		if (A[i]||B[i])
			::a[i]=(C){(A[i]+B[i])*0.5,(A[i]-B[i])*0.5};
	DFT(::a,len,1);
	for (i=0;i<len;i++) ::a[i]=::a[i]*::a[i];
	DFT(::a,len,-1);
	for (i=0;i<len;i++) tot[i]=(::a[i].x+0.5)/len;
	tot[((77*uni)+77)*uni+77]-=n;
	for (i=0,L=len,len=0;i<L;i++)
		if (tot[i])
		{
			tot[len]=tot[i],A[len]=i/uni/uni-77,B[len]=i/uni%uni-77,R[len]=i%uni-77;
			if(A[len]==0&&B[len]==0&&R[len]==0)
				continue;
			sq[len]=sqrt(sqr4(A[len])+sqr4(B[len])+sqr4(R[len])),len++;
		}
	while (m--) {
		a=gi(),b=gi(),c=gi(),d=gi();
		ans=0;
		for (i=0;i<len;i++)
			ans+=tot[i]*abs(a*A[i]+b*B[i]+c*R[i]+d)/sq[i];
		printf("%.10lf\n",ans/n/(n-1));
	}
	return 0;
}
