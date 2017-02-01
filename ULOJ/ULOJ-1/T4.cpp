#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
using namespace std;

int a,b,c;

int main(){
	cin>>a>>b>>c;
	int ans = 0x3f3f3f3f;
	int dst;
	for(int i=1;i<=100;++i){
		ans = min(ans,abs(i-a) + abs(i-b) + abs(i-c));
	}
	cout<<ans;
	return 0;
}