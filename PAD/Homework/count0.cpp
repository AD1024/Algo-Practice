#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	int N;cin>>N;
	int k;
	int ans=0;
	for(int i=1;i<=N;++i){
		k=i;
		while(!(k%5)){
			k/=5;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}