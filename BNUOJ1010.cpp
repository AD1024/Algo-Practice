#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<string,string> list;
map<string,bool> idx;

const char orth[5]={'a','e','i','o','u'};

int main(){
	int L,N;
	cin>>L>>N;
	string str,strp;
	for(int i=0;i<L;i++){
		cin>>str>>strp;
		list[str]=strp;
		idx[str]=true;
	}
	while(N--){
		cin>>str;
		if(idx[str]){
			cout<<list[str]<<"\n";
			continue;
		}
		if(str[str.size()-2]!=orth[0] && str[str.size()-2]!=orth[1] && str[str.size()-2]!=orth[2] && str[str.size()-2]!=orth[3] && str[str.size()-2]!=orth[4]){
			if(str[str.size()-1]=='y'){
				str[str.size()-1]='i';
				str+="es";
				cout<<str<<"\n";
				continue;
			}else{
				cout<<str+'s'<<"\n";
				continue;
			}
		}else{
			if(str[str.size()-1]=='o' || str[str.size()-1]=='s' || str[str.size()-1]=='x'){
				cout<<str+"es"<<"\n";
				continue;
			}else{
				if((str[str.size()-2]=='c' || str[str.size()-2]=='s') && str[str.size()-1]=='h'){
					cout<<str+"es"<<"\n";
					continue;
				}
			}
		}
		cout<<str+'s'<<"\n";
	}
	return 0;
}