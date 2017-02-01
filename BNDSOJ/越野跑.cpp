#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long ll;

int M,T,U,F,D;

int main(){
	cin>>M>>T>>U>>F>>D;
	char ch;ll ans = 0;
	while(T--){
		cin>>ch;
		if(ch == 'u' || ch == 'd'){
			M -= U+D;
		}else{
			M -= (F<<1);
		}
		if(M < 0) break;
		++ans;
	}
	cout<<ans;
	return 0;
}