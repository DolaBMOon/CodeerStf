#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

#define arr (int)(1e5+10)

int P[arr];

int f(int v)
{
	return (P[v]==v?v:P[v]=f(P[v]));
}

int n;
int a[arr];
vi reb[arr];
vi vh[arr];
vi dil[arr];
int S[arr];

int ans[arr];
int ans1[arr];

const int M=20;
vector<pii> vec;
int d[arr];

int tin[arr];
int tout[arr];
int T;

int rtin[arr];

int first_occurrence[arr];

int p[arr];

int pp[arr][M];

vi go_dfs[arr];

void dfs(int now,int pred)
{
	S[now]=1;

	p[now]=pred;

	pp[now][0]=pred;
	for (int j=1;j<M;j++){
		pp[now][j]=pp[pp[now][j-1]][j-1];
	}

	tin[now]=++T;
	rtin[tin[now]]=now;

	first_occurrence[now]=len(vec);
	vec.pb(mp(d[now],now));

	for (auto wh:reb[now]){
		if (wh!=pred){
			d[wh]=d[now]+1;

			go_dfs[now].pb(wh);

			dfs(wh,now);

			S[now]+=S[wh];

			vec.pb(mp(d[now],now));
		}
	}

	tout[now]=T;
}

vector<vector<pii>> stb;

void prepare_lca()
{
	stb.resize(len(vec));
	for (auto& i:stb){
		i.assign(M,mp(0,0));
	}
	for (int i=0;i<len(vec);i++){
		stb[i][0]=vec[i];
	}
	for (int j=1;j<M;j++){
		for (int i=0;i+(1ll<<j)-1<len(vec);i++){
			stb[i][j]=min(stb[i][j-1],stb[i+(1ll<<(j-1))][j-1]);
		}
	}
}

int lg[10*arr];

int get_stb(int l,int r)
{
	if (l>r){
		swap(l,r);
	}
	int k=lg[r-l+1];
	return min(stb[l][k],stb[r-(1ll<<k)+1][k]).sec;
}

int lca(int u,int v)
{
	int L=first_occurrence[u];
	int R=first_occurrence[v];
	return get_stb(L,R);
}

bool is_pred(int u,int v)
{
	return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

int get_next(int u,int v) /// u is pred v
{
	for (int j=M-1;j>=0;j--){
		if (!is_pred(pp[v][j],u)){
			v=pp[v][j];
		}
	}
	return v;
}

void push_on_way(int u,int v,const int& val);

vi cur_push;

void rec(int u,int v)
{
	if (v==0){
		return;
	}
	if (!is_pred(u,v)){
		return;
	}
	if (u==v){
		return;
	}
	int z=f(v);
	if (z==v){
		cur_push.pb(v);
		P[v]=f(p[v]);
	}
	rec(u,P[v]);
}

void push_on_way(int u,int v,const int& val)
{
	cur_push.clear();
	rec(u,v);
	for (auto i:cur_push){
		ans[i]=val;
	}
}

void push(int u,int v,int val) /// u is pred v
{
	//    cout<<"push :: "<<u<<" "<<v<<" :: "<<val<<" !!!\n";
	if (!is_pred(u,v)){
		return;
	}
	if (u==v||p[v]==u){
		return;
	}
	push_on_way(u,p[v],val);
}

void process(int id)
{
	if (len(dil[id])<=1){
		return;
	}
	int l=lca(dil[id][0],dil[id][1]);
	for (auto i:dil[id]){
		l=lca(l,i);
	}

	int min_tin=1e9;
	int max_tin=-1e9;
	for (auto i:dil[id]){
		if (i!=l){
			min_tin=min(min_tin,tin[i]);
			max_tin=max(max_tin,tin[i]);
		}
	}
	if (min_tin!=max_tin){
		int L=0,R=len(go_dfs[l])-1;
		/// find where min_tin
		while (R-L>0){
			int m=(L+R+1)/2;
			int lol=go_dfs[l][m];
			if (tin[lol]>min_tin){
				R=m-1;
			}
			else{
				L=m;
			}
		}
		int lol=go_dfs[l][L];
		if (!is_pred(lol,rtin[max_tin])){
			ans1[l]=max(ans1[l],id);
		}
	}

	/// process push
	for (auto i:dil[id]){
		push(l,i,id);
	}
}

main()
{
#ifdef I_love_Maria_Ivanova
	files("barik");
	freopen("debug.txt","w",stderr);
#endif

	fast;

	for (int i=0;i<arr;i++){
		P[i]=i;
	}

	for (int i=2;i<10*arr;i++){
		lg[i]=lg[i/2]+1;
	}

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		vh[a[i]].pb(i);
	}

	for (int i=1;i<arr;i++){
		for (int j=i;j<arr;j+=i){
			for (auto k:vh[j]){
				dil[i].pb(k);
			}
		}
	}

	for (int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		reb[u].pb(v);
		reb[v].pb(u);
	}
	dfs(1,1);
	prepare_lca();

	for (int i=arr-1;i>=1;i--){
		process(i);
	}

	for (int i=1;i<=n;i++){
		cout<<max(ans[i],ans1[i])<<" ";
	}
	cout<<"\n";
}
