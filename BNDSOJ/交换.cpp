#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

string a,b;
int ans=0;
int l1,l2;
inline bool ok(int i,int j){
	if(b[j]==a[i+1] && b[j]==a[i-1] && a[i]==b[j+1] && a[i]==b[j-1]){
		return true;
	}
	return false;
}

int main(){
	cin>>a>>b;
	l1=a.length();l2=b.length();
	for(int i=1;i<l1-1;++i){
		for(int j=1;j<l2-1;++j){
			if(ok(i,j)){
				++ans;
			}
		}
	}
	cout<<ans;
	return 0;
}