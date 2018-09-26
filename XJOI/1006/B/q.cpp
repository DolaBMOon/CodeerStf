#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

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

int n,ans;
vector<int> v;

bool Check()
{
	set<int> S;
	for(int i=0;i<(int)v.size();++i)
		S.insert(v[i]);
	for(int i=0;i<(int)v.size();++i)
		for(int j=i;j<(int)v.size();++j)
			if(!S.count(v[i]^v[j]))
				return false;
	return true;
}

int Ji()
{
	vector<int> p;
	for(int i=0;i<(int)v.size();++i)
	{
		int x=v[i];
		for(int j=0;j<(int)p.size();++j)
			GetMin(x,x^p[j]);
		if(x)
			p.push_back(x);
	}
	return p.size();
}

void Dfs(int k)
{
	if(k>n)
	{
		ans+=Check();
		return;
	}
	Dfs(k+1);
	v.push_back(k);
	Dfs(k+1);
	v.pop_back();
}

int main()
{
	cin>>n;
	v.push_back(0);
	Dfs(1);
	printf("%d",ans);
	return 0;
}
