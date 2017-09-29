#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1110;

struct BigInt{
    int len, s[MAXN];
    // Constructor
    BigInt (){
        memset(s,0,sizeof(s));
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
    bool operator == (const BigInt &b){
        if(len!=b.len) return false;
        for(int i=0;i<len;++i){
            if(s[i]!=b.s[i]) return false;
        }
        return true;
    }

    // Arithmetic Operands
    BigInt operator = (const int num){
        char s[MAXN];
        sprintf(s, "%d", num);
        *this=s;
        return *this;
    }
    BigInt operator = (const char *num){
        for(int i = 0; num[i] == '0'; num++) ;
        len = strlen(num);
        for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
        return *this;
    }
    
    void clear(){
        while(len > 1 && !s[len-1]) len--;
    }
    
    BigInt operator - (const BigInt &b){
        BigInt c;
        c.len = 0;
        for(int i=0,g=0;i<len;i++){
            int x=s[i]-g;
            if(i<b.len)x-=b.s[i];
            if(x>=0) g=0;
            else{
                g=1;
                x+=10;
            }
            c.s[c.len++]=x;
        }
        c.clear();
        return c;
    }
    string str()const{
        string res = "";
        for(int i=0;i<len;i++) res=char(s[i]+'0')+res;
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


BigInt a,b,c;
BigInt A[101]

int main(){
    
}