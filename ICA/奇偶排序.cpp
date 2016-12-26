#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
using namespace std;

inline void to(int x){
}

int main(){
	int N;cin>>N;
	while(cin>>N){
		bitset<256> bi(N);
		cout<<bi.count()<<endl;
	}
	return 0;
}