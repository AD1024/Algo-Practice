#include <iostream>
using namespace std;

const char HEX[18]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

inline void parse(int x){
	int ret[1001];
	int cur=0;
	while(x){
		ret[++cur]=x%2;
		x/=2;
	}
	for(int i=cur;i>=1;--i){
		cout<<ret[i];
	}
}

int main(){
	int N;
	cin>>N;
	parse(N);
	return 0;
}