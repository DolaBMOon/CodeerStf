#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

const int N=520;
const int M=5200;

int n,m,a[M],b[M],w[M];
bool G[N][N];

int main()
{
	n=300;
	m=2500;
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=m;++i)
	{
		while(true)
		{
			a[i]=rand()%n+1;
			b[i]=rand()%n+1;
			if(a[i]!=b[i]&&!G[a[i]][b[i]])
				break;
		}
		w[i]=rand()%1000000+1;
	}
	for(int i=1;i<=m;++i)
		cout<<a[i]-1<<" ";
	cout<<endl;
	for(int i=1;i<=m;++i)
		cout<<b[i]-1<<" ";
	cout<<endl;
	for(int i=1;i<=m;++i)
		cout<<w[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%1000000+1<<" ";
	cout<<endl;
	return 0;
}
