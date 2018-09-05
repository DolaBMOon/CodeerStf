%:pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
%:pragma GCC diagnostic error "-fwhole-program"
%:pragma GCC diagnostic error "-fcse-skip-blocks"
%:pragma GCC diagnostic error "-funsafe-loop-optimizations"

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define Pii pair<int,int>
#define fir first
#define sec second
#define makr(x,y) make_pair((x),(y))
#define It set<Pii>::iterator

const int _B=1e6;

char Nc()
{
	static char buf[_B],*p=buf,*q=buf;
	return (p==q&&((q=buf+fread(buf,1,_B,stdin))==(p=buf)))?0:(*(p++));
}

int Read()
{
	int res;
	char ch;
	while(!isdigit(ch=Nc()));
	res=ch-48;
	while(isdigit(ch=Nc()))
		res=res*10+ch-48;
	return res;
}

const int N=5e6+10;

int n,m,rt[N];

int lc[N],rc[N],cnt[N],fl[N],tot;

void Insert(int& o,int q,int l=1,int r=n)
{
	if(!o)
		o=++tot;
	++cnt[o];
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(q<=mid)
		Insert(lc[o],q,l,mid);
	else
		Insert(rc[o],q,mid+1,r);
}

void Merge(int& x,int y)
{
	if(x&&y)
	{
		Merge(lc[x],lc[y]);
		Merge(rc[x],rc[y]);
		cnt[x]=cnt[lc[x]]+cnt[rc[x]];
	}
	else if(y)
		x=y;
}

void Split(int& x,int& y,int k)
{
	if(cnt[x]!=k)
	{
		y=++tot;
		int t=cnt[lc[x]];
		if(t>=k)
		{
			rc[y]=rc[x];
			rc[x]=0;
			if(t>k)
				Split(lc[x],lc[y],k);
		}
		else
			Split(rc[x],rc[y],k-t);
		cnt[x]=cnt[lc[x]]+cnt[rc[x]];
		cnt[y]=cnt[lc[y]]+cnt[rc[y]];
	}
	else
		y=0;
}

int Kth(int o,int k,int l=1,int r=n)
{
	if(l==r)
		return l;
	int t=cnt[lc[o]];
	if(t>=k)
		return Kth(lc[o],k,l,(l+r)>>1);
	else
		return Kth(rc[o],k-t,((l+r)>>1)+1,r);
}

set<Pii> S;

void SplitHD(It it,int y)
{
	int x=it->fir,r=it->sec;
	if(x==r||x==y)
		return;
	S.erase(it);
	if(fl[x])
	{
		rt[y]=rt[x];
		Split(rt[y],rt[x],r-y+1);
		fl[y]=1;
	}
	else
	{
		Split(rt[x],rt[y],y-x);
		fl[y]=0;
	}
	S.insert(makr(x,y-1));
	S.insert(makr(y,r));
}

int main()
{
	n=Read();
	m=Read();
	for(int i=1,a;i<=n;++i)
	{
		a=Read();
		S.insert(makr(i,i));
		Insert(rt[i],a);
	}

	for(int i=1,ty,l,r;i<=m;++i)
	{
		ty=Read();
		l=Read();
		r=Read();
		It it=--S.upper_bound(makr(l,n));
		SplitHD(it,l);
		if(r<n)
		{
			it=--S.upper_bound(makr(r+1,n));
			SplitHD(it,r+1);
		}
		int t=0;
		for(It i=S.upper_bound(makr(l,0)),j=S.upper_bound(makr(r+1,0)),k;i!=j;)
		{
			k=(i++);
			Merge(t,rt[k->fir]);
			S.erase(k);
		}
		rt[l]=t;
		fl[l]=ty;
		S.insert(makr(l,r));
	}

	int k,t;
	k=Read();
	for(It i=S.begin();i!=S.end();++i,k-=t)
		if((t=cnt[rt[i->fir]])>=k)
		{
			if(fl[i->fir])
				printf("%d\n",Kth(rt[i->fir],cnt[rt[i->fir]]-k+1));
			else
				printf("%d\n",Kth(rt[i->fir],k));
			return 0;
		}
	return 0;
}
