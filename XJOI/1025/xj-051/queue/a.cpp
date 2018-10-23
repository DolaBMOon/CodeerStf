#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=1e5+10;

int n,m,a[N],fix[N],rt;
map<int,int> mp[N];

int Merge(int x,int y)
{
	if(x&&y)
	{
		if(fix[x]<fix[y])
		{
			ch[x][1]=Merge(ch[x][1],y);
			Join(mp[x],mp[ch[x][1]]);
			Pullup(x);
			return x;
		}
		else
		{
			ch[y][0]=Merge(x,ch[y][0]);
			Pullup(y);
			return y;
		}
	}
	else
		return x^y;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		++mp[a[i]];
		fix[i]=rand();
		rt=Merge(rt,i);
	}
	return 0;
}
