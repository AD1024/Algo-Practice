#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int get(int y,int m,int d){
	if(m == 1){
		m = 13;--y;
	}
	if(m == 2){
		m = 14;--y;
	}
	int week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return week;
}

int main(){
	freopen("in.in","r",stdin);
	int N;
	cin>>N;
	while(N--){
		int yy,mm,dd;
		scanf("%d-%d-%d",&yy,&mm,&dd);
		// cout<<yy<<" "<<mm<<" "<<dd<<endl;
		string id;cin>>id;
		char k =id[5];
		int w = get(yy,mm,dd);
		++w;
		cout<<w<<endl;
		switch(w){
			case 1:{
				if(k == '1' || k == '6'){
					puts("yes");
				}else{
					puts("no");
				}
				break;
			}
			case 2:{
				if(k == '2' || k == '7'){
					puts("yes");
				}else{
					puts("no");
				}
				break;
			}
			case 3:{
				if(k == '3' || k == '8'){
					puts("yes");
				}else{
					puts("no");
				}
				break;
			}
			case 4:{
				if(k == '4' || k == '9'){
					puts("yes");
				}else{
					puts("no");
				}
				break;
			}
			case 5:{
				if(k == '5' || k == '0' || !isdigit(k)){
					puts("yes");
				}else{
					puts("no");
				}
				break;
			}
			default:{
				puts("no");
			}
		}
	}
	return 0;
}