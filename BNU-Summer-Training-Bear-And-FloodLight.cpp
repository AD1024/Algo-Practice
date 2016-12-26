#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define PI (double)acos(-1.0)
#define FABS(x) x>0?(double)x:(double)(-x)
#define zrep(i,n) for(int i=0;i<n;++i)

const int MAXN = 1<<20;
int N;
double l,r,f[MAXN];

struct Light{
    double x,y;
    double degree;
    void init(){
        cin>>x>>y>>degree;
        degree*=PI/180;
        x-=l;
        y=fabs(y);
    }
}list[MAXN+10];

inline void init(){
    memset(f,0,sizeof(f));
    cin>>N>>l>>r;
    r-=l;
    zrep(i,N){
        list[i].init();
    }
}

inline double calc(double x0,int id){
    double k1=atan((r-list[id].x)/list[id].y);
    double dg=min(k1,atan((x0-list[id].x)/list[id].y)+list[id].degree);
    return list[id].x+list[id].y*tan(dg);
}

#define MAX(x,y) x>y?(double)x:(double)y
inline void work(){
    zrep(i,(1<<N)){
        zrep(j,N){
            if(!(i&(1<<j))){
                f[i|(1<<j)]=MAX(f[(i|1<<j)],calc(f[i],j));
            }
        }
    }
}

int main(){
    init();
    work();
    printf("%.9lf\n",f[(1<<N)-1]);
    return 0;
}
