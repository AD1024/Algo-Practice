#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll a[220],b[220],v[220];
ll f[220][220];
int N;int A,B;
int main(){
	cin>>N;
	cin>>A>>B;
	if(A<B) swap(A,B);
	for(int i=1;i<=N;++i){
		cin>>a[i]>>b[i]>>v[i];
	}
	for(int i=1;i<=N;++i){
		for(int j=A;j>=a[i];--j){
			for(int k=A;k>=b[i];--k){
				f[j][k]=max(f[j][k],f[j-a[i]][k-b[i]]+v[i]);
				if(j>=b[i] && k>=a[i]){
					f[j][k]=max(f[j][k],f[j-b[i]][k-a[i]]+v[i]);
				}
			}
		}
	}
	cout<<max(f[A][B],f[B][A]);
	return 0;
}