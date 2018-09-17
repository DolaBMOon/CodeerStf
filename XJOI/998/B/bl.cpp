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

int n;
vector<int> v;

int main()
{
	scanf("%d",&n);
	for(int i=1,op,x;i<=n;++i)
	{
		scanf("%d%d",&op,&x);
		if(op&1)
			v.push_back(x);
		else
		{
			int rex=0,rea=0,reo=0;
			for(int j:v)
			{
				GetMax(rex,j^x);
				GetMax(rea,j&x);
				GetMax(reo,j|x);
			}
			printf("%d %d %d\n",rex,rea,reo);
		}
	}
	return 0;
}
