#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int list[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};

int main(){
	int N;
	while(cin>>N){
		bool found=false;
		if(N<0) break;
		for(int i=9;i>=0;i--){
			if(N>=list[i]){
				N-=list[i];
			}
			if(N<=0){
				found=true;
				break;
			}
		}
		if(found){
			N==0?puts("YES"):puts("NO");
		}else puts("NO");
	}
	return 0;
}