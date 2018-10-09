#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<map>

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

#define H unsigned long long

const int L=23;
const int N=10;
const int K=10;
const int INF=0x3f3f3f3f;

const H B=233;

string s,t,a[N],b[N];
int n;

map<H,int> mp;

H Hash(string s)
{
	H x=0;
	for(char c:s)
		x=x*B+c;
	return x;
}

void Dfs(string s,int k)
{
	H x=Hash(s);
	if(mp.count(x))
		GetMin(mp[x],k);
	else
		mp[x]=k;
	if(k>5)
		return;
	for(int i=1;i<=n;++i)
		for(int j=0;j+a[i].size()<=s.size();++j)
			if(s.substr(j,a[i].size())==a[i])
			{
				string t=s;
				t.replace(j,a[i].size(),b[i]);
				Dfs(t,k+1);
			}
}

int ans=INF;

void Dfs2(string s,int k)
{
	H x=Hash(s);
	if(mp.count(x))
		GetMin(ans,k+mp[x]);
	if(k>5)
		return;
	for(int i=1;i<=n;++i)
		for(int j=0;j+b[i].size()<=s.size();++j)
			if(s.substr(j,b[i].size())==b[i])
			{
				string t=s;
				t.replace(j,b[i].size(),a[i]);
				Dfs2(t,k+1);
			}
}

int main()
{
	cin>>s>>t;
	while(cin>>a[n+1]>>b[n+1])
		++n;
	Dfs(s,0);
	Dfs2(t,0);
	if(ans!=INF)
		printf("%d",ans);
	else
		puts("NO ANSWER!");
	return 0;
}
