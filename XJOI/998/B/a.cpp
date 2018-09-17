#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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

const int N=2e7+10;
const int M=(1<<20)+10;
const int S=(1<<20)-1;

int q,mem[M],rex[M];
int ch[N][2],sz=1;
int f[M],g[M];

void Insert(int x)
{
	int nw=1;
	for(int i=19,k;~i;--i)
	{
		k=(x>>i)&1;
		if(!ch[nw][k])
			ch[nw][k]=++sz;
		nw=ch[nw][k];
	}
}

int MXor(int x)
{
	int nw=1,res=0;
	for(int i=19,k;~i;--i)
	{
		k=(x>>i)&1;
		if(ch[nw][k^1])
		{
			nw=ch[nw][k^1];
			res^=(1<<i);
		}
		else
			nw=ch[nw][k];
	}
	return res;
}

int main()
{
	//scanf("%d",&q);
	q=Read();
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	for(int i=1,op,x;i<=q;++i)
	{
		//scanf("%d%d",&op,&x);
		op=Read();
		x=Read();
		if(op==1)
		{
			Insert(x);
			GetMin(f[x],i);
			GetMin(g[x],i);
		}
		else
		{
			mem[i]=x;
			rex[i]=MXor(x);
			if(op==3)
				mem[i]*=-1;
		}
	}
	for(int i=S;i>=1;--i)
		for(int j=1<<19;j;j>>=1)if(i&j)
			GetMin(f[i^j],f[i]);
	for(int i=S;i>=1;--i)
		for(int j=1<<19;j;j>>=1)if(i&j)
			GetMin(g[i^j],g[i]);
	for(int i=1;i<=q;++i)if(mem[i])
	{
		if(mem[i]<0)
		{
			printf("%d\n",rex[i]);
			continue;
		}
		int x=mem[i],rea=0,reo=0;
		for(int k=1<<19;k;k>>=1)if((x&k)&&f[rea^k]<i)
			rea^=k;
		for(int k=1<<19;k;k>>=1)if(!(x&k)&&g[reo^k]<i)
			reo^=k;
		reo^=x;
		printf("%d %d %d\n",rex[i],rea,reo);
	}
	return 0;
}
