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

const int P=10000000;

bool vis[P];
int pri[P],totp,phi[P];

void Prework()
{
	for(int i=2;i<P;++i)
	{
		if(!vis[i])
		{
			pri[++totp]=i;
			phi[i]=i-1;
		}
		for(int j=1,k;j<=totp&&pri[j]*i<P;++j)
		{
			vis[k=pri[j]*i]=true;
			if(i%pri[j])
				phi[k]=phi[i]*(pri[j]-1);
			else
			{
				phi[k]=phi[i]*pri[j];
				break;
			}
		}
	}
}

bool Check(int x,int y)
{
	long long res=1;
	for(int i=1;i<=phi[y];++i)
		if((res*=x)>=y)
			return false;
	return true;
}

int main()
{
	Prework();
	cout<<phi[232];
	for(int i=2;i<=9999999;++i)
		if(Check(2,i))
		{
			cout<<i<<"!!"<<endl;
		}
	return 0;
}
