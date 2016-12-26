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
void Tail_Insert(int v); // Insert to the tail
void Head_Insert(int v); // Insert to the head
void Insert(int idx,int v); // Insert to idx(2<=idx<=tot)
void Remove(int idx); // Remove the element on idx
void Pop_Tail();  // Remove the element of the tail
void Pop_Head();  // Remove the element after the head
void Traverse();  // Print the data from head to tail
void OutN(int idx);
int main(){
  freopen("input.in","r",stdin);
  freopen("input.out","w",stdout);
    //head->Next=null;
    //tail=null;
    head=(Node*)malloc(sizeof(Node));
    head->Next=null;
    int N,M;
    cin>>M;
    int op,v;
    while(M--){
        cin>>op;
        switch(op){
            case 1:{
                cin>>v;
                Tail_Insert(v);
                break;
            }
            case 2:{
                if(tot>0){
                    Pop_Tail();
                }
                break;
            }
            case 3:{
                cin>>v;
                Head_Insert(v);
                break;
            }
            case 4:{
                if(tot>0) Pop_Head();
                break;
            }
            case 5:{
                int idx;cin>>idx>>v;
                if(idx>=tot){
                    Tail_Insert(v);
                }else{
                    Insert(idx,v);
                }
                break;
            }
            case 6:{
                cin>>v;
                if(v<=tot){
                    Remove(v);
                }else if(tot>0){
                    Pop_Tail();
                }
                break;

            }
            case 7:{
                int idx;cin>>idx;
                if(idx>tot){
                    puts("-1");
                }else{
                    OutN(idx);
                }
                break;
            }
            case 8:{
              if(tot>0){
                Traverse();
                putchar('\n');
              }else{
                puts("-1");
              }
                break;
            }
        }
    }
}

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
    if(cur->Next==NULL){
      head->Next=NULL;
      free(cur);
      return;
    }
    for(int i=2;i<idx;++i) cur=cur->Next;
    Node* del=cur->Next;
    cur->Next=del->Next;
    free(del);
}
inline void Pop_Head(){
    --tot;
    Node* del=head->Next;
    if(del==NULL) return;
    if(del->Next==NULL){
      head->Next=NULL;
      free(del);return;
    }
    head->Next=del->Next;
    free(del);
}
inline void Pop_Tail(){
    --tot;
    Node* cur=head->Next;
    if(cur==NULL) return;
    if(cur->Next==NULL){
      head->Next=NULL;
      free(cur);
      return;
    }
    while(cur->Next->Next!=null && cur->Next!=NULL){
        cur=cur->Next;
    }
    Node* del=cur->Next;
    free(del);
    cur->Next=null;
    tail=cur;
}

inline void OutN(int idx){
    Node * cur=head->Next;
    for(int i=1;i<idx;++i){
        cur=cur->Next;
    }
    cout<<cur->data<<endl;
}

inline void Traverse(){
    Node* cur=head->Next;
    while(cur!=null){
        printf("%d ",cur->data);
        cur=cur->Next;
    }
}
