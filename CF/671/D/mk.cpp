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
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=233;

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n,m,fa[N];

vector<int> v[N];

int main()
{
	srand((unsigned long long)new char);
	n=5;
	m=8;
	cout<<n<<" "<<m<<endl;
	v[1].emplace_back(1);
	for(int i=2;i<=n;++i)
	{
		cout<<(fa[i]=Randint(1,i-1))<<" "<<i<<endl;
		v[i]=v[fa[i]];
		v[i].emplace_back(i);
	}
	for(int i=1,u;i<=m;++i)
	{
		u=Randint(1,n);
		random_shuffle(v[u].begin(),v[u].end());
		cout<<u<<" "<<v[u].front()<<" "<<Randint(1,10)<<endl;
	}
	return 0;
}
