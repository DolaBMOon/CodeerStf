#include<cstdio>
#include<cstring>
const int N=1e5+10,mod=1e9+7;
int hd[N],tot,n,sz[N],dep[N],fa[N][20],a[N],l,r,b[N],ans;
struct Edge{
    int v,nx;
}e[N<<1];
int C2(int x){return 1ll*x*(x-1)/2%mod;}//返回C(x,2)
void add(int u,int v)
{
    e[tot].v=v;
    e[tot].nx=hd[u];
    hd[u]=tot++;
}
void dfs(int u)
{
    sz[u]=1;
    for(int i=1;(1<<i)<=dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=hd[u];~i;i=e[i].nx)
    {
        int v=e[i].v;
        if(v==fa[u][0])continue;
        fa[v][0]=u;dep[v]=dep[u]+1;dfs(v);
        sz[u]+=sz[v];a[u]=(a[u]+C2(sz[v]))%mod;
    }
    a[u]=(C2(sz[u])-a[u]+mod)%mod;//在u的子树中取2个不共路径的端点
}
void Dfs(int u)
{
    for(int i=hd[u];~i;i=e[i].nx)
    {
        int v=e[i].v;
        if(fa[u][0]==v)continue;
        b[v]=(0ll+b[u]+a[u]-C2(sz[u])+mod-C2(n-sz[u])+mod+C2(sz[v])+C2(n-sz[v]))%mod;
        //在v的子树外取两个不共路径的端点
        Dfs(v);
    }
}
int up(int u,int d)
{
    for(int i=19;i>=0;i--)if(d&(1<<i))u=fa[u][i];
    return u;
}
int main()
{
    //freopen("in.txt","r",stdin);
    memset(hd,-1,sizeof(hd));
    scanf("%d%d%d",&n,&l,&r);
    int u,v;
    for(int i=1;i<n;i++)
        scanf("%d%d",&u,&v),add(u,v),add(v,u);
    dfs(1);Dfs(1);
    for(int i=1;i<=n;i++)
    {
        int v=up(i,l-1);int u=up(i,r);//从i往上跳
        ans=(0ll+ans+(2ll*a[i]+1)*(b[v]-b[u]+mod)+1ll*a[i]*(dep[v]-dep[u]))%mod;
    }
    printf("%d\n",ans);
    return 0;
}
