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

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n,m,kk,q;

int main()
{
	srand((unsigned long long)new char);
	n=20000;
	m=50000;
	kk=1;
	cout<<n<<" "<<m<<" "<<kk<<endl;
	for(int i=1;i<=n;++i)
		cout<<Randint(1,n)<<" ";
	puts("");
	for(int i=1;i<=n;++i)
		cout<<Randint(1,n)<<" ";
	puts("");
	for(int i=1,u,v;i<=m;++i)
	{
		while((u=Randint(1,n))==(v=Randint(1,n)));
		cout<<u<<" "<<v<<endl;
	}
	q=n;
	cout<<q<<endl;
	for(int i=1,k;i<=q;++i)
	{
		cout<<Randint(1,n)<<" "<<(k=Randint(0,4))<<" ";
		for(int j=1;j<=k;++j)
			cout<<Randint(1,n)<<" ";
	}
	return 0;
}
