#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char key[100001];
char str[100001];
char g[28][28];
char list[28][28];

int klen,slen;

inline char NextChar(char s){
    return s=='z'?'a':s+1;
}

inline int NextCur(int x){
    return x==klen-1?0:x+1;
}

inline void init(){
    char s='a';
    char k;
    for(int i=0;i<26;++i){
        k=s;
        for(int j=0;j<26;++j){
            g[i][j]=k;
            k=NextChar(k);
        }
        ++s;
    }
    for(int i=0;i<26;++i){
        for(int j=0;j<26;++j){
            list[i][g[i][j]-'a']=j+'a';
        }
    }
}

inline bool isUpper(char x){
    if(x>='A' && x<='Z') return 1;
    else return 0;
}

int main(){
    init();
    cin>>key;
    cin>>str;
    klen=strlen(key);
    slen=strlen(str);
    for(int i=0;i<klen;++i){
        if(isUpper(key[i])){
            key[i]+=32;
        }
    }
    int cur=0;
    char out;
    bool idx;
    for(int i=0;i<slen;++i){
        idx=isUpper(str[i]);
        if(idx){
            str[i]+=32;
        }
        out=list[key[cur]-'a'][str[i]-'a'];
        cur=NextCur(cur);
        if(idx){
            printf("%c",toupper(out));
        }else{
            printf("%c",out);
        }
    }
    return 0;
}