#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char str1[10001];
	char str2[10001];
	cin>>str1>>str2;
	int len = strlen(str1);
	for(int i=0;i<len;i++){
		printf("%d", !(str1[i]-'0')^(str2[i]-'0'));
	}
	return 0;
}