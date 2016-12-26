#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ans[20];
int N;
int k;
int main(){
	cin>>k;
	while(k--){
		cin>>N;
		ans[N]++;
	}
	cout<<ans[1]<<"\n"<<ans[5]<<"\n"<<ans[10];
	return 0;
}