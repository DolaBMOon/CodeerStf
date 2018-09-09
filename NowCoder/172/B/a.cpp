#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int INF=0x3f3f3f3f3f3f3f3f;

int jc[20];
vector<Pir> v[20];

void Dfs(int mn=1,int k=1,int cnt=0,int b=1,int res=1)
{
	v[k-1].emplace_back(res,jc[k-1]/jc[cnt]/b);
	if(k==19)
		return;
	Dfs(mn,k+1,cnt+1,b,res*mn);
	b*=jc[cnt];
	for(int i=mn+1;i<=9;++i)
		Dfs(i,k+1,1,b,res*i);
}

int Find(const vector<Pir> v,int x)
{
	int left=0,mid,right=v.size()-1,res;
	while(left<=right)
	{
		if(v[mid=(left+right)>>1].fir<=x)
			left=(res=mid)+1;
		else
			right=mid-1;
	}
	return v[res].sec;
}

void Prework()
{
	jc[0]=1;
	for(int i=1;i<=18;++i)
		jc[i]=jc[i-1]*i;
	Dfs();
	v[0].emplace_back(0,1);
	for(int i=1,j=1,k=1;i<=18;++i)
	{
		v[i].emplace_back(0,(k*=10)-(j*=9));
		sort(v[i].begin(),v[i].end());
		for(int j=1;j<(int)v[i].size();++j)
			v[i][j].sec+=v[i][j-1].sec;
	}
}

int L,R,L1,R1;
int lst[20],ed;

int Song(int R1)
{
	int res=0;
	for(int i=ed;i>0;--i)
	{
		if(lst[i]>0)
		{
			if(i!=ed)
				res+=v[i-1].back().sec;
			else
				res+=Find(v[i-1],R1);
			for(int j=1;j<lst[i]&&(i>1||R1>=j);++j)
				res+=Find(v[i-1],R1/j);
			if(lst[i]>R1)
				return res;
			R1/=lst[i];
		}
		else
		{
			int x=0;
			for(int j=i-1;j>0;--j)
				x=x*10+lst[j];
			return res+x;
		}
	}
	return res+(R>0);
}

void Test()
{
	ed=4;
	lst[1]=0;
	lst[2]=0;
	lst[3]=0;
	lst[4]=1;
	Whats(Song(57));
}

int S2(int R,int R1)
{
	if(R<0||R1<0)
		return 0;
	if(!R)
		return 1;
	for(ed=0;R;lst[++ed]=R%10,R/=10);
	return Song(R1);
}

int S(int R)
{
	return S2(R,R1)-S2(R,L1-1);
}

signed main()
{
	Prework();
	Test();
	scanf("%lld%lld%lld%lld",&L,&R,&L1,&R1);
	printf("%lld",S(R)-S(L-1));
	return 0;
}
