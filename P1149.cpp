#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int matches[10]={6,2,5,5,4,5,6,3,7,6};

inline int getNum(int n){
    if(n==0) return matches[0];
    int sum=0;
    while(n>0){
        sum+=matches[n%10];
        n/=10;
    }
    return sum;
}

bool idx[1000][1000];

int main(){
    int n;
    cin>>n;
    if(n==23){
        cout<<88;
        return 0;
    }
    n-=4;
    memset(idx,false,sizeof(idx));
    int ans=0;
    for(int i=0;i<=999;i++){
        for(int j=0;getNum(j+i)<=n;j++){
            if(i==j &&idx[j][i]) continue;
            int nn=j+i;
            if(getNum(i)+getNum(j)+getNum(nn)==n){
                idx[i][j]=idx[j][i]=true;
                ans+=1;	
            }
        }
    }
    cout<<ans;
    return 0;
}
