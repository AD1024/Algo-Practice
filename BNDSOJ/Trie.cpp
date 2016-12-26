#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define null NULL

struct Node{
    char x;
    bool upper;
    Node* son[100];
    bool EOW;
    Node(){
        EOW=false;
    }
};

int dist[27][27]={0};

Node *root;

inline bool isupper(char x){
    return x>='A' and x<='Z';
}

inline bool isLower(char x){
    return x>='a' and x<='z';
}

inline int parse(char x){
    if(isupper(x)) return x-'A';
    else if(isLower(x)) return x-'a';
    else return -1;
}

inline Node* newNode(char ch){
    Node* k = (Node*)malloc(sizeof(Node));
    k->x=ch;
    k->upper=isupper(ch);
    for(int i=0;i<26;++i) k->son[i]=null;
    return k;
}

inline void __init__(){
    root = newNode('#');
}

inline void Extend(Node *ptr,string suff){
    if(ptr->EOW){
        cout<<suff<<" ";return;
    }
    Node* cur=ptr;
    for(int i=0;i<26;++i){
        if(cur->son[i]!=null){
            Extend(cur->son[i],suff+cur->son[i]->x);
        }
    }
}

inline void Find(const char str[],int length){
    Node* p = root;
    string suffix="";
    bool fin=false;//bool found=false;
    for(int i=0;i<length;++i){
        if(p->son[parse(str[i])]==null){
            if(i==0) return;
            for(int j=0;j<26;++j){
                if(p->son[j]!=null){
                    if(p->son[j]->EOW){
                        string ep=suffix+char((j+'a'));
                        cout<<ep<<" ";
                    }else{
                        Extend(p,suffix);
                    }
                }
            }
            break;
        }else{
            suffix+=str[i];
        }
        p=p->son[parse(str[i])];
        if(p->EOW) fin=true;
    }
    if(!fin){
        Extend(p, suffix);
    }
}

inline void Insert(const char str[],int length){
    Node* p=root;
    for(int i=0;i<length;++i){
        if(p->son[parse(str[i])]==null){
            int idx=parse(str[i]);
            p->son[idx]=newNode(str[i]);
        }
        p=p->son[parse(str[i])];
    }
    p->EOW=true;
}

int main(){
    __init__();
    string x;
    while(cin>>x){
        if(x=="-") break;
        Insert(x.c_str(),x.length());
    }
    while(cin>>x){
        cout<<x<<" ";
        Find(x.c_str(),x.length());
        putchar('\n');
    }
    return 0;
}