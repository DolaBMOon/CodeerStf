#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<set>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=1e6+10;
const int MOD=1e9+7;

int n,k;
set<int> S;
Pir p[N];

int F(int h)
{
	return (h%k+h)*(h/k+1)/2%MOD;
}

int Calc(int bl,int p,int br)
{
	return (F(br-bl-1)-F(br-p-1)-F(p-bl-1)-1+MOD)%MOD;
}

signed main()
{
	scanf("%I64d%I64d",&n,&k);
	--k;
	S.insert(0);
	S.insert(n+1);
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d",&p[i].fir);
		p[i].sec=i;
	}
	sort(p+1,p+n+1,greater<Pir>());
	int ans=0;
	for(int i=1,l,r;i<=n;++i)
	{
		set<int>::iterator it=S.insert(p[i].sec).fir;
		l=*prev(it);
		r=*next(it);
		ans=(ans+p[i].fir*Calc(l,p[i].sec,r)%MOD)%MOD;
	}
	printf("%I64d",ans);
	return 0;
}
