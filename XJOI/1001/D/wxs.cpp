
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lg long long
#define db double
#define lb(x) ((x)&-(x))
#define ft first
#define sd second

template <class _T_>
void read(_T_& d){
	d=0;int f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f*=-1;
	for(;c>='0'&&c<='9';c=getchar())d=d*10+c-'0';
	d*=f;
}

/************************************************/
#define MN 55
char c[MN][MN];
int g[MN][MN];
int n;
int win[MN];
int main(){
	read(n);
	srand(*(int*)"fx666");
	for(int i=1;i<=n;++i){
		scanf("%s",c[i]+1);
	}
	db res=0;
	db G=(n-1)*(n-1)/4;
	for(int I=1;I<=600;++I){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(c[i][j]=='W')g[i][j]=1;
				if(c[i][j]=='L')g[i][j]=-1;
				if(c[i][j]=='?'){
					if(i<j)g[i][j]=rand()%2*2-1;
					else g[i][j]=-g[j][i];
				}
			}
		}
		memset(win,0,sizeof win);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)if(g[i][j]==1)++win[i];
		}
		for(int i=1;i<=400;++i){
			for(int j=1;j<=n;++j){
				for(int k=j+1;k<=n;++k){
					if(c[j][k]=='?'){
						if(g[j][k]==1&&win[j]<=win[k]){
							--win[j];++win[k];
							swap(g[j][k],g[k][j]);
						}else if(g[j][k]==-1&&win[k]<=win[j]){
							--win[k];++win[j];
							swap(g[j][k],g[k][j]);
						}else{
							if(rand()%100<I%30){
								swap(g[j][k],g[k][j]);
								if(g[j][k]==-1){
									--win[j],++win[k];
								}else{
									--win[k],++win[j];
								}
							}
						}
					}
				}
			}
		}
		lg R=0;
		for(int i=1;i<=n;++i){
			R+=win[i]*win[i];
			R-=win[i]*(n-1);
		}
		db RR=1.0*R/n;
		RR+=1.0*(n-1)*(n-1)/4;
		res=max(res,RR);
	}
	printf("%.12lf",res/(n-1)/(n-1));
	return 0;
}
