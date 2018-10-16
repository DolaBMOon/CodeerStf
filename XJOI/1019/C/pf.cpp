#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<queue>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<"<<<<<<<<<<"endl
#define Divher() cout<<">>>>>>>>>>"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return (a<=b)?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return (a>=b)?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=200000+10;

priority_queue<int,vector<int>,greater<int> > P,Q;

void Push(int x)
{
	Q.push(x);
}

void Del(int x)
{
	P.push(x);
}

void Shrink()
{
	while(!P.empty()&&P.top()==Q.top())
	{
		P.pop();
		Q.pop();
	}
}

int Top()
{
	Shrink();
	return Q.top();
}

int n,m,a[N],q,du[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		++du[u];
		++du[v];
	}
	for(int i=1;i<=n;++i)
		du[i]=233;
	for(int i=1;i<=n;++i)if(du[i]>1)
		Push(a[i]);
	scanf("%d",&q);
	char s[3];
	for(int i=1,u,v;i<=q;++i)
	{
		scanf("%s%d%d",s,&u,&v);
		if(*s=='Q')
			printf("%d\n",max(0,a[u]-Top()));
		else if(du[u]>1)
		{
			Del(a[u]);
			Push(a[u]=v);
		}
	}
	return 0;
}
