#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<unordered_map>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> void GetMin(T &a,T b)
{
	return ((a<=b)?false:(a=b,true));
}

template<typename T> void GetMax(T &a,T b)
{
	return ((a>=b)?false:(a=b,true));
}

/*
	 -<Unlimited Blade Works>-
 */

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int MOD=1e9+7;

int Mul(signed a,signed b)
{
	static signed MO=MOD;
	unsigned long long x=(long long)a*b;
	unsigned xh=(unsigned)(x>>32),xl=(unsigned)x,d,m;
	asm
		(
		 "divl %4;\n\t"
		 :"=a"(d),"=d"(m)
		 :"d"(xh),"a"(xl),"r"(MO)
		);
	return m;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

const int N=5e5+10;

int n,m,k,c[N],pw[N],ans,fa[N];
unordered_map<int,vector<Pir> > mp;

void Prework()
{
	pw[0]=1;
	for(int i=1;i<=n;++i)
		pw[i]=U(pw[i-1],pw[i-1]);
}

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

bool Hb(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x==y)
		return false;
	fa[x]=y;
	return true;
}

signed main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%I64d",c+i);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%I64d%I64d",&u,&v);
		mp[c[u]^c[v]].emplace_back(Pir(u,v));
	}
	Prework();
	SU(ans,Mul(pw[n],D((1ll<<k)%MOD,mp.size())));
	for(pair<int,vector<Pir> > o:mp)
	{
		vector<Pir> &v=o.sec;
		int tot=n;
		for(Pir p:v)
			tot-=Hb(p.fir,p.sec);
		for(Pir p:v)
			fa[p.fir]=fa[p.sec]=0;
		SU(ans,pw[tot]);
	}
	printf("%I64d",ans);
	return 0;
}
