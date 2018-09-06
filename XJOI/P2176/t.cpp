#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
	 -<Unlimited Blade Works>-
 */

const int L=23333;
const int ALPHA=26;

int nxt[L][ALPHA],len[L],link[L],last,sz=1;

void append(int c)
{
	int p,cur;
	if((cur=nxt[p=last][c])&&len[p]+1==len[cur])
	{
		last=cur;
		return;
	}
	last=cur=++sz;
	len[cur]=len[p]+1;
	while(p&&!nxt[p][c])
	{
		nxt[p][c]=cur;
		p=link[p];
	}
	if(p)
	{
		int q;
		if(len[q=nxt[p][c]]==len[p]+1)
			link[cur]=q;
		else
		{
			int clone=++sz;
			link[clone]=link[q];
			len[clone]=len[p]+1;
			memcpy(nxt[clone],nxt[q],sizeof(int)*26);
			while(p&&nxt[p][c]==q)
			{
				nxt[p][c]=clone;
				p=link[p];
			}
			link[q]=link[cur]=clone;
		}
	}
	else link[cur]=1;
}

int n;
char s[L];

int main()
{
	while(~scanf("%s",s))
	{
		++n;
		last=1;
		for(char *j=s;*j;++j)
		{
			append(*j-'a');
			Whats(sz);
		}
	}
	return 0;
}
