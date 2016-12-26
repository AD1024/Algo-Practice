#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

inline void add(int a,int b){
	cout<<"C "<<a<<"\n";
	cout<<"C "<<b<<"\n";
	cout<<"F 1\nF 2";
	cout<<"T 1 2\n";
	cout<<"O 2\n";
}

inline void ABS(int a,int b){
	cout<<"C "<<a+b<<"\n";
	cout<<"C";
}

inline void MAX(int a,int b){
	a=max(a,b);
	cout<<"C "<<a<<"\n"<<"F 1\n"<<"O 1\n";
}
inline void toBin(int a){
	int k[32];
	int cur=0;
	while(a){
		k[cur++]=a%2;
		a/=2;
	}
	cout<<"I"<<"\n";
	cout<<"C 1\n";
	for(int i=32;i>=0;--i){
		if(!k[i]){
			cout<<"O 1\n";
		}else{
			cout<<"O 2\n";
		}
	}
}

inline void Mul(int a,int b){
	cout<<"C "<<a<<"\n";
	cout<<"C "<<b<<"\n";
	cout<<"K 1 2\n";
	cout<<"F 3\n";
	cout<<"O 3\n";
}

inline void GCD(int a,int b){
	while(a^=b^=a^=b%=a);
	cout<<"C "<<b<<"\n";
	cout<<"F 1\nO 1";
}

inline void XOR(int a,int b){
	int A[1100];
	int B[1100];
	int cura,curb;
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	cura=curb=0;
	while(a){
		A[cura++]=a%2;
		a/=2;
	}
	while(b){
		B[curb++]=b%2;
		b/=2;
	}
	int len=max(cura,curb);
	cout<<"I"<<"\n";
	cout<<"C 1\n";
	for(int i=len;i>=0;--i){
		if(A[i]!=B[i]){
			cout<<"O 2\n";
		}else{
			cout<<"O 1\n";
		}
	}
}

int main(){

}