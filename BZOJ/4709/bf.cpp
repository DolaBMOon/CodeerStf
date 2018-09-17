#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;
int inline readint(){
	int Num;char ch;
	while((ch=getchar())<'0'||ch>'9');Num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') Num=Num*10+ch-'0';
	return Num;
}
ll f[100010];
int n,a[100010];
int cnt[100010],s[100010];
vector <int> sta[10010];
ll inline cal(int x,int y){
	return f[x-1]+(ll)a[x]*y*y;
}
int beyond(int x,int y){
	int l=1,r=n,ret=n+1;
	while(l<=r){
		int mid=l+r>>1;
		if(cal(x,mid-s[x]+1)>=cal(y,mid-s[y]+1)){
			ret=mid;
			r=mid-1;
		}
		else l=mid+1; 
	}
	return ret;
}
int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		int x=readint();
		a[i]=x;
		s[i]=++cnt[x];
		while(sta[x].size()>=2&&beyond(sta[x][sta[x].size()-2],sta[x][sta[x].size()-1])<=beyond(sta[x][sta[x].size()-1],i)) sta[x].pop_back();
		sta[x].push_back(i);
		while(sta[x].size()>=2&&beyond(sta[x][sta[x].size()-2],sta[x][sta[x].size()-1])<=s[i]) sta[x].pop_back();
		f[i]=cal(sta[x][sta[x].size()-1],s[i]-s[sta[x][sta[x].size()-1]]+1);
		//cout<<i<<":"<<f[i]<<endl;
	}
	printf("%lld\n",f[n]);
	return 0;
}
