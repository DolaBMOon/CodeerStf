#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
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

#define H unsigned long long
#define Pii pair<int,int>
#define Pdi pair<double,int>
#define fir first
#define sec second

ostream& operator<<(ostream& os,Pii p)
{
	os<<"("<<p.fir<<","<<p.sec<<")";
	return os;
}

const int N=90;
const int L=1e5+10;
const H C=233;

int n,len,k,ans;
char s[N][L];
H h[N][L],pw[L];
vector<Pii> p[L];

Pdi dp[L];

void Update(Pdi &a,const Pdi &b)
{
	a=((a.fir!=b.fir)?(a.fir>b.fir):(a.sec<b.sec))?a:b;
}

bool Check(double x)
{
	for(int i=1;i<=len;++i)
	{
		dp[i]=dp[i-1];
		for(Pii j:p[i])
		{
			Pdi t=dp[j.sec-1];
			t.fir+=x+j.fir;
			++t.sec;
			Update(dp[i],t);
		}
	}
	if(dp[len].sec<=k)
	{
		GetMax(ans,(int)(dp[len].fir-dp[len].sec*x+0.5));
		return true;
	}
	return false;
}

H GetH(int id,int l,int r)
{
	return h[id][r]-h[id][l-1]*pw[r-l+1];
}

int Calc(int l,int r)
{
	set<H> S;
	int cnt=0;
	for(int i=1;i<=n;++i)
		cnt+=S.insert(GetH(i,l,r)).sec;
	return cnt;
}

void Song(int l,int r,int ed)
{
	int k=Calc(l,ed);
	if((l==r)||k==Calc(r,ed))
	{
		p[ed].emplace_back(k,r);
		return;
	}
	int m=(l+r)>>1;
	Song(l,m,ed);
	Song(m+1,r,ed);
}

void Fix(vector<Pii> &v)
{
	static vector<Pii> t;
	t=v;
	sort(t.begin(),t.end());
	v.clear();
	for(;!t.empty();t.pop_back())
	{
		if(v.empty()||t.back().fir!=v.back().fir)
			v.emplace_back(t.back());
	}
}

void Prework()
{
	pw[0]=1;
	for(int i=1;i<=len;++i)
		pw[i]=pw[i-1]*C;
	for(int i=1;i<=len;++i)
	{
		Song(1,i,i);
		Fix(p[i]);
	}
}

int main()
{
	scanf("%d%d%d",&n,&len,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=len;++j)
			h[i][j]=h[i][j-1]*C+s[i][j];
	}
	Prework();
	for(double l=-100,m,r=100;l<=r;)
	{
		if(Check(m=(l+r)*0.5))
			l=m+1e-6;
		else
			r=m-1e-6;
	}
	printf("%d",ans);
	return 0;
}
