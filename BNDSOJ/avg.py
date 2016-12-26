a = []
ans=0.0
for i in range(1,20):
	a[i]=float(raw_input())
	ans+=a[i]
avg =float(ans/20.0)
ret=0
for i in range(1,20):
	if avg>a[i]:
		ret=ret+1
print(ret)