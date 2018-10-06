#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<bitset>

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

#define LL long long

const int MOD=1e8+7;
const int N=3333;
const int INF=0x3f3f3f3f;
const int T[4]={2,1,1,0};

int pw[4][N];

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

void SMul(int &x,int y)
{
	x=(LL)x*y%MOD;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,SMul(x,x))if(y&1)
		SMul(res,x);
	return res;
}

int n,tot,a[N],id[N],l[N],r[N],fl[N],cnt[8],lo[N],ro[N],_fl[N],_cnt[8];
bool vis[N];

int Calc()
{
	int A=1,B=1;
	for(int i=0;i<8;++i)
	{
		SMul(A,pw[T[i&3]+1][cnt[i]]);
		SMul(B,pw[T[i&3]+!(i&4)][cnt[i]]);
	}
	return D(A,B);
}

void Song(int x,int y)
{
	if(fl[x]==y)
		return;
	--cnt[fl[x]];
	++cnt[fl[x]=y];
}

int main()
{
	scanf("%d",&n);
	memset(l,0x3f,sizeof l);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(!id[a[i]])
			id[a[i]]=++tot;
		a[i]=id[a[i]];
		GetMin(l[a[i]],i);
		GetMax(r[a[i]],i);
	}
	for(int i=1;i<=tot;++i)
	{
		lo[l[i]]=i;
		ro[r[i]]=i;
	}
	pw[0][0]=pw[1][0]=pw[2][0]=pw[3][0]=1;
	for(int i=1;i<=tot;++i)
		for(int j=0;j<4;++j)
			pw[j][i]=Mul(pw[j][i-1],j);
	cnt[0]=tot;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		Song(a[i],fl[i]|1);
		if(!lo[i])
			continue;
		memcpy(_fl,fl,sizeof fl);
		memcpy(_cnt,cnt,sizeof cnt);
		memset(vis,0,sizeof vis);
		vis[a[i]]=true;
		for(int j=i+1;j<=n;++j)
			Song(a[j],fl[a[j]]|4);
		for(int j=i+1;j<=n;++j)
		{
			if(!vis[a[j]])
			{
				vis[a[j]]=true;
				--cnt[fl[a[i]]];
				--cnt[fl[a[j]]];
				SU(ans,Calc());
				++cnt[fl[a[i]]];
				++cnt[fl[a[j]]];
			}
			if(ro[j])
				Song(a[j],fl[a[j]]&3);
			Song(a[j],fl[a[j]]|2);
		}
		memcpy(fl,_fl,sizeof fl);
		memcpy(cnt,_cnt,sizeof cnt);
	}
	printf("%d",ans);
	return 0;
}
