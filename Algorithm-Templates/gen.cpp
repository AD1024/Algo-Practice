#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
	srand(time(NULL));
	freopen("data.txt","w",stdout);
	//int N=rand()%10000;
	int N;
	cin>>N;
	cout<<N<<endl;
	int tot=0;
	while(N--){
		int op;
		do{
			op=rand()%9;
		}while(op==0);
		//cout<<"op:"<<op<<endl;
		if(op==1){
			++tot;
			int v=rand()%1000000;
			cout<<op<<" "<<v<<endl;
		}else if(op==2){
			cout<<op<<endl;
			if(tot>0) --tot;
		}else if(op==3){
			++tot;
			int v=rand()%1000000;
			cout<<op<<" "<<v<<endl;
		}else if(op==4){
			if(tot>0) --tot;
			cout<<op<<endl;
		}else if(op==5){
			int pos=rand()%(tot+20);
			int v=rand()%1000000;
			cout<<op<<" "<<pos<<" "<<v<<endl;
		}else if(op==6){
			int pos=rand()%(tot+10);
			if(tot>0) tot--;
			cout<<op<<" "<<pos<<endl;
		}else if(op==7){
			int pos=rand()%(tot+5)+1;
			cout<<op<<" "<<pos<<endl;
		}else{
			cout<<op<<endl;
		}
	}
}
