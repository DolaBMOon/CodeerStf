from numpy import *

MOD=998244353

n=int(input())

A=zeros((n,n),int)
B=zeros((n,n),int)

for i in range(1,n):
	u,v=map(int,input().split())
	B[u][v]=B[v][u]=1

rt,ki=map(int,input().split())

while(ki):
	if(ki&1)
		A=dot(A,B)
	ki>>=1
	B=dot(B,B)

print(A)
