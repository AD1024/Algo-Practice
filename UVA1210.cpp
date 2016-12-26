#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

inline bool isprime(int x){
    if(x==2) return true;
    if(!(x&1)) return false;
    if(x==1) return false;
    for(int i=2;i<=sqrt(x);++i){
        if(!(x%i)){
            return false;
        }
    }
    return true;
}

inline int nextPrim(int n){
    n-=1;
    while(!isprime(n--));
    return n+1;
}

int main(){
    int n;
    bool flag;
    int kk;
    int cnt;
    int half;
    int sum;
    while(~scanf("%d",&n)&&n){
        half=n/2;
        kk=nextPrim(n);
        cnt=0;
        if(isprime(n)) cnt++;
        while(kk>=2){
            flag=false;
            int zz=kk;
            sum=0;
            sum+=zz;
            while(sum!=n && sum<n){
                int t=nextPrim(zz);
                sum+=t;
                zz=t;
                // printf("%d ",zz);
                if(sum==n){
                    flag=true;
                    break;
                }
            }
            // cout<<endl;
            if(flag) cnt+=1;
            kk=nextPrim(kk);
        }
        printf("%d\n",cnt);
    }
    return 0;
}