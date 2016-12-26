#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;
const int MAXN = 1010;

int dir[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int m;
int n;
struct Point{
    int x;
    int y;
    int id;
};
queue<Point> q;
int g[MAXN][MAXN];
void bfs(Point p){
    q.push(p);
    while(!q.empty()){
        Point pnt;
        for(int i=0;i<8;i++){
            pnt=q.front();
            int cX,cY;
            cX=pnt.x+dir[i][0];
            cY=pnt.y+dir[i][1];
            if(cX>n || cY>m || cX<1 || cY<1 || g[cX][cY]!=-1){
                continue;
            }
            pnt.x+=dir[i][0];
            pnt.y+=dir[i][1];
            pnt.id+=1;
            g[pnt.x][pnt.y]=pnt.id;
            q.push(pnt);
        }
        q.pop();
    }
}

int main(){
    int ux,uy;
    cin>>n>>m>>ux>>uy;
    Point start;
    start.x=ux;start.y=uy;
    start.id=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            g[i][j]=-1;
        }
    }
    g[ux][uy]=0;
    bfs(start);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<setiosflags(ios::left)<<setw(5)<<g[i][j];
        }
        cout<<endl;
    }
    return 0;
}
