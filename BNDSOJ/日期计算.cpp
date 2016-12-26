#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int d[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

struct Date{
	int year,month,day;
	bool leap;
	Date(){}
	Date(int y,int m,int d){
		year=y;
		month=m;
		day=d;
		leap=ok(year);
	}
	bool ok(int N){
		if(N%400==0 || (N%100!=0 && N%4==0))
			return true;
		else return false;
	}
	void NextYear(){
		year++;
		leap=ok(year);
	}
	void NextMonth(){
		if(month+1>12){
			month=1;NextYear();
		}else month+=1;
	}
	void NextDay(){
		if(leap){
			if(day+1>d[1][month]){
				NextMonth();
				day=1;
			}else{
				day++;
			}
		}else{
			if(day+1>d[0][month]){
				NextMonth();
				day=1;
			}else{
				day++;
			}
		}
	}
	void work(int N){
		for(int i=1;i<=N;++i){
			NextDay();
		}
	}
};

int main(){
	int y,m,d;
	cin>>y>>m>>d;
	int N;cin>>N;
	Date ans=Date(y,m,d);
	ans.work(N);
	printf("%d %d %d",ans.year,ans.month,ans.day);
	return 0;
}