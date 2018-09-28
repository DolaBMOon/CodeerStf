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

const int N=1e5+10;
const int INF=0x3f3f3f3f;

int n,a[N];

int Calc(int k)
{
	static int mn[N],l0,r0,mx[N],l1,r1,res;
	l0=l1=0;
	r0=r1=-1;
	res=0x3f3f3f3f;
	for(int i=1;i<=n;++i)
	{
		for(;r0>=l0&&a[i]<mn[r0];--r0);
		for(;r1>=l1&&a[i]>mx[r1];--r1);
		mn[++r0]=a[i];
		mx[++r1]=a[i];
		if(i>=k)
		{
			if(i>k)
			{
				l0+=(mn[l0]==a[i-k]);
				l1+=(mx[l1]==a[i-k]);
			}
			GetMin(res,mx[l1]-mn[l0]);
		}
	}
	return res;
}

int ans[N];

void Song(int l,int r)
{
	if(ans[l]==-1)
		ans[l]=Calc(l);
	if(ans[r]==-1)
		ans[r]=Calc(r);
	if(ans[r]-ans[l]<=0.05*ans[r])
	{
		for(int i=l;i<=r;++i)
			ans[i]=ans[l];
		return;
	}
	int md=(l+r)>>1;
	Song(l,md);
	Song(md+1,r);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	memset(ans,-1,sizeof ans);
	Song(2,n);
	for(int i=2;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}
