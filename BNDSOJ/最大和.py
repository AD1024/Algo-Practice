a = [int(x) for x in input().split()]
a.append(a[0])
a.append(a[1])
a.append(a[2])
ans = -10000
pos = 0
s = 0
for i in range(4, len(a)+1) :
	s = sum(a[i-4:i])
	if s > ans :
		ans = s
		pos = i-3
print(ans, '\n', pos, sep='')
