#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

inline int gcd(int x,int y){
	while(x^=y^=x^=y%=x);return y;
}
int num = 0;
int main(){
	int N;cin>>N;
	for(int i=1;i<=N;++i){
		for(int j=1;j<i;++j){
			if(gcd(i,j) == (i^j)){
				num++;
			}
		}
	}
	printf("%d\n",num);
	return 0;
}