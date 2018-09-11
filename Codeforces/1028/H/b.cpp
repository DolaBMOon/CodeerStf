#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

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

const int N=2e5;
const int M=6e6;
const int B=8;
const int Q=2e6;

bool vis[M];
int p[M],totp,tr[M],cnt[M];
vector<int> di[M];

void Prework()
{
	tr[1]=1;
	for(int i=2;i<M;++i)
	{
		if(!vis[i])
		{
			p[++totp]=i;
			tr[i]=i;
			cnt[i]=1;
			di[i].emplace_back(i);
		}

		for(int j=1,k;j<=totp&&p[j]*i<M;++j)
		{
			vis[k=p[j]*i]=true;
			if(i%p[j])
			{
				tr[k]=tr[i]*p[j];
				if(cnt[i])
				{
					cnt[k]=cnt[i]+1;
					di[k]=di[i];
					di[k].emplace_back(p[j]);
				}
			}
			else
				tr[k]=tr[i/p[j]];
		}
	}
}

void Song(vector<int>& v)
{
	static int rec[(1<<B)+10]={1};
	int n=v.size(),S=1<<n;
	for(int i=0;i<n;++i)
		rec[1<<i]=v[i];
	v.emplace_back(1);
	for(int i=1,j;i<S;++i)if(i!=(j=i&(-i)))
		v.emplace_back(rec[i]=rec[i^j]*rec[j]);
}

void GetMax(int& x,int y)
{
	x=((x<y)?y:x);
}

int n,q,a[N],ans[Q];
vector<Pii> v[N];

int dp[M][B],id[B<<1];

int main()
{
	Prework();

	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		a[i]=tr[a[i]];
		if((int)di[a[i]].size()==cnt[a[i]])
			Song(di[a[i]]);
	}
	for(int i=1,l,r;i<=q;++i)
	{
		scanf("%d%d",&l,&r);
		v[r].emplace_back(l,i);
	}

	for(int i=1,j,k;i<=n;++i)
	{
		for(int x:di[a[i]])
		{
			k=cnt[a[i]/x];
			for(j=0;j<B;++j)
				GetMax(id[j+k],dp[x][j]);
			dp[x][k]=i;
		}
		sort(v[i].begin(),v[i].end());
		j=0;
		for(Pii p:v[i])
		{
			for(;id[j]<p.fir;++j);
			ans[p.sec]=j;
		}
	}
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
	return 0;
}
