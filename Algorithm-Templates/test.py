A=raw_input();
B=raw_input();
C=raw_input();
Vi=raw_input();
Vj=raw_input();
ans;
for i in range(1,A)
	for j in range(1,B)
		for k in range(1,C)
			if i>=1 and j>=1:
				ans[i][j][k]=max(ans[i][j][k],ans[i-1][j-1][k]+Vi)
			if