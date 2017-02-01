#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int MAXN = 1110;

struct BigInt{
    int len;
    char s[MAXN];
    // Constructor
    BigInt (){
        memset(s,0,sizeof(s));
        s[0] = '0';
        len = 1;
    }
    BigInt(int num){*this=num;}
    BigInt(const char *num){*this=num;}

    // Logic Operands
    bool operator < (const BigInt &b){
        if(len != b.len) return len < b.len;
        for(int i = len-1; i >= 0; i--){
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        }
        return false;
    }
    bool operator > (const BigInt &b){
        if(len!=b.len) return len > b.len;
        for(int i=len-1;i>=0;i--){
            if(s[i] != b.s[i]) return s[i]>b.s[i];
        }
        return false;
    }
    BigInt operator = (const char *num){
        for(int i = 0; num[i] == '0'; num++) ;
        len = strlen(num);
        for(int i = 0; i < len; i++) s[i] = num[len-i-1];
        return *this;
    }
    string str()const{
        string res = "";
        for(int i=0;i<len;i++) res=s[i]+res;
        return res;
    }
};

istream& operator >> (istream &in, BigInt &x){
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream &out, const BigInt &x){
    out << x.str();
    return out;
}

void quicksort(int b,int e,BigInt a[]) {
    int i=b,j=e;
    BigInt x=a[(b+e)>>1]; 
    do{
        while(a[i]<x) i++; 
        while(a[j]>x) j--;
        if(i<=j)
            swap(a[i++],a[j--]); 
    }while(i<j);
    if(i<e) quicksort(i,e,a);
    if(j>b) quicksort(b,j,a);
}

void quicksort1(int b,int e,unsigned int a[]) {
    int i=b,j=e;
    int x=a[(b+e)>>1]; 
    do{
        while(a[i]<x) i++; 
        while(a[j]>x) j--;
        if(i<=j)
            swap(a[i++],a[j--]); 
    }while(i<j);
    if(i<e) quicksort1(i,e,a);
    if(j>b) quicksort1(b,j,a);
}

inline int read(){
    int a = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        ch = getchar();
    }
    while(isdigit(ch)){
        a = a*10+ch-'0';
        ch = getchar();
    }
    return a;
}

BigInt a[100];

unsigned int b[1000010];

int main(){
    int N;N = read();
    if(N>10){
        for(register int i=1;i<=N;++i){
            cin>>b[i];
        }
        quicksort1(1,N,b);
        for(int i=1;i<=N;++i) printf("%d\n",b[i]);
    }else{
        for(register int i=1;i<=N;++i){
            cin>>a[i];
        }
        quicksort(1,N,a);
        for(int i=1;i<=N;++i){
            cout<<a[i]<<"\n";
        }
    }
    return 0;
}