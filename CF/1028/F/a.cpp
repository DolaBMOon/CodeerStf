//%:pragma GCC optimize("Ofast")
//%:pragma GCC target("sse3","sse2","sse")
//%:pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
//%:pragma GCC target("f16c")
//%:pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
//%:pragma GCC diagnostic error "-fwhole-program"
//%:pragma GCC diagnostic error "-fcse-skip-blocks"
//%:pragma GCC diagnostic error "-funsafe-loop-optimizations"
//%:pragma GCC diagnostic error "-std=c++14"

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}

int q,tot;
map<LL,set<pii> > mp;
map<pii,int> sum;

pii operator+(pii a,pii b)
{
	return {a.fir+b.fir,a.sec+b.sec};
}

pii Song(pii p)
{
	int d=gcd(p.fir,p.sec);
	return {p.fir/d,p.sec/d};
}

void Insert(set<pii>& S,pii p)
{
	++tot;
	--sum[Song(p)];
	for(pii v:S)
		----sum[Song(p+v)];
	S.insert(p);
}

void Del(set<pii>& S,pii p)
{
	--tot;
	++sum[Song(p)];
	S.erase(p);
	for(pii v:S)
		++++sum[Song(p+v)];
}

int main()
{
	scanf("%d",&q);
	for(int i=1,ty,x,y;i<=q;++i)
	{
		scanf("%d%d%d",&ty,&x,&y);
		LL bel=(LL)x*x+(LL)y*y;
		switch(ty)
		{
			case 1:
				Insert(mp[bel],{x,y});
				break;
			case 2:
				Del(mp[bel],{x,y});
				break;
			case 3:
				printf("%d\n",tot+sum[Song({x,y})]);
				break;
		}
	}
	return 0;
}
