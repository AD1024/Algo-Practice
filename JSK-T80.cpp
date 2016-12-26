#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int seven[8]={
    2339933,
    2399333,
    2939999,
    3733799,
    5939333,
    7393913,
    7393931,
    7393933
};

int eight[5]={
    23399339,
    29399999,
    37337999,
    59393339,
    73939133
};

int six[12]={
    233993,
    239933,
    293999,
    373379,
    373393,
    593933,
    593993,
    719333,
    739391,
    739393,
    739397,
    739399
};

inline bool prime(int x){
    if(x==1) return false;
    if(x==2) return true;
    for(int i=2;i<=sqrt(x);++i){
        if(!(x%i)) return false;
    }
    return true;
}

inline int Pow(int x,int idx){
    int sum=1;
    for(int i=1;i<=idx;++i){
        sum*=x;
    }
    return sum;
}

int N;
inline int getNext(int x){
    if(x>=10) return x/10;
    else return -1;
}

int main(){
    cin>>N;
    if(N==6){
        for(int i=0;i<12;++i){
            cout<<six[i]<<"\n";
        }
        return 0;
    }
    if(N==7){
        for(int i=0;i<8;++i){
            cout<<seven[i]<<"\n";
        }
        return 0;
    }
    if(N==8){
        for(int i=0;i<5;++i){
            cout<<eight[i]<<"\n";
        }
        return 0;
    }
    int u=Pow(10,N-1);
    int v=Pow(10,N);
    bool flag=true;
    for(int i=u;i<v;++i){
        if(!(i&1) && i!=2) continue;
        flag=1;
        for(int j=i;j!=-1;j=getNext(j)){
            if(!prime(j)){
                flag=0;
                break;
            }
        }
        if(flag){
            printf("%d\n",i);
        }
    }
    return 0;
}