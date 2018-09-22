%:pragma GCC target("avx")
%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("-fgcse")
%:pragma GCC optimize("-fgcse-lm")
%:pragma GCC optimize("-fipa-sra")
%:pragma GCC optimize("-ftree-pre")
%:pragma GCC optimize("-ftree-vrp")
%:pragma GCC optimize("-fpeephole2")
%:pragma GCC optimize("-ffast-math")
%:pragma GCC optimize("-fsched-spec")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("-falign-jumps")
%:pragma GCC optimize("-falign-loops")
%:pragma GCC optimize("-falign-labels")
%:pragma GCC optimize("-fdevirtualize")
%:pragma GCC optimize("-fcaller-saves")
%:pragma GCC optimize("-fcrossjumping")
%:pragma GCC optimize("-fthread-jumps")
%:pragma GCC optimize("-funroll-loops")
%:pragma GCC optimize("-fwhole-program")
%:pragma GCC optimize("-freorder-blocks")
%:pragma GCC optimize("-fschedule-insns")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("-ftree-tail-merge")
%:pragma GCC optimize("-fschedule-insns2")
%:pragma GCC optimize("-fstrict-aliasing")
%:pragma GCC optimize("-fstrict-overflow")
%:pragma GCC optimize("-falign-functions")
%:pragma GCC optimize("-fcse-skip-blocks")
%:pragma GCC optimize("-fcse-follow-jumps")
%:pragma GCC optimize("-fsched-interblock")
%:pragma GCC optimize("-fpartial-inlining")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("-freorder-functions")
%:pragma GCC optimize("-findirect-inlining")
%:pragma GCC optimize("-frerun-cse-after-loop")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("-finline-small-functions")
%:pragma GCC optimize("-ftree-switch-conversion")
%:pragma GCC optimize("-foptimize-sibling-calls")
%:pragma GCC optimize("-fexpensive-optimizations")
%:pragma GCC optimize("-funsafe-loop-optimizations")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int MOD=998244353;

unsigned int a, b, c;

int main()
{
	cin>>a>>b>>c;
	unsigned LL sm=0;
	unsigned LL x;
	for(register int i=250000000;i--;)
	{
		a^=b^c>>1;
		b^=a<<5^c>>3;
		c^=a>>2^b<<4;
		x=a>>2;
		a^=b^c>>1;
		b^=a<<5^c>>3;
		c^=a>>2^b<<4;
		x*=a>>2;
		sm+=x;
		a^=b^c>>1;
		b^=a<<5^c>>3;
		c^=a>>2^b<<4;
		x=a>>2;
		a^=b^c>>1;
		b^=a<<5^c>>3;
		c^=a>>2^b<<4;
		x*=a>>2;
		sm+=x;
		a^=b^c>>1;
		b^=a<<5^c>>3;
		c^=a>>2^b<<4;
		x=a>>2;
		a^=b^c>>1;
		b^=a<<5^c>>3;
		c^=a>>2^b<<4;
		x*=a>>2;
		sm+=x;
		a^=b^c>>1;
		b^=a<<5^c>>3;
		c^=a>>2^b<<4;
		x=a>>2;
		a^=b^c>>1;
		b^=a<<5^c>>3;
		c^=a>>2^b<<4;
		x*=a>>2;
		sm+=x;
	}
	cout<<(int)(sm%MOD);
	return 0;
}

