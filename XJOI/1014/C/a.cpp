#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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

#define LL long long

const int MOD=1e8+7;
const int N=3333;
const int INF=0x3f3f3f3f;

const int T[4]={3,2,2,1};

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


int n,tot,a[N],id[N],l[N],r[N],fl[N];

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
	int ans=0;
	for(int i=1;i<=tot;++i)
	{
		for(int j=1,tr;j<=tot;++j)if(i!=j&&l[i]<r[j])
		{
			for(tr=l[i]+1;a[tr]!=j;++tr);
			memset(fl,0,sizeof fl);
			for(int k=1;k<l[i];++k)
				fl[a[k]]|=1;
			for(int k=l[i]+1;k<tr;++k)
				fl[a[k]]|=2;
			for(int k=tr+1;k<=n;++k)
				fl[a[k]]|=4;
			int A=1,B=1;
			for(int k=1;k<=tot;++k)if(k!=i&&k!=j)
				SMul(A,T[fl[k]&3]);
			for(int k=1;k<=tot&&B;++k)if(k!=i&&k!=j)
				if(fl[k]&4)
					SMul(B,T[fl[k]&3]-1);
				else
					SMul(B,T[fl[k]&3]);
			SU(ans,D(A,B));
		}
	}
	printf("%d",ans);
	return 0;
}
