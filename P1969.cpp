#include <iostream>
using namespace std;

inline int MAX(int x,int y){
	return x>y?x:y;
}

int ans=0;
int pre;
int cur;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>cur;
		ans+=MAX(cur-pre,0);
		pre=cur;
	}
	cout<<ans;
	return 0;
}