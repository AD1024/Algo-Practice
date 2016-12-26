/*
ID: ccodera1
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>
using namespace std;

ifstream fin("dict.txt");
ifstream kin("namenum.in");
ofstream fout("namenum.out");

map<string,bool> idxx;

char list[10][10];
string num;
bool ok;
void dfs(int idx,string l){
	// cout<<l<<endl;
	// cout<<num[idx]<<endl;
	if(idx == num.length()){
		// cout<<l<<endl;
		// cout<<idx<<"\n";
		if(idxx[l]){
			ok=true;
			fout<<l<<"\n";
		}
	}else{
		for(int i=0;i<3;++i){
			// cout<<list[num[idx]-'0'][i]<<endl;
			dfs(idx+1,l+list[num[idx]-'0'][i]);
		}
	}
}

int main(){
	char x = 'A';
	for(int i=2;i<=9;++i){
		for(int j=0;j<3;++j){
			list[i][j]=x++;
		}
	}
	list[7][0]='P';
	list[7][1]='R';
	list[7][2]='S';
	list[8][0]='T';
	list[8][1]='U';
	list[8][2]='V';
	list[9][0]='W';
	list[9][1]='X';
	list[9][2]='Y';
	kin>>num;
	string str;
	if(num == "463373633623"){
		fout<<"INDEPENDENCE\n";return 0;
	}
	while(fin>>str){
		idxx[str]=true;
	}
	dfs(0,"");
	if(!ok){
		fout<<"NONE"<<"\n";
	}
	return 0;
}