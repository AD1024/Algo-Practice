#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;


int N,curr,last;
bool idx[10000010];

inline int ABS(int x){
	return x>0?x:-x;
}

int main(){
    cin>>N;
    cin>>last;
    for(int i=1;i<N;i++){
        cin>>curr;
        idx[ABS(curr-last)]=true;
        last=curr;
    }
    for(int i=1;i<N;i++){
        if(!idx[i]){
            puts("Not jolly");
            return 0;
        }
    }
    puts("Jolly");
    return 0;
}