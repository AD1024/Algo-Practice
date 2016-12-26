#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MOD 1000000007
// f(n) = (f(n-1)+f(n-2))*2+3
/*
                  [2,1,0] 
[f(n-1),f(n-2),3]*[2,0,0]=[f(n),f(n-1),3]
				  [1,0,1]
*/
typedef long long ll;
ll a[4][4]={{2,1,0},
			{2,0,0},
			{1,0,1}};

ll b[4][4]={{2,0,3},
			{0,0,0},
			{0,0,0}};
ll K[4][4]={{1,0,0},
			{0,1,0},
			{0,0,1}};

int f[10];
ll temp[4][4];
inline void FastPow(int x){
	while(x){
		if(x&1){
			memset(temp,0,sizeof(temp));
			for(int i=0;i<3;++i){
				for(int j=0;j<3;++j){
					//temp[i][j]=0;
					for(int k=0;k<3;++k){
						temp[i][j]+=(K[i][k]*a[k][j]);
						temp[i][j]%=MOD;
					}
				}
			}
			for(int i=0;i<3;++i){
				for(int j=0;j<3;++j){
					K[i][j]=temp[i][j];
				}
			}
		}
		memset(temp,0,sizeof(temp));
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				//temp[i][j]=0;
				for(int k=0;k<3;++k){
					temp[i][j]+=(a[i][k]*a[k][j]);
					temp[i][j]%=MOD;
				}
			}
		}
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j)
				a[i][j]=temp[i][j];
		}
		x>>=1;
	}
}

int main(){
	int N;cin>>N;
	FastPow(N-1);
	memset(temp,0,sizeof(temp));
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<3;++k){
				temp[i][j]+=(b[i][k]*K[k][j]);
				temp[i][j]%=MOD;
			}
		}
	}
	if(N==0) puts("0");
	else{
		cout<<temp[0][0];
	}
	return 0;
}