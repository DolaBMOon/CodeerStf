def isP(x):
	for i in range(2,x):
		if x%i==0:
			return False
	return True

for i in range(2,51):
	if isP(i):
		print(i)
