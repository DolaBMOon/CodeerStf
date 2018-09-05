#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<cmath>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=100;
const int NN=N*N;

int p[N+10],totp,d[NN+10],mu[N+10];
bool vis[N+10];

void Prework()
{
	mu[1]=1;
	for(int i=2;i<=N;++i)
	{
		if(!vis[i])
		{
			p[++totp]=i;
			mu[i]=-1;
		}
		for(int j=1,k;j<=totp&&p[j]*i<=N;++j)
		{
			vis[k=p[j]*i]=true;
			if(i%p[j])
				mu[k]=-mu[i];
			else
				break;
		}
	}
	for(int i=1;i<=NN;++i)
		for(int j=i;j<=NN;j+=i)
			d[j]+=i;
}

int Calc()
{
	int ans=0;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			ans+=d[i*j];
	return ans;
}

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}

bool Check(int i,int j)
{
	int ans=0;
	for(int x=1;x<=i;++x)if(i%x==0)
		for(int y=1;y<=j;++y)if(j%y==0&&gcd(x,y)==1)
			ans+=pow(x,j/y);
	cout<<ans<<","<<d[i*j];
}

int main()
{
	Prework();
	Check(6,8);
	return 0;
}
