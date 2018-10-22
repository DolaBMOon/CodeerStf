#pragma GCC optimize(1)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

#define LL long long

const int _B=1e6;

char Nc()
{
	static char buf[_B],*p=buf,*q=buf;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
}

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int sum=ch-48;
	while(isdigit(ch=Nc()))
		sum=sum*10+ch-48;
	return sum;
}

const int N=300000+10;

int n,m;

set<int> G[N];

void Adde(int u,int v)
{
	G[u].insert(v);
	G[v].insert(u);
}

int rp[N],fa[N],mn[N];

int Find(int u)
{
	return fa[u]?(fa[u]=Find(fa[u])):u;
}

void Shrink(set<int> &S,int x)
{
	while(!S.empty()&&*S.begin()<x)
		S.erase(S.begin());
}

int Join(int u,int l)
{
	Shrink(G[u],l);
	for(set<int>::iterator v=G[u].begin();v!=G[u].end()&&*v<=u;++v)if(l<=*v&&*v<=u)
	{
		int x=Find(u),y=Find(*v);
		if(x==y)
			return mn[x];
		else
		{
			fa[x]=y;
			GetMin(mn[x],mn[y]);
		}
	}
	//return 0;
}

int l[N],r[N];
LL ans[N];
vector<int> Q[N];

LL sm[N<<2],lz[N<<2];

void Add(int ql,int qr,int o=1,int l=1,int r=n)
{
	sm[o]+=(min(qr,r)-max(ql,l)+1);
	if(ql<=l&&r<=qr)
	{
		++lz[o];
		return;
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1;
	if(ql<=mid)
		Add(ql,qr,lc,l,mid);
	if(qr>mid)
		Add(ql,qr,rc,mid+1,r);
}

LL Query(int ql,int qr,int o=1,int l=1,int r=n)
{
	if(ql<=l&&r<=qr)
		return sm[o];
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1;
	LL res=lz[o]*(min(qr,r)-max(ql,l)+1);
	if(ql<=mid)
		res+=Query(ql,qr,lc,l,mid);
	if(qr>mid)
		res+=Query(ql,qr,rc,mid+1,r);
	return res;
}

int main()
{
	//scanf("%d%d",&n,&m);
	n=Read();
	m=Read();
	for(int i=1;i<=m;++i)
		Adde(Read(),Read());
	for(int i=1,j=2,r;i<=n&&j<=n;i=r+1)
	{
		for(int k=i;k<j;++k)
		{
			fa[k]=0;
			mn[k]=k;
			Join(k,i);
		}
		while(true)
		{
			fa[j]=0;
			mn[j]=j;
			r=Join(j,i);
			if(r)
				break;
			if(j==n)
			{
				++j;
				r=n;
				break;
			}
			++j;
		}
		for(int k=i;k<=r;++k)
			rp[k]=j-1;
	}
	int q=Read();
	for(int i=1;i<=q;++i)
	{
		l[i]=Read();
		r[i]=Read();
		Q[l[i]].push_back(i);
	}
	for(int i=n;i>=1;--i)
	{
		Add(i,rp[i]);
		for(int j=0;j<(int)Q[i].size();++j)
			ans[Q[i][j]]=Query(l[Q[i][j]],r[Q[i][j]]);
	}
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
	return 0;
}
