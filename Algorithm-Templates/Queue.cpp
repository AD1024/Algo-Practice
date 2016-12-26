#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
using namespace std;
#define SIZE 10000
struct Queue{
    int f,t;
    int a[10001];
    int k;
    
    Queue(){
        f=t=0;
        k=0;
    }
    void push(int x){
        if(t+1>SIZE && f==0){
            return;
        }else if(t+1>SIZE){
            a[t]=x;
            t=0;
        }else{
            a[t++]=x;
        }
        ++k;
    }
    int front(){
        return a[f];
    }
    void pop(){
        if(f!=t){
            f++;
            --k;
            if(f>SIZE) f=0;
        }
    }
    int size(){
       return k;
    }
};

int main(){
    Queue q;
    for(int i=0;i<10;++i) q.push(i);
    while(q.size()){
        cout<<q.front()<<' ';
        q.pop();
    }
    return 0;
}