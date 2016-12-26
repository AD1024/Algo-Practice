#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int x,n;
	cin>>n;
	x=n*n;
	int cur=1;
	int cnt=0;
	int tmp;
	while(x>0){
		cin>>tmp;
		cur=!cur;
		for(int i=1;i<=tmp;++i){
			cout<<cur;
			cnt+=1;
			if(!(cnt%n)) puts("");
		}
		x-=tmp;
	}
	return 0;
}