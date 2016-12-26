/*
ID: ccodera1
LANG: C++
TASK: preface
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int I,V,X,L,C,D,M;

int N;

int main(){
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;++i){
		int t = i;
		while(t){
			if(t>=1000){
				t-=1000;
				M+=1;
			}
			if(t>=900 && t<1000){
				t-=900;
				M+=1;
				C+=1;
			}
			if(t>=500 && t<=900){
				t-=500;
				D+=1;
			}
			if(t>=400 && t<500){
				t-=400;
				D+=1;
				C+=1;
			}
			if(t>=100 && t<400){
				t-=100;
				C+=1;
			}
			if(t>=90 && t<100){
				t-=90;
				X+=1;
				C+=1;
			}
			if(t>=50 && t<90){
				t-=50;
				L+=1;
			}
			if(t>=40 && t<50){
				t-=40;
				L+=1;
				X+=1;
			}
			if(t>=10 && t<40){
				t-=10;
				X+=1;
			}
			if(t>=9 && t<10){
				t-=9;
				I+=1;
				X+=1;
			}
			if(t>=5 && t<9){
				t-=5;
				V+=1;
			}
			if(t>=4 && t<5){
				t-=4;
				V+=1;
				I+=1;
			}else if(t>=1 && t<4){
				t-=1;
				I+=1;
			}
		}
	}
	if(I>0){
		cout<<"I"<<" "<<I<<endl;
	}
	if(V>0){
		cout<<"V"<<" "<<V<<endl;
	}
	if(X>0){
		cout<<"X"<<" "<<X<<endl;
	}
	if(L>0){
		cout<<"L"<<" "<<L<<endl;
	}
	if(C>0){
		cout<<"C"<<" "<<C<<endl;
	}
	if(D>0){
		cout<<"D"<<" "<<D<<endl;
	}
	if(M>0){
		cout<<"M"<<" "<<M<<endl;
	}
	return 0;
}