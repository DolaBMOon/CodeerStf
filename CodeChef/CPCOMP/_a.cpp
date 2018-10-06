#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

const int N=2e5+10;

int p[N],totp;
bool vis[N];
vector<int> D[N];

void Prework()
{
	for(int i=2;i<N;++i)
	{
		if(!vis[i])
			p[++totp]=i;
		for(int j=1;j<=totp&&p[j]*i<N;++j)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
	for(int i=1;i<=totp;++i)
		for(int j=p[i];j<N;j+=p[i])
			D[j].emplace_back(i);
}

int n,a[N];

int main()
{
	Prework();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	return 0;
}
