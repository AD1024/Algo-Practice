x = int(input())
y = int(input())

ans = 1
while 1 :
	if ((x*ans) // 60)%24 == ((y*ans) // 60)%24 and \
		(x*ans)%60 == (y*ans)%60 :
		print(ans)
		break
	ans += 1