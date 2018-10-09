from numpy import *

MOD=998244353

n=int(input())

A=zeros((n,n),int64)

for i in range(1,n):
	u,v=map(int,input().split())
	u=u-1
	v=v-1
	A[u][v]=A[v][u]=1

rt,ki=map(int,input().split())

B=array([0]*n)
B[rt-1]=1

B=B*A**ki

for i in range(0,n):
	print(B[i],end=' ')
