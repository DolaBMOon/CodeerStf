#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=1e5;

int n,m,p,c;
int lst[N],ed;

int Phi(int x)
{
	int res=x;
	for(int i=2;i*i<=x;++i)if(x%i==0)
	{
		res/=i;
		res*=i-1;
		for(;x%i==0;x/=i);
	}
	if(x>1)
		res*=x-1;
	return res;
}

void Prework()
{
	for(lst[ed=1]=p;p!=1;lst[++ed]=p=Phi(p));
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&p,&c);
	Prework();
	for(int i=1;i<=n;++i)
	{
	}
	return 0;
}
