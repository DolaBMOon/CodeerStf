from numpy import *

MOD=998244353

n=int(input())

A=array([0]*n)
B=zeros((n,n),int64)

for i in range(1,n):
	u,v=map(int,input().split())
	u=u-1
	v=v-1
	B[u][v]=B[v][u]=1

rt,ki=map(int,input().split())

A[rt-1]=1

while ki:
	if ki&1:
		A=dot(A,B)
		for i in A:
			i%=MOD
	ki>>=1
	B=dot(B,B)
	for i in B:
		i%=MOD

for i in range(0,n):
	print(A[i],end=' ')
