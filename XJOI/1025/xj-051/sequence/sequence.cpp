#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
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

const int K=21;
const int N=5e5+10;
const int MOD=1e9+7;

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

int n,m,l[N],r[N],qk[N],sm[N][K];

void Prework()
{
	sm[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		sm[i][0]=1;
		for(int j=1;j<K;++j)
			sm[i][j]=U(sm[i][j-1],sm[i-1][j]);
	}
}

int st[N],res[K],ans[N];
vector<int> ed[N];

void Solve(int ki)
{
	for(int i=1;i<=n;++i)
	{
		st[i]=0;
		ed[i].clear();
	}
	for(int i=1;i<=m;++i)if(qk[i]==ki)
	{
		++st[l[i]];
		ed[r[i]+1].push_back(r[i]-l[i]+1);
	}
	for(int i=0;i<=ki;++i)
		res[i]=0;
	for(int i=1;i<=n;++i)
	{
		for(int t=0,v;t<(int)ed[i].size();++t)
		{
			v=ed[i][t];
			for(int j=0;j<=ki;++j)
				SD(res[j],sm[v][j]);
		}
		SU(res[0],st[i]);
		for(int j=1;j<=ki;++j)
			SU(res[j],res[j-1]);
		SU(ans[i],res[ki]);
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d",&n,&m);
	Prework();
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",l+i,r+i,qk+i);
	for(int i=0;i<K;++i)
		Solve(i);
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}
