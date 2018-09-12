#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

const int N=1e6+200;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

char s1[N],s2[N];
int s[N],ans[N],fr[N],f[N];
int son[N][26],fail[N],len[N],tot,last;
int anc[N],dif[N];
inline int add(int p,int k) {
	//cout<<s[k]<<","<<s<<endl;
	//exit(0);
	while (s[k]!=s[k-len[p]-1]) p=fail[p];
	if (!son[p][s[k]]) {
		len[++tot]=len[p]+2;
		int t=fail[p];while (s[k]!=s[k-len[t]-1]) t=fail[t];
		fail[tot]=t=son[t][s[k]],son[p][s[k]]=tot;
		dif[tot]=len[tot]-len[t],anc[tot]=dif[tot]==dif[t]?anc[t]:t;
	}
	return son[p][s[k]];
}
int main()
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int n=strlen(s1+1),i,k;s[0]=-1;
	for (i=1;i<=n;i++) s[i*2-1]=s1[i]-'a',s[i*2]=s2[i]-'a';n<<=1;

	last=0,tot=1,len[1]=-1,fail[0]=fail[1]=1;
	memset(ans,0x3f,sizeof(ans));ans[0]=0;
	for (i=1;i<=n;i++) {
		last=add(last,i);
		for (k=last;k;k=anc[k]) {
			//cout<<i-len[anc[k]]-dif[k]<<"!"<<endl;
			//exit(0);
			f[k]=i-len[anc[k]]-dif[k];
			if (anc[k]!=fail[k]&&ans[f[fail[k]]]<ans[f[k]])
				f[k]=f[fail[k]];
			if (!(i&1)&&ans[f[k]]+1<ans[i])
				ans[i]=ans[f[k]]+1,fr[i]=f[k];
		}
		if (!(i&1)&&s[i-1]==s[i]&&ans[i-2]<ans[i])
			ans[i]=ans[i-2],fr[i]=i-2;
	}
	if (ans[n]<=n) {
		printf("%d\n",ans[n]);
		for (i=n;i;i=fr[i])
			if (fr[i]+2<i)
				printf("%d %d\n",fr[i]/2+1,i/2);
	} else puts("-1");
	return 0;
}
