/*************************************************************************
	> File Name: LinkList.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Oct 2016 11:30:20 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define null NULL

struct Node{
    int data;
    Node* Next;
};

Node *head;
Node *tail;
int tot=0;
inline void Tail_Insert(int v){
    ++tot;
    Node* q=(Node*)malloc(sizeof(Node));
    q->data=v;q->Next=null;
    if(tail==null){
        head->Next=q;
        q->Next=null;
        tail=q;
    }else{
        q->Next=tail->Next;
        tail->Next=q;
        tail=q;
    }
}

inline void Head_Insert(int v){
    ++tot;
    Node* q=(Node*)malloc(sizeof(Node));
    q->data=v;q->Next=null;
    if(head->Next==null){
        head->Next=q;
        tail=q;
        q->Next=null;
    }else{
        q->Next=head->Next;
        head->Next=q;
    }
}

inline void Insert(int idx,int data){
    ++tot;
    Node* cur=head->Next;
    for(int i=1;i<idx;++i){
        cur=cur->Next;
    }
    Node* q=(Node*)malloc(sizeof(Node));
    q->data=data;q->Next=cur->Next;
    cur->Next=q;
}

inline void Remove(int idx){
    --tot;
    Node* cur=head->Next;
    for(int i=2;i<idx;++i) cur=cur->Next;
    Node* del=cur->Next;
    cur->Next=del->Next;
    free(del);
}
inline void Pop_Head(){
    --tot;
    Node* del=head->Next;
    head->Next=del->Next;
    free(del);
}
inline void Pop_Tail(){
    --tot;
    Node* cur=head->Next;
    while(cur->Next->Next!=null){
        cur=cur->Next;
    }
    Node* del=cur->Next;
    free(del);
    cur->Next=null;
    tail=cur;
}

inline void Traverse(){
    Node* cur=head->Next;
    while(cur!=null){
        printf("%d ",cur->data);
        cur=cur->Next;
    }
}

int main(){
    //head->Next=null;
    //tail=null;
    head=(Node*)malloc(sizeof(Node));
    head->Next=null;
    int N,M;
    cin>>N>>M;
    int op,v;
    while(M--){
        cin>>op;
        switch(op){
            case 1:{
                cin>>v;
                Head_Insert(v);
                break;
            }
            case 2:{
                cin>>v;
                Tail_Insert(v);
                break;
            }
            case 3:{
                int idx;cin>>idx>>v;
                if(idx>=tot){
                    Tail_Insert(v);
                }else{
                    Insert(idx,v);
                }
                break;
            }
            case 4:{
                cin>>v;
                if(v<=tot){
                    Remove(v);
                }else if(tot>0){
                    Pop_Tail();
                }
                break;
            }
            case 5:{
                if(tot>0){
                    Pop_Head();
                }
                break;
            }
            case 6:{
                if(tot>0){
                    Pop_Tail();
                }
                break;
            }
            case 7:{
                Traverse();
                putchar('\n');
                break;
            }
        }
    }
}