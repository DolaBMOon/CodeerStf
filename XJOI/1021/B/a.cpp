#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

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

const int _B=1e6;

char Nc()
{
	static char buf[_B],*p=buf,*q=buf;
	return (p==q&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:(*(p++));
}

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int res=ch-48;
	for(;isdigit(ch=Nc());res=res*10-48+ch);
	return res;
}

const int N=100000+10;
const int B=20;

int n,m;
int fir[N],nxt[N<<1],to[N<<1],tote;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int fa[N],st[N][B],dep[N];

void Dfs(int u)
{
	dep[u]=dep[st[u][0]=fa[u]]+1;
	for(int i=1;i<B;++i)
		st[u][i]=st[st[u][i-1]][i-1];
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa[u])
	{
		fa[v]=u;
		Dfs(v);
	}
}

int Lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=B-1,k;i>=0;--i)if(dep[k=st[x][i]]>=dep[y])
		x=k;
	if(x==y)
		return x;
	for(int i=B-1,k,k2;i>=0;--i)if((k=st[x][i])!=(k2=st[y][i]))
	{
		x=k;
		y=k2;
	}
	return fa[x];
}

vector<int> Add[N],Del[N];
int ans[N];

struct Heap
{

	priority_queue<int,vector<int>,greater<int> > P,Q;
	int sz;

	void Push(int x)
	{
		P.push(x);
		++sz;
	}

	void Del(int x)
	{
		Q.push(x);
		--sz;
	}

	int Top()
	{
		for(;!Q.empty()&&P.top()==Q.top();P.pop(),Q.pop());
		return P.top();
	}

	void Pop()
	{
		for(;!Q.empty()&&P.top()==Q.top();P.pop(),Q.pop());
		P.pop();
		--sz;
	}

}H[N];

int id[N];

void Merge(int u,int v)
{
	if(H[id[u]].sz<H[id[v]].sz)
		swap(id[u],id[v]);
	Heap &A=H[id[u]],&B=H[id[v]];
	for(;B.sz;B.Pop())
		A.Push(B.Top());
}

void Song(int u)
{
	id[u]=u;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa[u])
	{
		Song(v);
		Merge(u,v);
	}
	for(int i=0;i<(int)Add[u].size();++i)
		H[id[u]].Push(Add[u][i]);
	for(int i=0;i<(int)Del[u].size();++i)
		H[id[u]].Del(Del[u][i]);
	if(H[id[u]].sz)
		ans[u]=H[id[u]].Top();
	else
		ans[u]=-1;
}

int main()
{
	//scanf("%d%d",&n,&m);
	n=Read();
	m=Read();
	static int u[N],v[N];
	for(int i=1;i<n;++i)
	{
		//scanf("%d%d",u+i,v+i);
		u[i]=Read();
		v[i]=Read();
		Adde(u[i],v[i]);
	}
	Dfs(1);
	for(int i=1,a,b,val,f;i<=m;++i)
	{
		//scanf("%d%d%d",&a,&b,&val);
		a=Read();
		b=Read();
		val=Read();
		f=Lca(a,b);
		Add[a].push_back(val);
		Add[b].push_back(val);
		Del[f].push_back(val);
		Del[f].push_back(val);
	}
	Song(1);
	for(int i=1;i<n;++i)
		printf("%d\n",(fa[u[i]]==v[i])?ans[u[i]]:ans[v[i]]);
	return 0;
}
