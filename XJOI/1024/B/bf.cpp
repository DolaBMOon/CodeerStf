#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
 
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
 
const int N=400000+10;
 
int n,m,a[N];
 
namespace Brute
{
 
    int b[N],hs[N],ed;
 
    int C[N];
 
    void Update(int x,int y)
    {
        for(;x<=ed;x+=x&(-x))
            GetMax(C[x],y);
    }
 
    int Query(int x)
    {
        int res=0;
        for(;x;x-=x&(-x))
            GetMax(res,C[x]);
        return res;
    }
 
    int Solve()
    {
        ed=0;
        for(int i=1;i<=n;++i)
            hs[++ed]=a[i];
        sort(hs+1,hs+ed+1);
        ed=unique(hs+1,hs+ed+1)-hs-1;
        for(int i=1;i<=n;++i)
            b[i]=lower_bound(hs+1,hs+ed+1,a[i])-hs;
        for(int i=1;i<=ed;++i)
            C[i]=0;
        int ans=0;
        for(int i=1,t;i<=n;++i)
        {
            GetMax(ans,t=Query(b[i]-1)+1);
            Update(b[i],t);
        }
        return ans;
    }
 
    void Force()
    {
        for(int i=1,x,y;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            swap(a[x],y);
            printf("%d\n",Solve());
            swap(a[x],y);
        }
    }
 
}
 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    if(n<=2333&&m<=2333)
    {
        Brute::Force();
        return 0;
    }
    if(a[n]==n)
    {
        for(int i=1,x,y;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            if(y==a[x]||(x==1&&y<=a[x]))
                printf("%d\n",n);
            else
                printf("%d\n",n-1);
        }
    }
    else
    {
        for(int i=1,x,y;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            if((x>1&&a[x-1]<y)||(x<n&&y<a[x+1]))
                printf("2\n");
            else
                printf("1\n");
        }
    }
    return 0;
}
