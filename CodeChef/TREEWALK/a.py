import numpy as np

MOD=998244353

n=int(input())

A=np.zeros((n,n),dtype=np.int64)

for i in range(n-1):
	u,v=map(int,input().split())
	u=u-1
	v=v-1
	A[u][v]=1
	A[v][u]=1

print(A)

print(A*A*A*A)

 
# rt,ki=map(int,input().split())
# 
# for i in range(0,n):
# 	print(A[rt][i],end=' ')
