#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int F=2e7+10;
namespace Seg{
    const int xb=N-5;
    ll f[N<<1];
    inline void add(int x,int y){
        for (int i=xb+x;i;i>>=1) f[i]+=y;
    }
    inline void add(int x,int y,int z){
        add(x,z);add(y+1,-z);
    }
    inline ll ask(int x){
        ll ans=0;
        for (int l=xb,r=xb+x+1;l^r^1;l>>=1,r>>=1){
            if (~l&1) ans+=f[l^1];
            if (r&1) ans+=f[r^1];
        }
        return ans;
    }
}
int n,m;
int phi[F],pnum,pri[F/10];
bool bo[F];
inline int qmi(ll x,int y,int p){
    int ans=1;
    bool flag=0;
    if (x>=p) flag=1,x%=p;
    while (y){
        if (1ll*ans*x>p||(y>1&&1ll*x*x>=p)) flag=1;
        if (y&1) ans=1ll*ans*x%p;
        x=x*x%p;
        y>>=1;
    }
    return ans+flag*p;
}
inline int get_val(int pos,int r,int p){
    ll val=Seg::ask(pos);
    if (val%p==0||pos==r) return val%p+(val>=p)*p;
    return qmi(val,get_val(pos+1,r,phi[p]),p);
}
main(){
    // freopen("sample6.in","r",stdin);freopen("my.out","w",stdout);
    phi[1]=1;
    for (int i=2;i<F;++i){
        if (!bo[i]) phi[i]=i-1,pri[++pnum]=i;
        for (int j=1;j<=pnum&&i*pri[j]<F;++j){
            bo[i*pri[j]]=1;
            if (i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
    scanf("%d%d",&n,&m);
    int op,l,r,x;
    for (int i=1;i<=n;++i) scanf("%d",&x),Seg::add(i,i,x);
    while (m--){
        scanf("%d%d%d%d",&op,&l,&r,&x);
        if (op==1) Seg::add(l,r,x); else printf("%d\n",get_val(l,r,x)%x);
    }
    return 0;
}
