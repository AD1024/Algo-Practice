#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

double A,B,C,D;
#define eps 10e-5
#define db double

db MID(db l,db r){
    return (l+r)/(double)2.0;
}

db f(db x){
    return A*x*x*x+B*x*x+C*x+D;
}

db binSearch(db l,db r){
    if(r-l<=eps) return MID(l,r);
    db mid = f(MID(l,r));db ll=f(l);db rr=f(r);
    if(mid==0){
        return MID(l,r);
    }else{
        if(mid*ll<0){
            return binSearch(l,MID(l,r));
        }else if(mid*rr<0){
            return binSearch(MID(l,r),r);
        }
    }
    return -1000;
}

int main(){
    cin>>A>>B>>C>>D;
    int ct=0;
    for(db i=-100;i<101;++i){
        if(ct==3) break;
        db m=f(i);db n=f(i+1);
        if(m==0){
            ct++;
            printf("%.2lf ",i);//puts("m");
        }else if(n==0){
            ct++;
            printf("%.2f ",i+1);//puts("n");
            ++i;
        }else if(m*n<0){
            db ans=binSearch(i,i+1);
            if(ans!=-1000.0){
                ct++;
                printf("%.2lf ",ans);//puts("ans");
            }
        }
    }
    return 0;
}