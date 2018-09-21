#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<map>

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

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=2333;
const int MOD=1e9+7;

void SU(int &a,int b)
{
	((a+=b)>=MOD)?(a-=MOD):0;
}

int n,m;
map<pair<int,int>,int> f,g;

int main()
{
	scanf("%d%d",&n,&m);
	f[Pir(0,0)]=1;
	g=f;
	for(int i=1;i<=n||i<=m;++i)
	{
		for(pair<Pir,int> p:f)
		{
			if(i<=n)
				SU(g[Pir(p.fir.fir^i,p.fir.sec)],p.sec);
			if(i<=m)
				SU(g[Pir(p.fir.fir,p.fir.sec^i)],p.sec);
		}
		f=g;
	}
	int ans=0;
	for(pair<Pir,int> p:f)if(p.fir.fir<p.fir.sec)
		SU(ans,p.sec);
	printf("%d",ans);
	return 0;
}
