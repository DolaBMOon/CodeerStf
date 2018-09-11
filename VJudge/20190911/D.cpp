#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<bitset>

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

const int N=1001;
const int C=10001;

int n,q;
bitset<C> S[C];

int main()
{
	n=Read();
	for(int i=1,c;i<=n;++i)
	{
		c=Read();
		for(int j=1;j<=c;++j)
			S[Read()][i]=true;
	}
	q=Read();
	for(int i=1,a,b;i<=q;++i)
	{
		a=Read();
		b=Read();
		puts((S[a]&S[b]).any()?"Yes":"No");
	}
	return 0;
}
