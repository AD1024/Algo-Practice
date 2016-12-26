#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

typedef long long LL;

inline LL power(int n, int w){
    LL res=1;
    for(int i=1;i<=w;i++){
        res*=n;
    }
    return res;
}

list<int> l;

inline void toBin(int K){
	while(K){
		l.push_front(K%2);
		K>>=1;
	}
}

int main(){
    int k,N;
    cin>>k>>N;
    toBin(N);
    int ans=0;
    int cnt=l.size()-1;
    l::iterator it;
    while(it!=l.end()){
    	ans+=(*it)*k*(cnt--);
    }
    cout<<ans;
    return 0;
}