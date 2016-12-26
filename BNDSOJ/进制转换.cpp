#include <iostream>
#include <cstring>
using namespace std;

const char num[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string a;
int K,N;
void convert(int x){
	while(x){
		a=num[x%N]+a;
		x/=N;
	}
	cout<<a;
}

int main(){
	cin>>K>>N;
	convert(K);
	return 0;
}