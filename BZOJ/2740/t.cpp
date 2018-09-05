#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define next __next__
const int maxn=10000011;
char s[maxn];int n;
void init(){scanf("%s",s+1);n=strlen(s+1);}
int xx(char *s,int n){
    int i,j,k;
    for (i=1,j=2,k=0;i<=n && j<=n && k<n;++k){
        if (s[i+k>n?i+k-n:i+k]>s[j+k>n?j+k-n:j+k]) i+=k+1,i+=(i==j),k=-1;
        else if (s[i+k>n?i+k-n:i+k]<s[j+k>n?j+k-n:j+k]) j+=k+1,j+=(i==j),k=-1;
    }
    return min(i,j);
}
int next[maxn];
void kmp(char *s,int n){
    next[1]=0;
    for (int i=2,j=0;i<=n;++i){
        while (j && s[j+1]!=s[i]) j=next[j];
        if (s[i]==s[j+1]) next[i]=++j;else next[i]=j;
    }
}
void work(){
    reverse(s+1,s+n+1);
    int t=xx(s,n),x=n-t+1;kmp(s+(t-1),x);
    while (next[x]) x=next[x];
    int m=n-x+1,k,len=x;bool ok=1;
    for (k=m-len;k>0 && ok;k-=len)
        for (int i=0;i<len;++i) if (s[k+i]!=s[m+i]) ok=0;
    m=k+len;if (!ok) m+=len;
    printf("%d %d\n",n-m+1,n-xx(s,m-1)+1);
}
int main(){
    int T=1;scanf("%d",&T);
    while (T--) init(),work();
    return 0;
}
