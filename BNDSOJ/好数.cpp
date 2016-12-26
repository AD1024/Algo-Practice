#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*
0
1
10
11
100
101
110
111
1000
1001
1010


1011
1100
1101
1110
1111
*/



int main(){
	int l,r;cin>>l>>r;
	int ans=0;
	for(register int i=l;i<=r;++i){
		if(!(i&(i-1))){
			if(i<4) continue;
			//cout<<i<<' ';
			ans++;
		}else{
			if(i%5)
		}
	}
	cout<<ans;
	return 0;
}