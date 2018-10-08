#include<bits/stdc++.h>

using namespace std;

int n,m;

void dfs(int k){
	if (k>n+1){
		n=k-1;
		printf("%d\n",n);
		//		for (int x=0;x<m;x++,puts(""))
		//			for (int i=1;i<=n;i++)
		//				printf("%d ",a[i]>>x&1);
		for (int i=1;i<=n;i++){
			printf("%9d,",a[i]);
			if (i%10==0)
				puts("");
		}
		puts("");
	}
	for (int i=1;i<(1<<m);i++){
		a[k]=v[i];
		if (a[k]&a[k-1])
			continue;
		int flag=1;
		for (int j=1;j<k-1&&flag;j++)
			if (!(a[k]&a[j]))
				flag=0;
		if (!flag)
			continue;
		dfs(k+1);
	}
}

int main(){
	n=0;
	m=read();
	for (int i=1;i<(1<<m);i++)
		v[i]=i;
	random_shuffle(v+1,v+(1<<m));
	dfs(1);
	return 0;
}
