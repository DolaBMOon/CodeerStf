#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

#define int unsigned

const int _B=1e6+10;

char Nc()
{
	static char buf[_B],*p=buf,*q=buf;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
}

int Read()
{
	char ch;
	while('0'>(ch=Nc())||'9'<ch);
	int sum=ch-48;
	while('0'<=(ch=Nc())&&ch<='9')
		sum=sum*10+ch-48;
	return sum;
}

const int N=2e7;
const int A=5200727;

int n,q,ans,l[N],r[N];
int C[N];

signed main()
{
	n=Read()+A;
	q=Read();
	bool fl=false;
	for(int x,v;q--;fl^=1)
	{
		if(fl)
		{
			x=Read()+A;
			for(;x;x&=(x-1))
				ans^=C[x];
		}
		else
		{
			x=Read()+A;
			v=Read();
			for(;x<=n;x+=x&(-x))
				C[x]^=v;
		}
	}
	printf("%u",ans);
	return 0;
}
