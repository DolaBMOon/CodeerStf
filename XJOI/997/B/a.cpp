#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
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

#define Triple pair<int,pair<int,int> >
#define fir first
#define sec second.first
#define thi second.second

#define LL long long

const int N=5000000+10;
const int INF=0x3f3f3f3f;

int MOD;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

int Cu(int x,int y)
{
	return Mul(x,Qpow(y));
}

int n,wt;
char s[N];
int op[N],nu[N];
Triple w[N];
vector<int> G[N];

Triple mn[N<<2];

void Build(int o=1,int l=1,int r=n)
{
	if(l==r)
	{
		mn[o]=w[l];
		return;
	}
	int lc=o<<1,rc=lc^1,mid=(l+r)>>1;
	Build(lc,l,mid);
	Build(rc,mid+1,r);
	mn[o]=min(mn[lc],mn[rc]);
}

Triple Query(int ql,int qr,int o=1,int l=1,int r=n)
{
	if(ql<=l&&r<=qr)
		return mn[o];
	int lc=o<<1,rc=lc^1,mid=(l+r)>>1;
	Triple res;
	res.fir=INF;
	if(ql<=mid)
		GetMin(res,Query(ql,qr,lc,l,mid));
	if(qr>mid)
		GetMin(res,Query(ql,qr,rc,mid+1,r));
	return res;
}

int rt,lc[N],rc[N],fu[N],ans[N],sz;

void Buildx(int &o=rt,int l=1,int r=n)
{
	Triple t=Query(l,r);
	o=-t.thi;
	if(l<o)
		Buildx(lc[o],l,o-1);
	else
		fu[lc[o]=++sz]=nu[o-1];
	if(o<r)
		Buildx(rc[o],o+1,r);
	else
		fu[rc[o]=++sz]=nu[o];
	int a=fu[lc[o]],b=fu[rc[o]];
	switch(op[o])
	{
		case 0:fu[o]=U(a,b);break;
		case 1:fu[o]=D(a,b);break;
		case 2:fu[o]=Mul(a,b);break;
		case 3:fu[o]=Cu(a,b);break;
	}
}

void Song(int o=rt,int k=wt)
{
	if(o>n)
	{
		switch(k)
		{
			case -1:
				puts("-1");
				break;
			case -2:
				puts("No Solution");
				break;
			default:
				printf("%d\n",k);
				break;
		}
		return;
	}
	if(k<0)
	{
		Song(lc[o],k);
		Song(rc[o],k);
		return;
	}
	switch(op[o])
	{
		case 0:
			Song(lc[o],D(k,fu[rc[o]]));
			Song(rc[o],D(k,fu[lc[o]]));
			break;
		case 1:
			Song(lc[o],U(k,fu[rc[o]]));
			Song(rc[o],D(fu[lc[o]],k));
			break;
		case 2:
			if(fu[rc[o]])
				Song(lc[o],Cu(k,fu[rc[o]]));
			else if(k)
				Song(lc[o],-2);
			else
				Song(lc[o],-1);
			if(fu[lc[o]])
				Song(rc[o],Cu(k,fu[lc[o]]));
			else if(k)
				Song(rc[o],-2);
			else
				Song(rc[o],-1);
			break;
		case 3:
			Song(lc[o],Mul(k,fu[rc[o]]));
			if(fu[lc[o]])
			{
				if(k)
					Song(rc[o],Cu(fu[lc[o]],k));
				else
					Song(rc[o],-2);
			}
			else if(k)
				Song(rc[o],-2);
			else
				Song(rc[o],-1);
			break;
	}
}

int main()
{
	scanf("%*d%d%s",&MOD,s+1);
	int len=strlen(s+1);
	int st=1;
	for(;s[st]!='=';wt=wt*10-48+s[st],++st);
	for(int i=st+1,a=0;i<=len;++i)
	{
		if(isdigit(s[i]))
		{
			int &x=nu[n];
			x=s[i]-48;
			int j;
			for(j=i+1;isdigit(s[j]);++j)
				x=x*10-48+s[j];
			i=j-1;
			//Whats(x);
		}
		else
		{
			switch(s[i])
			{
				case '+':
					w[++n].fir=a;
					w[n].thi=-n;
					break;
				case '-':
					op[++n]=1;
					w[n].fir=a;
					w[n].thi=-n;
					break;
				case '*':
					op[++n]=2;
					w[n].fir=a;
					w[n].sec=1;
					w[n].thi=-n;
					break;
				case '/':
					op[++n]=3;
					w[n].fir=a;
					w[n].sec=1;
					w[n].thi=-n;
					break;
				case '(':++a;break;
				case ')':--a;break;
			}
		}
	}
	Build();
	sz=n;
	Buildx();
	Song();
	return 0;
}
