#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

inline char nextChar(char x){
    return x+1>'z'?'a':x+1;
}

char list[200][200];

void generateList(){
    for(char i='a';i<='z';++i){
        int j=0;
        char k=i;
        while(j<26){
            list[i][k]='a'+j;
            k=nextChar(k);
            ++j;
        }
    }
    /*for(int i='a';i<='z';++i){
    	for(int j='a';j<='z';++j){
    		cout<<list[i][j]<<' ';
    	}
    	puts("");
    }*/
}
char sec[1001];
char key[1001];
int keylen;
inline int nextCur(int x){
    return x+1==keylen?0:x+1;
}

int main(){
    generateList();
    gets(key);
    gets(sec);
    keylen=strlen(key);
    for(int i=0;i<keylen;++i){
    	if(key[i]>='A' && key[i]<='Z')
    		key[i]+=32;
    }
    int cur=0;bool isupper;
    for(int i=0;i<strlen(sec);++i){
        isupper = false;
        if(sec[i]>='A' && sec[i]<='Z'){
            sec[i]+=32;
            isupper=true;
        }
        //cout<<sec[i]<<' '<<key[cur]<<endl;
        char ans = list[key[cur]][sec[i]];
        cur=nextCur(cur);
        if(isupper) ans-=32;
        putchar(ans);
    }
    putchar('\n');
    return 0;
}