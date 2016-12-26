#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

string fib[100];

inline string add(string a,string b){
	if(a.size()<b.size()) swap(a,b);
	int sum=0;
	for(int i=a.length()-1,j=b.length()-1;i>=0;--i,--j){
		sum+=a[i]-'0';
		if(j>=0){
			sum+=b[j]-'0';
		}
		a[i]=sum%10+'0';sum/=10;
	}
	if(sum){
		a='1'+a;
	}
	return a;
}

int main(){
	int N;cin>>N;
	string ans[1001];
	fib[1]="1";fib[2]="1";
	ans[1]="1";ans[2]="2";
	for(int i=3;i<=N;++i){
		fib[i]=add(fib[i-1],fib[i-2]);
		ans[i]=add(ans[i-1],fib[i]);
	}
	cout<<ans[N];
	return 0;
}