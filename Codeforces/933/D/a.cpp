#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<cmath>

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

#define int long long

const int MOD=1e9+7;

int Mul(int x,int y)
{
	return x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+=MOD):x;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

int Div(int x,int y)
{
	return x*Qpow(y)%MOD;
}

int m,mm,ans,l;

int Calc(int a)
{
	a%=MOD;
	return D(Div(Mul(Mul(U(mm,1),U(a,mm)),U(D(mm,a),1)),2),D(Div(Mul(Mul(mm,U(mm,1)),U(U(mm,mm),1)),6),Div(Mul(Mul(D(a,1),a),D(U(a,a),1)),6)));
}

const int G=8;

int y[233],ny[233];

int Work(int k)
{
	int ans=0;
	for(int a=0,res;a<G;++a)
	{
		res=y[a];
		for(int b=0;b<G;++b)
			if(a<b)
			{
				res=Mul(res,D(b,k));
				res=Mul(res,ny[b-a]);
			}
			else if(a>b)
			{
				res=Mul(res,D(k,b));
				res=Mul(res,ny[a-b]);
			}
		ans=U(ans,res);
	}
	return ans;
}

void Solve()
{
	int ans=0;
	for(int i=1;i*i<=m;++i)
	{
		int k=sqrt(m-i*i);
		if(k<=10)
		{
			for(int j=0;i*i+j*j<=m;++j)
				ans=U(ans,Calc(i*i+j*j));
		}
		else
		{
			y[0]=Calc(i*i);
			for(int j=1;j<G;++j)
				y[j]=U(y[j-1],Calc(i*i+j*j));
			ans=U(ans,Work(k));
		}
	}
	cout<<U(Mul(ans,4),Calc(1))<<endl;
}

signed main()
{
	for(int i=1;i<G;++i)
		ny[i]=Qpow(i);
	cin>>m;
	mm=m%MOD;
	if(m<10000)
	{
		int ans=0;
		for(int i=1;i*i<=m;++i)
			for(int j=0;i*i+j*j<=m;++j)
				ans=U(ans,Calc(i*i+j*j));
		cout<<U(Mul(ans,4),Calc(1))<<endl;
	}
	else
		Solve();
	return 0;
}
