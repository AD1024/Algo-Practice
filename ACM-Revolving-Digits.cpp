#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1000010
int Next[MAXN];
void getNext(char *str,int len){
	int i=-1;
	int j=0;
	Next[0]=-1;
	while(j<len){
		if(i==-1 || str[i]==str[j]){
			Next[++j]=++i;
		}else{
			i=Next[i];
		}
	}
}


void extend(char *str,int len){
	memset(Next,0,sizeof(Next));
	int cur=0;
	int i=1;
	Next[0]=len;
	while(cur+1<len && str[cur]==str[cur+1]){
		++cur;
	}
	Next[1]=cur;
	int k=1;
	while(++i<(len>>1)){
		int maxn=k+Next[k]-1;
		Next[i]=min(Next[i-k],max(maxn-i+1,0));
		while(i+Next[i]<len && str[Next[i]]==str[i+Next[i]]){
			Next[i]+=1;
		}
		if(k+Next[k]<i+Next[i]){
			k=i;
		}
	}
}
char str[MAXN<<1];
int main(){
	int T;
	cin>>T;
	int CASE=0;
	while(T--){
		++CASE;
		scanf("%s",str);
		int len = strlen(str);
		getNext(str,len);
		int div;
		if(len%(len-Next[len])==0){
			div=len/(len-Next[len]);
		}else{
			div=1;
		}
		// char str2[MAXN<<1];
		// strcpy(str2,str);
		// strcat(str,str2);
		for(int i=0;i<=len;++i){
			str[i+len]=str[i];
		}
		extend(str,len<<1);
		int gt=0,eq=0,lt=0;
		for(int i=0;i<len;++i){
			if(Next[i]>=len){
				eq++;
			}else if(str[Next[i]]<str[Next[i]+i]){
				gt++;
			}else lt++;
		}
		printf("Case %d: %d %d %d\n",CASE,lt/div,eq/div,gt/div);
	}
	return 0;
}