#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double score[8];

int main(){
	for(int i=0;i<5;++i){
		cin>>score[i];
	}
	sort(score,score+5);
	double ret = 0.0;
	for(int i=1;i<4;++i) ret+=score[i];
	ret/=3;
	printf("%.2f",ret);
	return 0;
}