#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int every=250;

int main(){
	int x,n;
	int tot=0;
	cin>>x>>n;
	while(n>0){
		if(x>7) x-=7;
		n-=1;
		if(x<6){
			tot+=250;
			x++;
		}else{
			x++;
		}
	}
	cout<<tot;
	return 0;
}
