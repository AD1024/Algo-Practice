#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef double db;
typedef long long ll;

#define X first
#define Y second
#define sc scanf
#define pr printf
#define MP make_pair
#define PB push_back
#define mem(a,b) memset(a,b,sizeof(a))

int n;
const int N=20001;
const db eps=1e-8;

int sgn(db x){
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    return 1;
}

struct Point{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator - (const Point &t) const{
        return Point(x-t.x,y-t.y);
    }
    db operator ^ (const Point &t) const{
        return x*t.y-y*t.x;
    }
    db operator * (const Point &t) const{
        return x*t.x+y*t.y;
    }
    bool operator != (const Point &t) const{
        return sgn(x-t.x)!=0 || sgn(y-t.y)!=0;
    }
    void in(){
        sc("%lf%lf",&x,&y);
    }
    
}p[N];

struct Line
{
    Point s,e;
    
    Line(){}
    
    Line(Point _s,Point _e) { s=_s,e=_e; }
    
    pair<int,Point> operator & (const Line &b) const
    {
        Point res=s;
        if(sgn((s-e)^(b.s-b.e))==0)
        {
            if(sgn((s-b.e)^(b.s-b.e))==0)
                return MP(0,res);
            else return MP(1,res);
        }
        db t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x+=(e.x-s.x)*t;
        res.y+=(e.y-s.y)*t;
        return MP(2,res);
    }
};

bool OnLine(Point p1,Point p2,Point p3){
    return sgn((p2-p1)^(p3-p1))==0;
}

inline bool judge(Point t){
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++)
            if(OnLine(p[i],p[j],t))
                cnt++;
        if(cnt!=2) return 0;
    }
    return 1;
}

int main()
{
    sc("%d",&n);
    for(int i=0;i<n;i++) p[i].in();
    Point ans;
    int num=0;
    int a1=0;
    for(int b1=1;b1<n && num<2;b1++){
        int a2=1;
        if(b1==a2) a2=2;
        for(int b2=a2+1;b2<n && num<2;b2++){
            if(b1==b2) continue;
            pair<int,Point> t=(Line(p[a1],p[b1])&Line(p[a2],p[b2]));
            if(t.X!=2) continue;
            if(judge(t.Y)){
                if(num==0) ans=t.Y,num++;
                else if(t.Y!=ans) num++;
            }
        }
    }
    if(num==0) puts("This is a dangerous situation!");
    if(num==1) pr("V.I.P. should stay at (%.1f,%.1f).",ans.x,ans.y);
    if(num==2) puts("This is a dangerous situation!");
    return 0;
}