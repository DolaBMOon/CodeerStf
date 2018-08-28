#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<"<<end
#define Oops() cout<<"!!!!!!!!!!"<<endl

#define pii pair<int,int>
#define fir first
#define sec second

const int N=100000+10;
const int INF=0x3f3f3f3f;

struct Data
{
	int u,v,w;
};

struct Cmp
{
	bool operator()(const Data& a,const Data& b)
	{
		return a.w>b.w;
	}
};

int n,m,c,A,B;
int fa[N],p[N],p2[N],d[N];

vector<pii> G[N];
priority_queue<Data,vector<Data>,Cmp> Q;

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

void Hb(int x,int y)
{
	fa[Find(x)]=Find(y);
}

void Next(int x)
{
	int &t=p[x],&t2=p2[x];
	if(fa[t2])
		t2=Find(t2);
	for(;;)
	{
		if(t<(int)G[x].size()&&(t2>n||G[x][t].fir<t2*c))
		{
			if(!fa[G[x][t].sec])
			{
				Q.push({x,G[x][t].sec,d[x]+G[x][t].fir});
				++t;
				break;
			}
			continue;
		}
		else if(t2<=n)
		{
			Q.push({x,t2^x,d[x]+t2*c});
			break;
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1,u,v,d;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&d);
		G[u].emplace_back(d,v);
	}
	for(int i=1;i<=n;++i)
		sort(G[i].begin(),G[i].end());
	memset(d,0x3f,sizeof d);
	scanf("%d%d",&A,&B);
	Next(A);
	Hb(A,A+1);
	while(!Q.empty())
	{
		Data da=Q.top();
		Q.pop();
		Next(da.u);
	}
	return 0;
}
