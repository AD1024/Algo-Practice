#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
	map<string,int> m;
	int n;
	cin>>n;
	string a;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(m[a]!=2){
			ans+=1;
			m[a]++;
		}
	}
	cout<<ans;
	return 0;
}
