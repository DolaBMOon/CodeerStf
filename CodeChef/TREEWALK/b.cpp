#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

#define LL long long

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

const int MOD=998244353;
const int NB=3030;

int Mul(int a,int b)
{
	return (LL)a*b%MOD;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
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

void Extend(vector<int> &v,int x)
{
	if((int)v.size()<x)
		v.resize(x);
}

vector<int> BM(vector<int> v)
{
	static vector<int> f,g,t;
	f.clear();
	g.clear();
	f.reserve(NB);
	g.reserve(NB);
	t.reserve(NB);
	int fp=0,fw=0;

	for(int i=0;i<(int)v.size();++i)
	{
		int x=v[i];
		if((int)f.size()<=i)
			for(int j=0;j<(int)f.size();++j)
				SD(x,Mul(f[j],v[i-j-1]));
		if(x)
		{
			if(f.empty())
				f.resize(i);
			else
			{
				t=f;
				Extend(f,i-fp+g.size());
				int y=Mul(x,Qpow(fw));
				SU(f[i-fp-1],y);
				for(int j=0;j<(int)g.size();++j)
					SD(f[i-fp+j],Mul(y,g[j]));
				g=t;
			}
			fp=i;
			fw=x;
		}
	}
	return f;
}

namespace CHSolver
{

	int n;
	vector<int> f;

	void Muc(vector<int>& A,const vector<int>& B)
	{
		static vector<int> t;
		t.resize(n+n-1);
		for(int i=0;i<n+n-1;++i)
			t[i]=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				SU(t[i+j],Mul(A[i],B[j]));

		for(int i=n+n-2;i>=n;--i)
			for(int j=1;j<=n;++j)
				SU(t[i-j],Mul(t[i],f[j-1]));

		for(int i=0;i<n;++i)
			A[i]=t[i];
	}

	int Solve(vector<int> v,vector<int> _f,LL m)
	{
		n=(f=_f).size();
		if(m<(int)v.size())
			return v[m];

		m-=n-1;
		static vector<int> g,h;
		g.clear();
		h.clear();
		g.resize(n);
		h.resize(n);
		g[0]=h[1]=1;
		for(;m;m>>=1,Muc(h,h))if(m&1)
			Muc(g,h);

		int t=v.size();
		v.resize(n+n-1);
		for(int i=t;i<n+n-1;++i)
			for(int j=1;j<=n;++j)
				SU(v[i],Mul(v[i-j],f[j-1]));

		int ans=0;
		for(int i=0;i<n;++i)
			SU(ans,Mul(g[i],v[n+i-1]));
		return ans;
	}

}

const int N=3010;

int n,rt,k,nw[N];
vector<int> G[N],f[N],g[N];

void Appendall()
{
	for(int i=1;i<=n;++i)
		f[i].emplace_back(nw[i]);
}

void Nxt()
{
	static int f[N];
	for(int i=1;i<=n;++i)
	{
		f[i]=0;
		for(int v:G[i])
			SU(f[i],nw[v]);
	}
	memcpy(nw,f,sizeof nw);
}

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	scanf("%d%d",&rt,&k);
	nw[rt]=1;
	if(n==1)
	{
		if(k)
			puts("0");
		else
			puts("1");
		return 0;
	}
	Appendall();
	for(int i=1;i<N;++i)
	{
		Nxt();
		Appendall();
	}
	g[0]=BM(f[1]);
	for(int i=1;i<=n;++i)
		printf("%d ",CHSolver::Solve(f[i],g[0],k));
	return 0;
}
