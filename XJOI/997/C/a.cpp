#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<set>

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

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second

struct Vector
{

	int x,y;

	void Read()
	{
		scanf("%lld%lld",&x,&y);
	}

};

Vector operator*(const Vector &a,const Vector &b)
{
	return (Vector){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}

Vector operator*=(Vector &a,const Vector &b)
{
	return a=a*b;
}

int Dot(const Vector &a,const Vector &b)
{
	return a.x*b.x+a.y*b.y;
}

ostream& operator<<(ostream &os,const Vector &a)
{
	os<<"("<<a.x<<","<<a.y<<")";
	return os;
}

const int N=2e5+10;
const int INF=0x3f3f3f3f;

struct St
{

	int mx[N<<2];

	void Update(int q,int w,int o=1,int l=1,int r=N)
	{
		if(l==r)
		{
			mx[o]=w;
			return;
		}
		int lc=o<<1,rc=lc^1,mid=(l+r)>>1;
		if(q<=mid)
			Update(q,w,lc,l,mid);
		else
			Update(q,w,rc,mid+1,r);
		mx[o]=max(mx[lc],mx[rc]);
	}

	int Query(int q,int o=1,int l=1,int r=N)
	{
		if(r<=q)
			return mx[o];
		int mid=(l+r)>>1;
		if(q<=mid)
			return Query(q,o<<1,l,mid);
		else
			return max(mx[o<<1],Query(q,(o<<1)^1,mid+1,r));
	}

}A,B;

int n,ki,tot,m,dp[N],que[N];
Vector u0,v0,p[N],ap[N];
bool fl[N];

void Trans(Vector &p)
{
	p*=u0;
	int x=Dot(u0,p),y=Dot(v0,p);
	p=(Vector){x,y};
}

bool Cmpx(Vector a,Vector b)
{
	return (a.x!=b.x)?(a.x<b.x):(a.y<b.y);
}

bool Cmpy(const Vector &a,const Vector &b)
{
	return (a.y!=b.y)?(a.y<b.y):(a.x<b.x);
}

set<Pir> Sx,Sy;

void Prework()
{
	sort(p+1,p+n+1,Cmpx);
	static Vector ls[N];
	int ed=0;
	for(int i=1;i<=tot;++i)
		ls[++ed]=p[i];
	sort(ls+1,ls+ed+1,Cmpx);
	for(int i=1;i<=tot;++i)
		p[i].x=lower_bound(ls+1,ls+ed+1,p[i],Cmpx)-ls;
	ed=0;
	for(int i=1;i<=tot;++i)
		ls[++ed]=p[i];
	sort(ls+1,ls+ed+1,Cmpy);
	for(int i=1;i<=tot;++i)
		p[i].y=lower_bound(ls+1,ls+ed+1,p[i],Cmpy)-ls;
	static int C[N];
	for(int i=1;i<=n;++i)
	{
		int &r=dp[i];
		for(int j=p[i].y;j;j-=j&(-j))
			GetMax(r,C[j]);
		++r;
		for(int j=p[i].y;j<=ed;++j)
			GetMax(C[j],r);
		A.Update(p[i].x,r);
		B.Update(p[i].y,r);
		Sx.insert(Pir(p[i].x,i));
		Sy.insert(Pir(p[i].y,i));
	}
}

void Update(bool fl,const int id)
{
	Vector nw=p[id];
	static int lst[N],ed;
	if(fl)
	{
		set<Pir>::iterator it=Sy.upper_bound(Pir(nw.y,INF));
		ed=0;
		for(int t;it!=Sy.end();++it)
		{
			lst[++ed]=t=it->sec;
			A.Update(p[t].y,dp[t]);
		}
		int &r=dp[id];
		A.Update(nw.x,r=A.Query(nw.y));
		B.Update(nw.x,
		for(int i=1;i<=ed;++i)
		{
			A.Update(p[lst[i]].x,dp[lst[i]]=A.Query(p[lst[i]].x));
			B.Update(p[lst[i]].x,dp[lst[i]]);
		}
	}
	else
	{
	}
}

signed main()
{
	scanf("%lld%lld",&n,&ki);
	u0.Read();
	v0.Read();
	for(int i=1;i<=n;++i)
	{
		p[i].Read();
		Trans(p[i]);
	}
	tot=n;
	scanf("%lld",&m);
	for(int i=1,op;i<=m;++i)
	{
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld",que+i);
			que[i]*=-1;
		}
		else
		{
			p[que[i]=++tot].Read();
			Trans(p[tot]);
			fl[tot]=(op==2);
		}
	}
	Prework();
	//for(int i=1;i<=tot;++i)
	//	Whats(p[i]);
	for(int i=1;i<=m;++i)
		if(que[i]<0)
			printf("%lld\n",dp[-que[i]]);
		else
			Update(fl[que[i]],que[i]);
	return 0;
}
