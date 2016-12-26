#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct P{
	int id;
	int fscore;
	int cscore;
	char islead;
	char iswest;
	int essay;
	int mon;
	string name;
}list[10001];


bool cmp(P a, P b){
	if(a.mon==b.mon){
		return a.id<b.id;
	}else{
		return a.mon>b.mon;
	}
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		list[i].id=i;
		cin>>list[i].name>>list[i].fscore>>list[i].cscore>>list[i].islead>>list[i].iswest>>list[i].essay;
		list[i].mon=0;
		if(list[i].fscore>80 && list[i].essay>=1){
			list[i].mon+=8000;
		}
		if(list[i].fscore>85 && list[i].cscore>80){
			list[i].mon+=4000;
		}
		if(list[i].fscore>90){
			list[i].mon+=2000;
		}
		if(list[i].fscore>85 && list[i].iswest=='Y'){
			list[i].mon+=1000;
		}
		if(list[i].cscore>80 && list[i].islead=='Y'){
			list[i].mon+=850;
		}
	}
	int sum=0;
	for(int i=0;i<N;i++){
		sum+=list[i].mon;
	}
	sort(list,list+N,cmp);
	cout<<list[0].name<<"\n"<<list[0].mon<<"\n"<<sum;
	return 0;
}