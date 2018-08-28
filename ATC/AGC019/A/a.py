q,h,s,d=map(int,input().split())

h=min(h,q+q)
s=min(s,h+h)
d=min(d,s+s)

n=int(input())

print(n//2*d+n%2*s)
