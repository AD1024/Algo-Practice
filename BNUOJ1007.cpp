#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;


int main(){
    int N;
    while(cin>>N){
    	if(N==0) break;
    	int M=1;
    	int s=0;
    	while(1){
    		s=0;
    		for(int i=2;i<=N-1;i++){
    			s=(s+M)%i;
    		}
    		if(s==0) break;
    		M++;
    	}
    	cout<<M<<endl;
	}
    return 0;
}