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

#define HII cerr<<"HI"<<endl
#define LLLINE cerr<<"@@@@@@@@@@@@@@@@@@@@"<<endl

template <class _T_>
void read(_T_& d){
	d=0;int f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f*=-1;
	for(;c>='0'&&c<='9';c=getchar())d=d*10+c-'0';
	d*=f;
}


/************************************************/
#define MN 200005
vector<int> pri[MN];
int a[MN];
int pr[MN],ud[MN],tpr;
int fa[MN];
int v[MN],sz[MN],gg[MN];
int gf(int x){
	return fa[x]<=0?x:fa[x]=gf(fa[x]);
}
int n;
void mg(int x,int y){
	x=gf(x);y=gf(y);
	if(x==y)return;
	if(fa[x]<fa[y])fa[x]+=fa[y],fa[y]=x,gg[x]=1;
	else fa[y]+=fa[x],fa[x]=y,gg[y]=1;
}
vector<int> c1,c2;
int cnt=0;
int MAX;
int main(){
	read(n);
	srand(time(0));
	for(int i=2;i<MN;++i){
		if(!ud[i])pr[++tpr]=i;
		for(int j=1;j<=tpr&&pr[j]*i<MN;++j){
			ud[pr[j]*i]=1;
			if(i%pr[j]==0)break;
		}
	}
	for(int i=1;i<=n;++i){
		read(a[i]);
		for(int j=1;j<=tpr&&pr[j]<=sqrt(a[i]);++j){
			if(a[i]%pr[j]==0){
				while(a[i]/pr[j]%pr[j]==0)a[i]/=pr[j];
			}
		}
		++v[a[i]];
	}
	for(int i=1;i<MN;++i){
		if(v[i])a[++cnt]=i,sz[cnt]=v[i];
	}
	n=cnt;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=tpr&&pr[j]<=sqrt(a[i]);++j){
			if(a[i]%pr[j]==0){
				pri[i].pb(pr[j]);
				MAX=max(pr[j],MAX);
				while(a[i]%pr[j]==0)a[i]/=pr[j];
			}
		}
		if(a[i]!=1)pri[i].pb(a[i]),MAX=max(a[i],MAX);
		fa[i]=-sz[i];
	}
	while(1.0*clock()/CLOCKS_PER_SEC<=0.47){
		c1.clear();c2.clear();
		for(int i=1;pr[i]<=MAX;++i){
			ud[pr[i]]=(rand()%3)&1;
		}
		for(int i=1;i<=n;++i){
			int F=0;
			for(auto z:pri[i]){
				if(ud[z]){
					if(F==1){F=-2;break;}
					else F=-1;
				}else{
					if(F==-1){F=-2;break;}
					else F=1;
				}
			}
			if(F==-1)c1.pb(i);
			if(F==1)c2.pb(i);
		}
		if(c1.size()&&c2.size()){
			int x=c1.back();c1.pop_back();
			for(auto z:c1)mg(x,z);
			for(auto z:c2)mg(x,z);
		}
	}
	int res=0;
	for(int i=1;i<=n;++i)if(fa[i]<0)res+=gg[i]?1:-fa[i];
	cout<<res;
	return 0;
}
