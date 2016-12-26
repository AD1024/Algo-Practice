#include <iostream>
using namespace std;

inline int sum(int x){
	int ret=0;
	while(x){
		ret+=x%10;
		x/=10;
	}
	return ret;
}

inline bool check(int x){
	int a=x%1000;
	int b=x/1000;
	return sum(a)==sum(b);
}

inline void work(){
	int N;
	cin>>N;
	if(check(N) || check(N+1) || check(N-1)){
		puts("Yes");
	}else{
		puts("No");
	}
}

int main(){
	work();
	return 0;
}