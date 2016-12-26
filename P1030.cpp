#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

void DO(char *s1, char* s2,int cnt){
	if(!cnt) return;
	char root=s2[0];
	cout<<root;
	int p=strchr(s1,root)-s1;
	DO(s1,s2+cnt-p,p);
	DO(s1+1+p,s2+1,cnt-p-1);
}


int main(){
	char s1[10001],s2[10001],s3[10001]={'\0'};
	cin>>s1>>s2;
	int cur=0;
	for(int i=strlen(s2)-1;i>-1;--i){
		s3[cur++]=s2[i];
	}
	s3[cur]='\0';
	DO(s1,s3,strlen(s1));
	return 0;
}