#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

inline int gcd(int x,int y){
    while(x^=y^=x^=y%=x);return y;
}
inline int lcm(int x,int y){
    return x*y/gcd(x,y);
}

inline void parse(int &a,int &b){
    int g = gcd(a,b);
    a /= g;
    b /= g;
}

int main(){
    int a,b,c,d;
    ios::sync_with_stdio(false);
    cin>>a>>b>>c>>d;// a/b + c/d
    int di = b * d;
    a *= d;
    c *= b;
    int did = a + c;
    if(did > di){
        int itg = did / di;
        did -= di*itg;
        // did -= di;
        
        if(did == 0)
            cout<<itg<<endl;
        else{
            parse(did,di);
            cout<<itg<<"+"<<did<<"/"<<di<<endl;
        }
    }else{
        parse(did,di);
        if(did == di){
            cout<<1<<endl;
        }else{
            cout<<did<<"/"<<di<<endl;
        }
    }
    return 0;
}