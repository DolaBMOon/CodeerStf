%:pragma GCC target("avx")
%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("-fgcse")
%:pragma GCC optimize("-fgcse-lm")
%:pragma GCC optimize("-fipa-sra")
%:pragma GCC optimize("-ftree-pre")
%:pragma GCC optimize("-ftree-vrp")
%:pragma GCC optimize("-fpeephole2")
%:pragma GCC optimize("-ffast-math")
%:pragma GCC optimize("-fsched-spec")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("-falign-jumps")
%:pragma GCC optimize("-falign-loops")
%:pragma GCC optimize("-falign-labels")
%:pragma GCC optimize("-fdevirtualize")
%:pragma GCC optimize("-fcaller-saves")
%:pragma GCC optimize("-fcrossjumping")
%:pragma GCC optimize("-fthread-jumps")
%:pragma GCC optimize("-funroll-loops")
%:pragma GCC optimize("-fwhole-program")
%:pragma GCC optimize("-freorder-blocks")
%:pragma GCC optimize("-fschedule-insns")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("-ftree-tail-merge")
%:pragma GCC optimize("-fschedule-insns2")
%:pragma GCC optimize("-fstrict-aliasing")
%:pragma GCC optimize("-fstrict-overflow")
%:pragma GCC optimize("-falign-functions")
%:pragma GCC optimize("-fcse-skip-blocks")
%:pragma GCC optimize("-fcse-follow-jumps")
%:pragma GCC optimize("-fsched-interblock")
%:pragma GCC optimize("-fpartial-inlining")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("-freorder-functions")
%:pragma GCC optimize("-findirect-inlining")
%:pragma GCC optimize("-frerun-cse-after-loop")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("-finline-small-functions")
%:pragma GCC optimize("-ftree-switch-conversion")
%:pragma GCC optimize("-foptimize-sibling-calls")
%:pragma GCC optimize("-fexpensive-optimizations")
%:pragma GCC optimize("-funsafe-loop-optimizations")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC optimize("-fdelete-null-pointer-checks")
%:pragma GCC diagnostic error "-std=c++14"
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return ((a<=b)?false:(a=b,true));
}

template<typename T> bool GetMax(T &a,T b)
{
	return ((a>=b)?false:(a=b,true));
}

/*
	 -<Unlimited Blade Works>-
 */

#define LL long long

const int MOD=1e9+7;
const int COL=10;
const int N=100+10;
const int M=N*N;
const int MS=(1<<COL)+10;
const int S=(1<<COL)-1;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

void SU(int &a,int b)
{
	((a+=b)>=MOD)?(a-=MOD):0;
}

int n,m,u[M],v[M];
vector<int> o[COL];
int cnt[COL][N][N];
bool G[N][N];
int dp[MS][N];

void Solve(vector<int> &v,int a[N][N])
{
	sort(v.begin(),v.end());
	do
	{
		bool fl=true;
		for(int i=1;i<(int)v.size()&&fl;++i)
			fl&=G[v[i-1]][v[i]];
		a[v.front()][v.back()]+=fl;
	}
	while(next_permutation(v.begin(),v.end()));
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0,c;i<n;++i)
	{
		scanf("%d",&c);
		o[c].emplace_back(i);
	}
	for(int i=1;i<=m;++i)
		scanf("%d",u+i);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",v+i);
		G[u[i]][v[i]]=G[v[i]][u[i]]=true;
	}
	for(int i=0;i<COL;++i)if(!o[i].empty())
	{
		Solve(o[i],cnt[i]);
		for(int j:o[i])
			for(int k:o[i])
				SU(dp[1<<i][k],cnt[i][j][k]);
	}
	for(int f=1;f<S;++f)
	{
		for(int c=0;c<COL;++c)
		{
			if(!((f>>c)&1)&&!o[c].empty())
			{
				for(int i=0,t;i<n;++i)
				{
					for(int j:o[c])if(G[i][j])
					{
						for(int k:o[c])if((t=cnt[c][j][k]))
							SU(dp[f^(1<<c)][k],Mul(dp[f][i],t));
					}
				}
			}
		}
	}
	int s=0;
	for(int i=0;i<COL;++i)if(!o[i].empty())
		s^=1<<i;
	int ans=0;
	for(int i=0;i<n;++i)
		SU(ans,dp[s][i]);
	printf("%d",ans);
	return 0;
}
