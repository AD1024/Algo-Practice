#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

string x;
int ans;

int dfs(int &pos){
	int mul = 0;
	int ret = 0;
	for(;pos<x.length();){
		if(x[pos+1] == '('){
			mul = x[pos]-'0';
            pos+=2;
			ret += dfs(pos) * mul;
		}else if(x[pos] == ')'){
            ++pos;
            return ret;
        }
		else{
            ++ret;++pos;
        }
	}
	return ret;
}

int main(){
    cin>>x;
    int p = 0;
    cout<<dfs(p);
    return 0;
}