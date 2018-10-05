//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double

db f[55][55], g[55];
int n, sz[55];
vector<int>G[55];

db jc[111];
void PRE(){
	jc[0]=1;
	for (int i=1;i<=n*2;++i) jc[i]=jc[i-1]*i;
}
db C(int x,int y){
	return jc[x]/jc[y]/jc[x-y];
}
db gao(int x,int y){
	return C(x+y,x);
}

void dfs(int x,int fff){
	f[x][1]=1; sz[x]=1;
	for (auto y:G[x]){
		if (y==fff) continue;
		dfs(y,x);
		for (int i=0;i<=sz[x]+sz[y];++i) g[i]=0;
		for (int i=1;i<=sz[x];++i)
			for (int j=1;j<=sz[y];++j)
				for (int k=0;k<=sz[y];++k)
					g[i+k]+= f[x][i]*f[y][min(j,k+1)]
						*(j<=k? 0.5: 1)
						*gao(i-1,k)*gao(sz[x]-i,sz[y]-k);
		for (int i=0;i<=sz[x]+sz[y];++i) f[x][i]=g[i];
		sz[x]+=sz[y];
	}
}

int main(){
	cin>>n;
	PRE();
	int x, y;
	for (int i=1;i<n;++i){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i=1;i<=n;++i){
		dfs(i,0);
		//for (int j=1;j<=n;++j) cout<<f[i][j]/jc[n-1]<<' ';
		printf("%.11lf\n",f[i][n]/jc[n-1]);
	}
}
