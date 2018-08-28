cnt=[0]*200
print(sum(map(lambda x:x[0]-cnt[ord(x[1])],enumerate(input())))+1)
