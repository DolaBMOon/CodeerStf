#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define clone __clone__

const int L=2222222+10;
const int ALPHA=26;

int n;
char s[L];

int last,tot=1,nxt[L][ALPHA],fl[L],fa[L],dep[L];

void Append(int c,int di)
{
	int p=last,nw=nxt[p][c];
	if(nw&&dep[p]+1==dep[nw])
	{
		fl[last=nw]|=di;
		return;
	}

	fl[last=nw=++tot]|=di;
	dep[nw]=dep[p]+1;
	for(;p&&!nxt[p][c];nxt[p][c]=nw,p=fa[p]);

	if(p)
	{
		int q=nxt[p][c];
		if(dep[p]+1==dep[q])
		{
			fa[nw]=q;
			return;
		}
		int clone=++tot;
		memcpy(nxt[clone],nxt[q],ALPHA*sizeof(int));
		fa[clone]=fa[q];
		fl[clone]=fl[q];
		dep[clone]=dep[p]+1;
		for(;p&&nxt[p][c]==q;nxt[p][c]=clone,p=fa[p]);
		fa[q]=fa[nw]=clone;
	}
	else
		fa[nw]=1;
}

int Calc()
{
	static vector<int> Vec[L];
	for(int i=tot;i;--i)
		Vec[dep[i]].emplace_back(i);
	for(int i=tot;i;--i)
		for(int v:Vec[i])
			fl[fa[v]]|=fl[v];
	int ans=0;
	for(int i=1;i<=tot;++i)if(fl[i]==(1<<n)-1)
		ans=max(ans,dep[i]);
	return ans;
}

int main()
{
	while(~scanf("%s",s))
	{
		++n;
		last=1;
		for(char *j=s;*j;++j)
		{
			Append(*j-'a',1<<(n-1));
			Whats(tot);
		}
	}
	printf("%d",Calc());
	return 0;
}
