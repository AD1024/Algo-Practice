#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

string word[10001];
string max_str;
int cnt[10001];

int N;
inline void init(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>word[i];
	}
	cin>>word[0];
}

inline string connect(string a,string b){
	int lena=a.length();int lenb=b.length();
	int len=lena>lenb?lenb:lena;
	if(a.length()==1) len+=1;
	string res;
	for(int i=1;i<len;++i){
		if(a.substr(lena-i,i)==b.substr(0,i)){
			res=a+b.substr(i);
			if(res.length()>max_str.length()){
				max_str=res;
			}
			return res;
		}
	}
	return "";
}

inline void dfs(string str){
	string cnnt;
	for(int i=1;i<=N;++i){
		if(cnt[i]>1) continue;
		cnnt=connect(str,word[i]);
		if(cnnt.length()==0) continue;
		cnt[i]++;
		dfs(cnnt);
		cnt[i]--;
	}
}

int main(){
	init();
	dfs(word[0]);
	cout<<max_str.size();
	return 0;
}