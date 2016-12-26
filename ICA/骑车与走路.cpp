#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

#define eps 1e-5

int main(){
	int T;
	cin>>T;double dist;
	while(T--){
		cin>>dist;
		double bi = dist/3.0;
		bi+=50.0;
		double wal = dist/1.2;
		//cout<<bi<<" "<<wal<<endl;
		if(bi<wal){
			puts("Bike");
		}else if(wal<bi){
			puts("Walk");
		}else{
			puts("All");
		}
	}
	return 0;
}