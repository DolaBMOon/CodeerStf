#include<bits/stdc++.h>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

#define LL long long
#define Poly vector<int>

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
const int Gen=3;
const int N=3030;

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
	f.reserve(N);
	g.reserve(N);
	t.reserve(N);
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
	vector<int> f,mf;

	void FFT(Poly &A,bool fl)
	{
		int L=A.size();
		if(fl)
		{
			int t=Qpow(L);
			for(int& v:A)
				v=Mul(v,t);
			reverse(A.begin()+1,A.end());
		}
		for(int i=1,j=L>>1,k;i<L;++i,j^=k)
		{
			if(i<j)
				swap(A[i],A[j]);
			k=L>>1;
			while(j&k)
			{
				j^=k;
				k>>=1;
			}
		}

		static int w[N]={1};

		for(int i=1;i<L;i<<=1)
		{
			int t=Qpow(Gen,(MOD-1)/(i<<1));
			for(int j=1;j<i;++j)
				w[j]=Mul(w[j-1],t);
			for(int j=0;j<L;j+=(i<<1))
			{
				for(int k=0;k<i;++k)
				{
					t=Mul(A[i+j+k],w[k]);
					A[i+j+k]=D(A[j+k],t);
					SU(A[j+k],t);
				}
			}
		}
	}

	Poly Inv(Poly A)
	{
		int L=A.size();
		if(L==1)
			return Poly(1,Qpow(A[0]));
		Poly t=A;
		t.resize((L+1)>>1);
		Poly B=Inv(t);
		int p=1;
		for(;p<(L<<1);p<<=1);
		t=A;
		t.resize(p);
		FFT(t,false);
		B.resize(p);
		FFT(B,false);
		for(int i=0;i<p;++i)
			B[i]=Mul(D(2,Mul(t[i],B[i])),B[i]);
		FFT(B,true);
		B.resize(L);
		return B;
	}

	Poly operator*(Poly A,Poly B)
	{
		int need=A.size()+B.size()-1,L;
		for(L=1;L<need;L<<=1);
		A.resize(L);
		FFT(A,false);
		B.resize(L);
		FFT(B,false);
		for(int i=0;i<L;++i)
			A[i]=Mul(A[i],B[i]);
		FFT(A,true);
		A.resize(need);
		return A;
	}

	Poly operator/(Poly A,Poly B)
	{
		int n=A.size(),m=B.size(),p=1,t=n-m+1;
		for(;p<(t<<1);p<<=1);
		reverse(A.begin(),A.end());
		A.resize(t);
		reverse(B.begin(),B.end());
		B.resize(t);
		A=A*Inv(B);
		A.resize(t);
		reverse(A.begin(),A.end());
		return A;
	}

	Poly operator-(Poly A,Poly B)
	{
		for(int i=B.size()-1;i>=0;--i)
			SD(A[i],B[i]);
		return A;
	}

	ostream& operator<<(ostream &os,const Poly &p)
	{
		os<<"{";
		for(int i=0;i<(int)p.size()-1;++i)
			os<<p[i]<<",";
		os<<p.back()<<"}";
		return os;
	}

	void Muc(vector<int> &A,const vector<int> &B)
	{
		A=A*B;
		(A=A-A/mf*mf).resize(n);
	}

	int Solve(vector<int> v,vector<int> _f,LL m)
	{
		n=(f=_f).size();
		if(m<(int)v.size())
			return v[m];

		mf=f;
		reverse(mf.begin(),mf.end());
		mf.push_back(1);
		for(int i=0;i<n;++i)
			mf[i]=D(0,mf[i]);

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

int n,rt,k,nw[N];
vector<int> G[N],f[N],g;

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
	Appendall();
	for(int i=1;i<N;++i)
	{
		Nxt();
		Appendall();
	}
	g=BM(f[1]);
	for(int i=1;i<=n;++i)
		printf("%d ",CHSolver::Solve(f[i],g,k));
	return 0;
}
