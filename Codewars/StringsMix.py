def mix(s1, s2) :
	ans_1 = {}
	ans_2 = {}
	for i in s1 :
		if i.islower() :
			if i in ans_1.keys() :
				ans_1[i] += 1
			else :
				ans_1[i] = 0
	for i in s2 :
		if i.islower() :
			if i in ans_2.keys() :
				ans_2[i] += 1
			else :
				ans_2[i] = 0
	ans_1 = list(map(lambda x: (x[0], x[1]), ans_1.items()))
	ans_2 = list(map(lambda x: (x[0], x[1]), ans_2.items()))

	ans_1.sort(key=lambda x: -x[1])
	ans_2.sort(key=lambda x: -x[1])
	