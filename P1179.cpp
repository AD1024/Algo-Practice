#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int l,r;
	cin>>l>>r;
	int cnt=0;
	int n;
	for(int i=l;i<=r;i++){
		n=i;
		while(n){
			if(n%10==2) cnt+=1;
			n/=10;
		}
	}
	cout<<cnt;
	return 0;
}