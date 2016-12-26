#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int cnt[30];
int main(){
	char str[100001];
	cin>>str;
	for(int i=0;i<strlen(str);++i){
		//if(str[i]=='n' || str[i]=='i' || str[i]=='t' || str[i]=='e'){
		cnt[str[i]-'a']++;
	}
	int n=cnt['n'-'a'];
	int i=cnt['i'-'a'];
	int e=cnt['e'-'a'];
	int t=cnt['t'-'a'];
	e/=3;
	int ans=min(t,min(e,i));
	if(((n-1)/2)<ans){
		printf("%d",(n-1)/2);
	}else{
		cout<<ans;
	}
	return 0;
}