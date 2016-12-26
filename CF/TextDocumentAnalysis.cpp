#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> in;
vector<string> out;

bool cmp(string a,string b){
	return a.length()>b.length();
}

bool isChar(char x){
	return (x>='a' && x<='z') || (x>='A' && x<='Z');
}

int main(){
	int N;cin>>N;
	string a;
	cin>>a;
	bool flag=false;
	for(int i=0;i<a.length();++i){
		if(a[i]=='('){
			flag=true;
			continue;
		}
		else if(a[i]==')'){
			flag=false;
			continue;
		}
		if(a[i]=='_') continue;
		if(flag){
			string add="";
			while(isChar(a[i])){
				add+=a[i];
				++i;
			}
			--i;
			in.push_back(add);
		}else{
			string add="";
			while(isChar(a[i])){
				add+=a[i];
				++i;
			}
			--i;
			out.push_back(add);
		}
	}
	sort(out.begin(),out.end(),cmp);
	cout<<(out.size()?out[0].length():0)<<" "<<in.size();
	return 0;
}