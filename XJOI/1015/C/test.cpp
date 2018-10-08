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

#define int long long
#define Gcd(x,y) __gcd(x,y)

vector<int> v;

void GG()
{
	puts("Lol");
	exit(0);
}

signed main()
{
	int x;
	while(~scanf("%lld",&x))
		v.emplace_back(x);
	for(int i=0;i<(int)v.size();++i)
		for(int j=0;j<(int)v.size();++j)if(i!=j)
		{
			if(abs(i-j)==1)
			{
				if(Gcd(v[i],v[j])!=1)
				{
					cout<<i+1<<","<<j+1<<endl;
					cout<<v[i]<<","<<v[j]<<endl;
					Whats(Gcd(v[i],v[j]));
					GG();
				}
			}
			else if(Gcd(v[i],v[j])==1)
			{
				GG();
			}
		}
	return 0;
}
