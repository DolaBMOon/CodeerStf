#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<map>
#include<set>
#include<vector>

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

const int _B=1e6;

char Nc()
{
	//return getchar();
	static char buf[_B],*p,*q;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:(*(p++));
}

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int res=ch-48;
	while(isdigit(ch=Nc()))
		res=res*10-48+ch;
	return res;
}

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=500000+10;

struct Edge
{
	int u,v,x;
}edges[N];

int n,m,kk,q;
int a[N],b[N],fuck[N];

bool Cmp(const Edge &a,const Edge &b)
{
	return a.x<b.x;
}

int id[N],V[N];
vector<int> ban[N];

bool Cmp2(int x,int y)
{
	return V[x]<V[y];
}

struct Data
{
	int val;
	map<int,int> cnt;
}data[N];

int fa[N];
set<Pir,greater<Pir> > S;
set<int> T;

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

bool Jud(int x)
{
	return x&&(x%kk==0);
}

void Join(Data &a,Data &b)
{
	if(a.cnt.size()<b.cnt.size())
		swap(a,b);
	for(map<int,int>::iterator it=b.cnt.begin();it!=b.cnt.end();++it)
	{
		int &x=a.cnt[it->fir];
		a.val-=Jud(x);
		a.val+=Jud(x+=it->sec);
	}
	b.cnt.clear();
}

void Hb(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x==y)
		return;
	//cout<<x<<"--"<<y<<endl;
	fa[y]=x;
	//cout<<data[x].val<<":"<<data[y].val<<endl;
	S.erase(Pir(data[y].val,y));
	S.erase(Pir(data[x].val,x));
	Join(data[x],data[y]);
	S.insert(Pir(data[x].val,x));
}

bool Cmpf(int x,int y)
{
	return a[x]<a[y];
}

int main()
{
	//scanf("%d%d%d",&n,&m,&kk);
	n=Read();
	m=Read();
	kk=Read();
	for(int i=1;i<=n;++i)
		a[i]=Read();//scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		b[i]=Read();//scanf("%d",b+i);
	for(int i=1;i<=n;++i)
		fuck[i]=i;
	sort(fuck+1,fuck+n+1,Cmpf);
	for(int i=1;i<=m;++i)
	{
		//scanf("%d%d",&edges[i].u,&edges[i].v);
		edges[i].u=Read();
		edges[i].v=Read();
		edges[i].x=max(a[edges[i].u],a[edges[i].v]);
	}

	sort(edges+1,edges+m+1,Cmp);
	//scanf("%d",&q);
	q=Read();
	for(int i=1,k;i<=q;++i)
	{
		id[i]=i;
		//scanf("%d%d",V+i,&k);
		V[i]=Read();
		k=Read();
		for(int j=0,x;j<k;++j)
		{
			x=Read();//scanf("%d",&x);
			ban[i].push_back(x);
		}
	}
	for(int i=1;i<=n;++i)
	{
		data[i].val=(kk==1);
		data[i].cnt[b[i]]=1;
	}

	sort(id+1,id+q+1,Cmp2);
	for(int i=1,p=0,pp=0,t;i<=q;++i)
	{
		t=id[i];
		for(;pp<n&&a[fuck[pp+1]]<=V[t];++pp,S.insert(Pir(data[fuck[pp]].val,fuck[pp])));
		for(;p<m&&edges[p+1].x<=V[t];++p,Hb(edges[p].u,edges[p].v));
		T.clear();
		for(vector<int>::iterator it=ban[t].begin();it!=ban[t].end();++it)
			T.insert(Find(*it));
		bool fl=false;
		for(set<Pir>::iterator it=S.begin();it!=S.end()&&!fl;++it)
			if(!T.count(it->sec))
			{
				V[t]=it->fir;
				fl=true;
			}
		if(!fl)
			V[t]=0;
	}
	for(int i=1;i<=q;++i)
		printf("%d\n",V[i]);
	return 0;
}
