#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<unordered_map>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
	 -<Unlimited Blade Works>-
 */

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=1e5+10;
const int ALPHA=27;
const int MAXSG=30;

char s[N];
int id[N],n,m;

int ed[ALPHA][ALPHA],np[N][ALPHA],sgsm[ALPHA][N],pre[N][ALPHA],nxt[N][ALPHA];
vector<int> p[ALPHA][ALPHA],rp[ALPHA][ALPHA],sg[ALPHA][ALPHA];

void Append(int x,int y,int l,int r)
{
	int nw=++ed[x][y];
	if(nw==1)
	{
		p[x][y].emplace_back(0);
		rp[x][y].emplace_back(0);
		sg[x][y].emplace_back(0);
	}
	p[x][y].emplace_back(l);
	rp[x][y].emplace_back(r);
	np[l][y]=nw;
	sg[x][y].emplace_back(-1);
}

unordered_map<int,int> memo[N];

int GetAns(int l,int r)
{
	if(l==r)
		return 1;
	if(l>r)
		return 0;
	if(memo[l].count(r))
		return memo[l][r];
	int &res=memo[l][r];
	int x=id[l-1],y=id[r+1],t;
	if((t=np[l-1][y])&&rp[x][y][t]==r+1)
		return res=sg[x][y][t];

	bool vis[MAXSG]={false};

	for(int i=1,il,ir,w;i<ALPHA;++i)if((il=nxt[l-1][i])&&il<=r)
	{
		ir=pre[r+1][i];
		if(!np[ir][i]&&il!=ir)
			np[ir][i]=np[pre[ir][i]][i]+1;
		w=GetAns(l,il-1)^GetAns(ir+1,r)^sgsm[i][np[ir][i]-1]^sgsm[i][np[il][i]-1];
		vis[w]=true;
		for(;vis[res];++res);
	}
	return res;
}

void Fix(int x,int y,int rk)
{
	int &res=sg[x][y][rk];
	if(~res)
		return;
	int l=p[x][y][rk]+1,r=rp[x][y][rk]-1;
	if(l==r)
		return (void)(res=1);
	else if(l>r)
		return (void)(res=0);

	bool vis[MAXSG]={false};
	memset(vis,0,sizeof vis);
	res=0;

	for(int i=1,il,ir,w,t;i<ALPHA;++i)if((il=nxt[l-1][i])&&il<=r)
	{
		w=0;
		ir=pre[r+1][i];
		if(l!=il)
		{
			t=np[l-1][i];
			Fix(x,i,t);
			w^=sg[x][i][t];
		}
		if(r!=ir)
		{
			t=np[ir][y];
			Fix(i,y,t);
			w^=sg[i][y][t];
		}
		if(!np[ir][i]&&il!=ir)
			np[ir][i]=np[pre[ir][i]][i]+1;
		for(int j=np[il][i],jj=np[ir][i];j<jj;++j)
		{
			Fix(i,i,j);
			w^=sg[i][i][j];
		}
		vis[w]=true;
		for(;vis[res];++res);
	}
}

void Prework()
{
	for(int i=1;i<=n;++i)
		id[i]=s[i]-'a'+1;
	for(int i=1;i<ALPHA;++i)
		for(int j=1;j<ALPHA;++j)
			for(int k=1,l=0;k<=n;++k)
			{
				if(l&&id[k]==j)
				{
					Append(i,j,l,k);
					l=0;
				}
				if(id[k]==i)
					l=k;
			}

	for(int i=1;i<=n;++i)
		if(!ed[0][id[i]])
			Append(0,id[i],0,i);

	for(int i=n;i>=1;--i)
		if(!ed[id[i]][0])
			Append(id[i],0,i,n+1);

	for(int i=2;i<=n+1;++i)
	{
		for(int j=1;j<ALPHA;++j)
			pre[i][j]=pre[i-1][j];
		pre[i][id[i-1]]=i-1;
	}

	for(int i=n-1;i>=0;--i)
	{
		for(int j=1;j<ALPHA;++j)
			nxt[i][j]=nxt[i+1][j];
		nxt[i][id[i+1]]=i+1;
	}

	for(int i=0;i<ALPHA;++i)
		for(int j=0;j<ALPHA;++j)if(i||j)
			for(int k=1,kk=ed[i][j];k<=kk;++k)
				Fix(i,j,k);

	for(int i=1,*s;i<ALPHA;++i)
	{
		vector<int> &a=sg[i][i];
		s=sgsm[i];
		for(int j=1,jj=ed[i][i];j<=jj;++j)
			s[j]=s[j-1]^a[j];
	}
}

int main()
{
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	Prework();
	for(int i=1,l,r;i<=m;++i)
	{
		scanf("%d%d",&l,&r);
		puts(GetAns(l,r)?"Alice":"Bob");
	}
	return 0;
}
