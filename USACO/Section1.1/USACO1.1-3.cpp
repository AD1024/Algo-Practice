/*
ID: ccodera1
LANG: C++
TASK: friday
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
ll M;
int N;
int T;
int cnt[8];

bool isLeap(int y){
    return y%400==0 || (y%4==0 && (y%100!=0));
}

int getDays(int m,bool isleap){
    if(m == 2){
        return isleap?29:28;
    }
    if(m!=1 && m!=3 && m!=5 && m!=7 && m!=8 && m!=10 && m!=12){
        return 30;
    }else
        return 31;
}

inline int NextDate(int n){
    return n+1>7?1:n+1;
}

struct Date{
    int y,m,d;
    bool leap;
    Date(){}
    int cntY;
    Date(int yy,int mm,int dd){
        y = yy;
        m = mm;
        d = dd;
        cntY = 1;
        leap = isLeap(y);
    }
    void NextYear(){
        ++y;
        ++cntY;
        leap = isLeap(y);
    }
    void NextMonth(){
        m++;
        if(m>12){
            m=1;
            NextYear();
        }
    }
    void NextDay(){
        ++d;
        if(d>getDays(m,leap)){
            NextMonth();
            d = 1;
        }
    }
};

int main(){
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    Date d = Date(1900,1,1);
    int N;cin>>N;
    int dt = 1;
    while(d.cntY <= N){
        // cout<<d.y<<" "<<d.m<<" "<<d.d<<"\n";
        if(d.d == 13)
            cnt[dt]++;
        dt = NextDate(dt);
        d.NextDay();
    }
    cout<<cnt[6]<<" "<<cnt[7]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<" "<<cnt[4]<<" "<<cnt[5]<<"\n";
    return 0;
}