#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
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

#define int long long

const int _B=1e6+10;

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

const int N=100010;

bool fl;
int n,m,l,q,cc;
vector<int> A[N],B[N];

signed main()
{
	n=Read();
	m=Read();
	l=Read();
	q=Read();
	if(n<m)
	{
		swap(n,m);
		fl=true;
	}
	for(int i=0;i<=n;++i)
	{
		A[i].resize(m+1);
		B[i].resize(m+1);
	}
	for(int i=1,ty,a,b,c,d,w;i<=q;++i)
	{
		ty=Read();
		a=Read();
		b=Read();
		c=Read();
		d=Read();
		if(fl)
		{
			swap(a,b);
			swap(c,d);
		}
		if(ty&1)
		{
			w=Read();
			for(int x=a;x<=c;++x)
				for(int y=b;y<=d;++y)
					A[x][y]+=w;
		}
		else
		{
			if(A[a][b]>=l||A[c][d]>=l)
			{
				puts("no");
				continue;
			}
			B[a][b]=++cc;
			for(int x=a;x<=c;++x)
			{
				bool ok=(x==a);
				for(int y=b;y<=d;++y)
					if(A[x][y]<l&&(B[x-1][y]==cc||B[x][y-1]==cc))
					{
						B[x][y]=cc;
						ok=true;
					}
				if(!ok)
					break;
			}
			puts(B[c][d]==cc?"yes":"no");
		}
	}
	return 0;
}
