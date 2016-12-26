#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int N;

inline int read(){
    char ch;
    bool flag = false;
    int a=0;
    while(!((((ch=getchar())>='0') && (ch<='9')) || (ch=='-')));
    if(ch!='-'){
        a *= 10;
        a += ch - '0';
    }
    else{
        flag = true;
    }
    while(((ch=getchar())>='0')&& (ch<='9')){
        a *= 10;
        a += ch - '0';
    }
    if(flag){
        a = -a;
    }
    return a;
}
void write(int a){
    if(a<0){
        putchar('-');
        a = -a;
    }
    if(a>=10){
        write(a / 10);
    }
    putchar(a % 10 + '0');
}

bool cmp(int &a,int &b){
    return a>b;
}

const int Pow[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

inline int MAX(int x){
    int a[1001];
    int cur=0;
    while(x){
        a[cur++]=x%10;
        x/=10;
    }
    sort(a,a+cur);
    int ret=0;
    int p=0;
    for(int i=3;i>=0;--i){
        ret+=a[i]*Pow[p++];
    }
    return ret;
}

inline int MIN(int x){
    int a[1001];
    int cur=0;
    while(x){
        a[cur++]=x%10;
        x/=10;
    }
    sort(a,a+cur,cmp);
    int ret=0;
    int p=0;
    for(int i=cur-1;i>=0;--i){
        ret+=a[i]*Pow[p++];
    }
    return ret;
}

int main(){
    N=read();
    int step=0;
    while(N!=6174){
        ++step;
        int a,b;
        a=MAX(N);
        b=MIN(N);
        N=abs(a-b);
    }
    write(step);
    return 0;
}