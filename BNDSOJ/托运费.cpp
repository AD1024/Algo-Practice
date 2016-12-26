#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	float N;
	cin>>N;
	if(N<=50){
		printf("%.2f",N*0.15);
	}else{
		float ans=50.0*0.15;
		N-=50;
		ans+=N*0.25;
		printf("%.2f",ans);
	}
	return 0;
}