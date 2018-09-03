#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=1e5+10;
const int ALPHA=27;
const int MAXSG=30;

char s[N];
int id[N],n,m;

struct Data
{
	int l,r,sg;
};

vector<Data> v[ALPHA][ALPHA];
int np[N][ALPHA],sgsm[ALPHA][N],pre[N][ALPHA],nxt[N][ALPHA];

void Append(int x,int y,int l,int r)
{
	v[x][y].emplace_back(l,r,-1);
	np[l][y]=v[x][y].size()-1;
}

int Get(int l,int r)
{
	if(l==r)
		return true;
	if(l>r)
		return false;
	int x=id[l-1],y=id[r+1],t;
	if((t=np[l-1][y])&&v[x][y][t].r==r+1)
		return v[x][y][t].sg;

	bool vis[MAXSG]={false};
	int res=0;

	for(int i=1,il,ir,w,p,q;i<ALPHA;++i)if((il=nxt[l-1][i])&&il<=r)
	{
		ir=pre[r+1][i];
		p=;
		q=np[il][i]-1;
		w=Get(l,il-1)^Get(ir+1,r)^sgsm[i][np[ir][i]-1]*sgsm[i][q];
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
	int l=v[x][y][rk].l+1,r=v[x][y][rk].r-1;
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
			t=np[x][i][l-1];
			Fix(x,i,t);
			w^=sg[x][i][t];
		}
		if(r!=ir)
		{
			t=np[i][y][ir];
			Fix(i,y,t);
			w^=sg[i][y][t];
		}
		for(int j=np[i][i][il],jj=np[i][i][ir];j<jj;++j)
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

	memset(sg,-1,sizeof sg);
	for(int i=0;i<ALPHA;++i)
		for(int j=0;j<ALPHA;++j)if(i||j)
			for(int k=1,kk=ed[i][j];k<=kk;++k)
				Fix(i,j,k);

	for(int i=1,*a,*s;i<ALPHA;++i)
	{
		a=sg[i][i];
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
		puts(Get(l,r)?"Alice":"Bob");
	}
	return 0;
}
