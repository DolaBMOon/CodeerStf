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

const int MOD=1e9+7;
const int NB=3030;

int Mul(int a,int b)
{
	unsigned long long x=(long long)a*b;
	unsigned xh=(unsigned)(x>>32),xl=(unsigned)x,d,m;
	asm
		(
		 "divl %4;\n\t"
		 :"=a"(d),"=d"(m)
		 :"d"(xh),"a"(xl),"r"(MOD)
		);
	return m;
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

const int K=5000;

int n,ki;
int dp[K][K][3];

void Work()
{
	scanf("%d%d",&n,&ki);
	memset(dp,0,sizeof dp);
	dp[0][0][0]=1;
	for(int i=0;i<K-1;++i)
		for(int j=0;j<=ki;++j)
			for(int a=0,x;a<3;++a)if((x=dp[i][j][a]))
				for(int b=0;b<3;++b)if(!(a&b))
					SU(dp[i+1][j+(b>0)][b],x);
	vector<int> A,B;
	for(int i=0;i<K;++i)
	{
		int sm=0;
		for(int j=0;j<3;++j)
			SU(sm,dp[i][ki][j]);
		A.emplace_back(sm);
	}
	printf("%d\n",A[n]);
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
