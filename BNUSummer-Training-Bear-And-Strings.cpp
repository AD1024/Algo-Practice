#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

char str[5010];

int main(){
	cin>>str;
	long long ans=0;
	int n=strlen(str);
	int cur=-1;
	for(int i=0;i<n-3;++i){
		if(strncmp(str+i,"bear",4)==0){
			ans+=(i-cur)*(n-i-3);
			cur=i;
		}
	}
	cout<<ans;
	return 0;
}