#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
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

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n,m,q,tot;
vector<vector<int> > v;

int main()
{
	srand((unsigned long long)new char);
	n=5;
	m=5;
	tot=20;
	while(tot)
	{
		int k=Randint(1,tot);
		if(tot>=20)
			k=Randint(1,20);
		tot-=k;
		set<int> S;
		v.emplace_back(0);
		for(int x;k>0;--k)
		{
			//while(S.count(x=Randint(1,n)));
			x=Randint(1,n);
			if(!S.count(x))
			{
				S.insert(x);
				v.back().emplace_back(x);
			}
		}
		if(v.back().empty())
			v.pop_back();
	}
	cout<<n<<" "<<m<<" "<<v.size()<<endl;
	for(int i=1;i<=m;++i)
		cout<<Randint(1,n)<<" "<<Randint(1,n)<<endl;
	for(auto p:v)
	{
		cout<<p.size()<<endl;
		for(auto i:p)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
