#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a,string b){
	return a+b>b+a;
}

int main(){
	string nums[10001];
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>nums[i];
	}
	sort(nums+1,nums+N+1,cmp);
	for(int i=1;i<=N;i++){
		cout<<nums[i];
	}
	return 0;
}