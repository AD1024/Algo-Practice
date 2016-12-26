#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

#define RAND rand()

struct Node{
    int value;
    Node* rson;
    Node* lson;
    int fix;
    int size;
    inline int lsize(){
        return lson?lson->size:0;
    }
    inline int rsize(){
        return rson?rson->size:0;
    }
};

Node* T;

inline void init(){
    srand(19260817);
}

inline void left_rot(Node* &a){
    Node* b=a->rson;
    a->rson=b->lson;
    b->lson=a;
    a=b;
}

inline void right_rot(Node* &a){
    Node* b=a->lson;
    a->lson=b->rson;
    b->rson=a;
    a=b;
}

inline void insert(Node* &P,int v){
    if(P==NULL){
        P=(Node*)malloc(sizeof(Node));
        P->rson=NULL;
        P->lson=NULL;
        P->value=v;
        P->fix=RAND;
    }else if(v<=P->value){
        insert(P->lson,v);
        if(P->fix > P->lson->fix){
            right_rot(P);
        }
    }else{
        insert(P->rson,v);
        if(P->fix > P->rson->fix){
            left_rot(P);
        }
    }
}

inline void inorder(Node* P){
    if(P->lson) inorder(P->lson);
    cout<<P->value<<" ";
    if(P->rson) inorder(P->rson);
}

inline void __Remove(Node* P,int v){
    if(!P) return;
    if(P->value==v){
        if(!P->lson || !P->rson){
            Node *t=P;
            if(!P->lson){
                P=P->rson;
            }else{
                P=P->lson;
            }
            free(t);
        }else{
            if(P->lson->fix<P->rson->fix){
                right_rot(P);
                __Remove(P->rson,v);
            }else{
                left_rot(P);
                __Remove(P->lson,v);
            }
        }
    }else{
        if(v<P->value){
            __Remove(P->lson,v);
        }else __Remove(P->rson,v);
    }
}
bool found=false;
inline void search(Node* P,int v,int step){
    if(P==NULL) return;
    if(P->value==v){
        found=true;
        puts("Found");
        cout<<"Step:"<<step;
        return;
    }
    if(found) return;
    if(v<=P->value){
        search(P->lson,v,step+1);
    }else{
        search(P->rson,v,step+1);
    }
}

int main(){
    init();
    int v;
    int q;
    while(cin>>q && q){
        found=false;
        switch(q){
            case 1:{
                cin>>v;
                insert(T,v);
                break;
            }
            case 2:{
                inorder(T);
                break;
            }
            case 3:{
                cin>>v;
                __Remove(T,v);
                break;
            }
            case 4:{
                cin>>v;
                search(T,v,0);
                break;
            }
        }
    }
}