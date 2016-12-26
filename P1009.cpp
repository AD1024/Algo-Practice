#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
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
    bool operator != (const BigInt &b){
        return !(*this == b);
    }
    bool operator <= (const BigInt &b){
        return *this<b || *this==b;
    }
    bool operator >= (const BigInt &b){
        return *this>b || *this==b;
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
    BigInt operator + (const BigInt &b) const{
        BigInt c;
        c.len = 0;
        for(int i = 0, g = 0; g || i < max(len, b.len); i++)
        {
            int x = g;
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    BigInt operator += (const BigInt &b){
        *this = *this + b;
        return *this;
    }
    void clear(){
        while(len > 1 && !s[len-1]) len--;
    }
    BigInt operator * (const BigInt &b){
        BigInt c;
        c.len = len + b.len;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < b.len; j++)
            {
                c.s[i+j] += s[i] * b.s[j];
            }
        }
        for(int i = 0; i < c.len; i++)
        {
            c.s[i+1] += c.s[i]/10;
            c.s[i] %= 10;
        }
        c.clear();
        return c;
    }
    BigInt operator *= (const BigInt &b){
        *this = *this * b;
        return *this;
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
    BigInt operator -= (const BigInt &b){
        *this = *this - b;
        return *this;
    }
    BigInt operator / (const BigInt &b){
        BigInt c, f = 0;
        for(int i = len-1; i >= 0; i--)
        {
            f = f*10;
            f.s[0] = s[i];
            while(f >= b)
            {
                f -= b;
                c.s[i]++;
            }
        }
        c.len = len;
        c.clear();
        return c;
    }
    BigInt operator /= (const BigInt &b){
        *this  = *this / b;
        return *this;
    }
    BigInt operator % (const BigInt &b){
        BigInt r = *this / b;
        r = *this - r*b;
        return r;
    }
    BigInt operator %= (const BigInt &b){
        *this = *this % b;
        return *this;
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

inline BigInt Fac(BigInt a){
    BigInt ret=1;
    for(BigInt i=1;i<=a;i+=BigInt(1)){
        ret*=i;
    }
    return ret;
}

int main(){
    BigInt a;
    cin>>a;
    BigInt ans=0;
    for(BigInt i=1;i<=a;i+=BigInt(1)){
        ans+=Fac(i);
    }
    cout<<ans;
    return 0;
}