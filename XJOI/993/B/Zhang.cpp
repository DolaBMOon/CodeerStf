#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

map<int,int>mp;
int n, m, a[17][17], sum[17][17], ans=1e8;
vector<int>st, en;

int dft(vector<int>v){
	int w=0, res=0, las=m;
	for (auto o:v){
		for (int t=las-o;t--;) w++; las=o;
		res|=1<<w++;
	}
	return res;
}

int getsum(int i,int j,int s,int v){
	return sum[i][j]+sum[s][v]-sum[i][v]-sum[s][j];
}

int cal(vector<int>v){
	if (v==en) return 0;
	int id=dft(v);
	if (mp.count(id)) return mp[id];
	int res=1e8;
	for (int i=0;i<n;++i)
		if (v[i]!=(i==0? m: v[i-1])){
			if (getsum(n,m,i,v[i])==0) return res;
		}
	for (int s=0,t;s<n;s=t){
		for (t=s+1;t<n&&v[t]==v[s];++t);
		int lim= s==0? m: v[s-1];
		for (int i=s+1;i<=t;++i)
			for (int j=v[s]+1;j<=lim;++j){
				int cnt=getsum(i,j,s,v[s]);
				if (cnt==1){
					vector<int>w=v;
					for (int k=s;k<i;++k) w[k]=j;
					res=min(res,cal(w)+2*(i-s+j-v[s]));
				}else{
					if (cnt==0) continue;
					else break;
				}
			}
	}
	return mp[id]=res;
}

int main(){
	cin>>n>>m;
	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j){
			cin>>a[i][j];
			sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+a[i][j];
		}
	st.resize(n); en.resize(n);
	for (auto &o:en) o=m;
	cout<<cal(st)/2-n-m<<endl;
}
