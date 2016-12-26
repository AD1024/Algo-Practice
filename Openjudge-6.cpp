#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int MIN(int a,int b){
	return a>b?b:a;
}


inline bool cmp(string a,string b){
	int len=MIN(a.size(),b.size());
	for(int i=0;i<len;++i){
		if(a[i]!=b[i]){
			if((a[i]>='A' && a[i]<='Z') || (b[i]>='a' && b[i]<='z') || (a[i]>='a' && a[i]<='z') || (b[i]>='A' && b[i]<='Z')){
				if(toupper(a[i])>toupper(b[i])){
					return false;
				}else{
					return true;
				}
			}else{
				return a[i]<b[i];
			}
		}
	}
	return true;
}
string list[10001];
int T;
int main(){
	cin>>T;
	int n;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>list[i];
		}
		sort(list+1,list+1+n,cmp);
		for(int i=1;i<=n;++i){
			cout<<list[i]<<"\n";
		}
		puts("");
	}
	return 0;
}