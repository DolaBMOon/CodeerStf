#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100100
using namespace std;
struct P{int x,y;}e[N];
int s[N*3],r[N*3],n,ans,mx,id,T;
int sqr(int x){return x*x;}
int dis(int a,int b){
	return sqr(e[a].x-e[b].x)+sqr(e[a].y-e[b].y);
}
int cro(int a,int b,int c){
	return (e[b].x-e[a].x)*(e[c].y-e[a].y)-(e[c].x-e[a].x)*(e[b].y-e[a].y);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d%d",&e[i].x,&e[i].y);
		for (int i=0;i<n;i++) s[i*2+1]=dis(i,(i+1)%n);
		for (int i=0;i<n;i++) s[i*2]=cro(i,(i-1+n)%n,(i+1)%n);
		for (int i=0;i<n;i++) s[i+n*2]=s[i];
		ans=mx=id=0;
		memset(r,0,sizeof(r));
		for (int i=0;i<n*3;i++){
			if (mx>i) r[i]=min(mx-i,r[2*id-i]); else r[i]=1;
			while (i-r[i]>=0&&i+r[i]<3*n&&s[i+r[i]]==s[i-r[i]]) r[i]++;
			if (i+r[i]>mx) mx=i+r[i],id=i;
			if (r[i]>=n+1) ans++;
		}
		printf("%d\n",ans);
	}
}
