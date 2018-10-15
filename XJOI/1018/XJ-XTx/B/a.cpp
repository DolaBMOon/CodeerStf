#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

const int _B=4e5;

char Nc()
{
	static char buf[_B],*p=buf,*q=buf;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
}

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int sum=ch-48;
	while(isdigit(ch=Nc()))
		sum=sum*10+ch-48;
	return sum;
}

#define Pir pair<int,int>
#define fir first
#define sec second

ostream& operator<<(ostream &os,Pir p)
{
	os<<"("<<p.fir<<","<<p.sec<<")";
	return os;
}

const int N=2e6+10;

struct Edge
{
	int v,w;
}edges[N];

int n;
int fir[N],nxt[N],tote;

void Adde(int u,int v,int w)
{
	//cout<<u<<","<<v<<endl;
	edges[++tote]=(Edge){v,w};
	nxt[tote]=fir[u];
	fir[u]=tote;
	edges[++tote]=(Edge){u,w};
	nxt[tote]=fir[v];
	fir[v]=tote;
}

Pir stk[N];
int tp;
bool vis[N];

Pir lst[N];
int ed;

bool Dfs(int u,int fa=0,int dep=0)
{
	stk[++tp]=(Pir){u,dep};
	vis[u]=true;
	for(int i=fir[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(e.v==fa)
			continue;
		if(vis[e.v])
		{
			//Whats(u);
			//Whats(e.v);
			for(Pir p(-1,0);p.fir!=e.v;)
			{
				p=stk[tp--];
				lst[++ed]=(Pir){p.fir,p.sec-stk[tp].sec};
			}
			lst[ed].sec=e.w;
			//Whats(ed);
			return true;
		}
		if(Dfs(e.v,u,dep+e.w))
			return true;
	}
	--tp;
	return false;
}

int main()
{
	n=Read();
	for(int i=1,u,v,w;i<=n;++i)
	{
		u=Read();
		v=Read();
		w=Read();
		Adde(u,v,w);
	}
	Dfs(1);
	memset
	return 0;
}
