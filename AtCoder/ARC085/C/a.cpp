#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<queue>

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

#define int long long

const int N=233;
const int S=N-2;
const int T=N-3;
const int M=2333;
const int INF=0x3f3f3f3f3f3f3f3f;

struct Edge
{
	int v,cap,cost;
}edges[M];

int n,a[N];
int fir[N],nxt[N],tote=1;

void Adde(int u,int v,int cap,int cost)
{
	edges[++tote]=(Edge){v,cap,cost};
	nxt[tote]=fir[u];
	fir[u]=tote;
	edges[++tote]=(Edge){u,0,-cost};
	nxt[tote]=fir[v];
	fir[v]=tote;
}

bool inq[N];
int d[N],cur[N];

bool Spfa()
{
	static queue<int> Q;
	memset(d,0x3f,sizeof d);
	Q.push(S);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		inq[u]=false;
		for(int i=fir[u];i;i=nxt[i])
		{
			Edge &e=edges[i];
			if(e.cap&&d[e.v]>d[u]+e.cost)
			{
				d[e.v]=d[u]+e.cost;
				if(!inq[e.v])
				{
					Q.push(e.v);
					inq[e.v]=true;
				}
			}
		}
	}
	return d[T]<0;
}

int Dfs(int u,int a=INF)
{
	if(u==T||!a)
		return a;
	inq[u]=true;
	int f=0,af;
	for(int &i=cur[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(!inq[e.v]&&d[e.v]==d[u]+e.cost&&(af=Dfs(e.v,min(a,e.cap))))
		{
			f+=af;
			a-=af;
			e.cap-=af;
			edges[i^1].cap+=af;
		}
	}
	inq[u]=false;
	return f;
}

int MinCost()
{
	int res=0;
	while(Spfa())
	{
		memcpy(cur,fir,sizeof(cur));
		res+=Dfs(S)*d[T];
	}
	return res;
}

signed main()
{
	scanf("%lld",&n);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		ans+=a[i];
	}
	for(int i=1;i<=n;++i)
		Adde(S,i,INF,0);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			Adde(i,n+j,INF,0);
	for(int i=1;i<=n;++i)
		Adde(n+i,T,1,a[i]);
	ans-=MinCost();
	printf("%lld",ans);
	return 0;
}
