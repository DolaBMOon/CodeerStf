#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<list>

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

#define Lit list<int>::iterator

const int N=2e5;
const int B=1230;

int n,m;
list<int> lst;
Lit fir[N];
int cnt[N/B][N];

Lit Find(int p)
{
	Lit i=fir[p/B];
	for(p%=B;p--;++i);
	return i;
}

int main()
{
	scanf("%d",&n);
	for(int i=0,x;i<n;++i)
	{
		scanf("%d",&x);
		lst.push_back(--x);
		if(i%B==0)
			fir[i/B]=--lst.end();
		++cnt[i/B][x];
	}
	//lst.push_back(-1);
	scanf("%d",&m);
	for(int i=1,op,l,r,k,ans=0;i<=m;++i)
	{
		scanf("%d%d%d",&op,&l,&r);
		--l;
		--r;
		l=(l+ans)%n;
		r=(r+ans)%n;
		if(l>r)
			swap(l,r);
		Lit tl=Find(l);
		Lit tr=Find(r);
		if(op&1)
		{
			if(l==r)
				continue;
			lst.insert(tl,*tr);
			if(r%B==0)
				++fir[r/B];
			if(l%B==0)
				--fir[l/B];
			++cnt[l/B][*tr];
			--cnt[r/B][*tr];
			lst.erase(tr);
			for(int i=r/B;i*B>l;--i)
			{
				--fir[i];
				++cnt[i][*fir[i]];
				--cnt[i-1][*fir[i]];
			}
		}
		else
		{
			scanf("%d",&k);
			--k;
			k=(k+ans)%n;
			ans=0;
			int x=l/B,y=r/B;
			if(x==y)
			{
				for(Lit it=tl;it!=tr;++it)
					ans+=(*it==k);
			}
			else
			{
				for(Lit it=tl;it!=fir[x+1];++it)
					ans+=(*it==k);
				for(int i=x+1;i!=y;++i)
					ans+=cnt[i][k];
				for(Lit it=fir[y];it!=tr;++it)
					ans+=(*it==k);
			}
			ans+=(*tr==k);
			printf("%d\n",ans);
		}
	}
	return 0;
}
