#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ri int
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define For(i,a,b) for(ri i=(a);i<=(b);++i)
#define DFor(i,a,b) for(ri i=(a);i>=(b);--i)
#define ctz __builtin_ctzll//__builtin_ctz函数作用:判断n的二进制末尾后面0的个数
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
char ss[1<<20],*A=ss,*B=ss;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;}
template<class T>inline void read(T&x){
	char ch=gc();
	for(;!isdigit(ch);ch=gc());
	for(x=0;isdigit(ch);x=(x<<1)+(x<<3)+(ch^48),ch=gc());
}
char sr[1<<20],z[130];int C=-1,Z;
template<class T>inline void wer(T x){
	//ri y=0;//if(x<0)y=1,x=-x;
	while(z[++Z]=(x%10)^48,x/=10);//if(y)z[++Z]='-';
	while(sr[++C]=z[Z],--Z);
}
typedef long long ll;
const int base[5]={2,3,7,61,24251};
ll pr;
inline ll mul(ll a,ll b,ll m){
	ll d=((long double)a/m*b+1e-8);
	ll r=a*b-d*m;
	return r<0?r+m:r;
}
inline ll gcd(ll a,ll b){//听说二进制算法特快
	if(!a)return b;
	if(!b)return a;
	int t=ctz(a|b);
	a>>=ctz(a);
	do{
		b>>=ctz(b);
		if(a>b){ll t=b;b=a,a=t;}
		b-=a;
	}while(b);
	return a<<t;
}
inline ll ksm(ll x,ll k,ll mo){
	ll ans=1;
	for(;k;k>>=1,x=mul(x,x,mo))
		if(k&1)ans=mul(ans,x,mo);
	return ans;
}
inline bool Miller(ll x){
	if(x==46856248255981ll||x<2)return false;//强伪素数
	if(x==2||x==3||x==7||x==61||x==24251)return true;
	if(!(x&1)||!(x%3)||!(x%61)||!(x%24251))return false;
	ll ba=x-1;
	int ti=0;
	while(!(ba&1))ba>>=1,++ti;
	For(i,0,4){
		if(base[i]>x)break;
		ll r=ksm(base[i],ba,x),l=r;
		for(ri j=1;j<=ti;++j){
			r=mul(r,r,x);
			if(r==1&&l!=1&&l!=x-1)return false;
			l=r;
		}if(r!=1)return false;
	}return true;
}
inline ll Abs(ll a){return a<0?-a:a;}
inline ll g(ll x,ll n,ll a){
	ll t=mul(x,x,n)+a;
	return t<n?t:t-n;
}
const int M=(1<<7)-1;
inline ll Rho(ll n){
	if(!(n%2))return 2;
	if(!(n%3))return 3;
	ll x=0,y=x,t=1,q=1,c=(rand()%(n-1))+1;
	for(ri k=2;;k<<=1,y=x,q=1){//相当于重新迭代
		for(ri i=1;i<=k;++i){
			x=g(x,n,c);
			q=mul(q,Abs(x-y),n);
			if(!(i&M)){//应该巧妙利用了生日悖论
				t=gcd(q,n);
				if(t>1)break;
			}
		}
		if(t>1||(t=gcd(q,n))>1)break;
	}
	//	if(t==n){//判的比较松
	//        t=1;
	//        while(t==1)t=gcd(Abs(x=g(x,n,c)-y),n);
	//    }
	return t;
}
void find(ll x){
	if(x<=pr||x==1)return;
	if(Miller(x)){pr=Max(pr,x);return;}
	ll t=x;
	while(t==x)t=Rho(x);
	while(!(x%t))x/=t;
	find(t),find(x);
}
int main(){
	//	freopen("a.in","r",stdin);
	//	freopen("a.out","w",stdout);
	srand(156850236239ll);
	int T;
	ll n;
	read(T);
	while(T--){
		read(n);
		pr=0,find(n);
		if(pr==n)sr[++C]='P',sr[++C]='r',sr[++C]='i',sr[++C]='m',sr[++C]='e';
		else wer(pr);
		sr[++C]='\n';
	}fwrite(sr,1,C+1,stdout);
	return 0;
}
