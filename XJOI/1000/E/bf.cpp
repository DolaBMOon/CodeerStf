#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

#define LL long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=55;

int n;
Pir p[N];

bool Cmp(const Pir &a,const Pir &b)
{
	return (a.sec!=b.sec)?(a.sec<b.sec):(a.fir<b.fir);
}

int ans;

vector<Pir> v;

bool Check()
{
	int x=0;
	for(Pir a:v)
	{
		if(a.fir>x)
			x=a.fir;
		else
			++x;
		//cout<<x<<":"<<a.fir<<","<<a.sec<<endl;
		if(x>a.sec)
			return false;
	}
	return true;
}

bool vis[N];

bool Judge(int k=0)
{
	if(k==v.size())
	{
		//Oops();
		return true;
	}
	for(int i=v[k].fir;i<=v[k].sec;++i)if(!vis[i])
	{
		//cout<<k<<" "<<i<<endl;
		vis[i]=true;
		if(Judge(k+1))
		{
			vis[i]=false;
			return true;
		}
		vis[i]=false;
	}
	return false;
}

void Dfs(int k=0)
{
	if(k==n)
	{
		int a,b;
		if((a=Check())!=(b=Judge()))
		{
			//cout<<a<<" "<<b<<endl;
			//for(Pir p:v)
			//	cout<<p.fir<<" "<<p.sec<<endl;
			DivHim();
			Check();
			exit(0);
		}
		return;
	}
	v.push_back(p[k]);
	Dfs(k+1);
	v.pop_back();
	Dfs(k+1);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i].fir);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i].sec);
	sort(p,p+n,Cmp);
	Dfs();
	printf("%d\n",ans);
	return 0;
}
