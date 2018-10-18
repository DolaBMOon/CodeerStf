#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
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

const int N=100000+10;

int n,a[N],b[N],tot,fa[N],ans;
map<int,int> A,B,id;
bool vis[N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

void GG()
{
	puts("-1");
	exit(0);
}

void Merge(int x,int y)
{
	if(x!=y)
		++ans;
	if((x=Find(x))!=(y=Find(y)))
	{
		fa[x]=y;
		vis[y]=true;
		vis[x]=true;
	}
}

int main()
{
	scanf("%d",&n);
	int sm=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		sm^=a[i];
	}
	bool fl=true;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",b+i);
		fl&=(a[i]==b[i]);
	}
	if(fl)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		++A[a[i]];
		++B[b[i]];
	}
	++A[sm];
	int diff=0,x,y,w=-1;
	for(map<int,int>::iterator it=A.begin();it!=A.end();++it)
	{
		x=it->second;
		id[it->first]=++tot;
		y=B[it->first];
		if(x>y)
		{
			diff+=x-y;
			w=it->first;
		}
		else if(x<y)
			GG();
	}
	if(diff!=1)
		GG();
	a[++n]=sm;
	b[n]=w;
	for(int i=1;i<n;++i)
		Merge(id[a[i]],id[b[i]]);
	for(int i=1;i<=tot;++i)if(vis[i]&&!fa[i])
		++ans;
	if(vis[id[sm]])
		--ans;
	printf("%d\n",ans);
	return 0;
}
