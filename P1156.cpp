#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int D,G;

bool status[500][6000];

struct R{
	int t;
	int add;
	int len;
}list[400];

void init(){
	cin>>D>>G;
}

bool cmp(R a,R b){
	return a.t<b.t;
}

int main(){
	init();
	int sum=10;
	for(int i=1;i<=G;i++){
		cin>>list[i].t>>list[i].add>>list[i].len;
		sum+=list[i].add;
	}
	sort(list+1,list+G+1,cmp);
	status[0][10]=true;
	for(int i=1;i<=G;i++){
		for(int j=D-1;j>=0;j--){
			for(int k=sum;k>=list[i].t;k--){
				if(status[j][k]){
					status[j+list[i].len][k]=true;
					if(j+list[i].len>=D){
						cout<<list[i].t;
						return 0;
					}
					status[j][k+list[i].add]=true;
				}
			}
		}
	}
	for(int i=sum;i>=1;i--){
		if(status[0][i]){
			cout<<i;
			return 0;
		}
	}
	return 0;
}