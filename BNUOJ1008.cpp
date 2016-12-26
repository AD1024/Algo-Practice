#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define PI 3.141592653589793

struct P{
    double x;
    double y;
};

inline double square(double x){
    return x*x;
}

inline double calcdis(P a,P b){
    return sqrt(square(a.x-b.x)+square(a.y-b.y));
}


int main(){
    P a,b,c;
    double A,C,B;
    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y){
        C=calcdis(a,b);
        A=calcdis(b,c);
        B=calcdis(a,c);
        double cosa = (square(B)+square(C)-square(A))/(2*B*C);
        double sina = (double)sqrt((double)(1-square(cosa)));
        double D = A/sina;
        printf("%.2lf\n",D*PI);
    }
    return 0;
}