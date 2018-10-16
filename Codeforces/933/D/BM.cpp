#include<bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
const int NB=1000;

int Mul(int a,int b)
{
	unsigned long long x=(long long)a*b;
	unsigned xh=(unsigned)(x>>32),xl=(unsigned)x,d,m;
	asm
		(
		 "divl %4;\n\t"
		 :"=a"(d),"=d"(m)
		 :"d"(xh),"a"(xl),"r"(MOD)
		);
	return m;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

void Extend(vector<int> &v,int x)
{
	if((int)v.size()<x)
		v.resize(x);
}

vector<int> BM(vector<int> v)
{
	static vector<int> f,g,t;
	f.clear();
	g.clear();
	f.reserve(NB);
	g.reserve(NB);
	t.reserve(NB);
	int fp=0,fw=0;

	for(int i=0;i<(int)v.size();++i)
	{
		int x=v[i];
		if((int)f.size()<=i)
			for(int j=0;j<(int)f.size();++j)
				SD(x,Mul(f[j],v[i-j-1]));
		if(x)
		{
			if(f.empty())
				f.resize(i);
			else
			{
				t=f;
				Extend(f,i-fp+g.size());
				int y=Mul(x,Qpow(fw));
				SU(f[i-fp-1],y);
				for(int j=0;j<(int)g.size();++j)
					SD(f[i-fp+j],Mul(y,g[j]));
				g=t;
			}
			fp=i;
			fw=x;
		}
	}
	return f;
}

int main()
{
	cout<<(BM({0,5,28,78,180,387,720,1200,1880,2821,4132,5850,8012,10759,14136,18188,23024,28829,35732,43794,53236,64127,76536,90532,106184,123861,143852,166246,191132,218831,249440,283056,319904,360085,403972,451674,503444,559691,620536,686100,756824,833165,915260,1003246,1097260,1197799,1305008,1419032,1540016,1668301,1804636,1949182,2102516,2265231,2437504,2619512,2811432,3013441,3226180,3449834,3684588,3931115,4189608,4460260,4743520,5040625,5351788,5677222,6017684,6373395,6744576,7131448,7534520,7954601,8392516,8848506,9322812,9815675,10327336,10858036,11408656,11979769,12572284,13186462,13822564,14482211,15165680,15873248,16605192,17362501,18146180,18956522,19793820,20658367,21550456,22470380,23418432,24395681,25402820,26440154,27509188}).size());
	return 0;
}
