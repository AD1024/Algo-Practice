#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int N;

int main(){
	cin>>N;
	if(N==1 || N==3 || N==5){
		puts("NO");
	}else puts("YES");
	return 0;
}