#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Pos{
    int x,y;
    int step;
    Pos(){}
    Pos(int xx,int yy,int st){
        x=xx;
        y=yy;
        step=st;
    }
};

queue<Pos> q;
bool vis[110][100];
int x,y,z;
bool flag=false;

inline void enqueue(Pos add){
    if(!vis[add.x][add.y]){
        vis[add.x][add.y]=true;
        q.push(add);
    }
}

inline void BFS(){
    vis[x][y]=true;
    q.push(Pos(x,0,0));
    Pos k;
    while(q.size()){
        k=q.front();q.pop();
        if(k.y==z){
            cout<<k.step;
            flag=true;
            return;
        }
        if(k.y<y && k.x>0){
            Pos add;
            if(k.x>y-k.y){
                add=Pos(k.x-(y-k.y),y,k.step+1);
                enqueue(add);
            }else{
                add=Pos(0,k.y+k.x,k.step+1);
                enqueue(add);
            }
        }
        if(k.y>0 && k.x<x){
        	Pos add;
        	if(k.y>x-k.x){
        		add=Pos(x,k.y-(x-k.x),k.step+1);
        		enqueue(add);
        	}else{
        		add=Pos(k.y+k.x,0,k.step+1);
        		enqueue(add);
        	}
        }
        if(k.y>0){
            Pos add = Pos(k.x,0,k.step+1);
            enqueue(add);
        }
        if(k.x>0){
            Pos add=Pos(0,k.y,k.step+1);
            enqueue(add);
        }
        if(k.x<x){
            Pos add=Pos(x,k.y,k.step+1);
            enqueue(add);
        }
        if(k.y<y){
            Pos add=Pos(k.x,y,k.step+1);
            enqueue(add);
        }
    }
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
    cin>>x>>y>>z;
    BFS();
    if(!flag){
        puts("No solution!");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}