#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 100010;

int Next[MAXN];
int CASE=1;
int len;

char str[10001];

inline int MIN(int x,int y){
    return x>y?y:x;
}
inline int MAX(int x,int y){
    return x>y?x:y;
}

inline void exKMP(){
    int c=0;
    int i;
    Next[0]=len;
    while(c+1<len && str[c]==str[c+1]){
        ++c;
    }
    Next[1]=c;
    c=1;
    int maxn;
    int L;
    int P;
    for(int i=2;i<len/2;++i){
        maxn=c+Next[c]-1;
        L=Next[i-c];
        P=MAX(maxn-i+1,0);
        Next[i]=MIN(L,P);
        while(Next[i]+i<len && str[Next[i]]==str[i+Next[i]]){
            ++Next[i];
        }
        if(Next[i]+i>c+Next[c]) {
            c=i;
        }
    }
}


inline void getNext(){
    int l=len;
    int i=0,j=-1;
    Next[0]=-1;
    while(i<l){
        if(j==-1 || str[j]==str[i]){
            Next[++i]=(++j);
        }else
            j=Next[j];
    }
}


inline void init(){
    scanf("%s",str);
    len=strlen(str);
}

inline void work(){
    getNext();
    int zz;
    if(len%(len-Next[len])==0){
        zz=len/(len-Next[len]);
    }else{
        zz=1;
    }
    char strt[MAXN];
    strcpy(strt,str);
    strcat(str,strt);
    len<<=1;
    exKMP();
    int eq,gt,lt;
    eq=gt=lt=0;
    len>>=1;
    for(int i=0;i<len;i++){
        if(Next[i]>=len) ++eq;
        else if(str[i+Next[i]]>str[Next[i]]) ++gt;
        else ++lt;
    }
    printf("Case %d: %d %d %d\n",CASE++,lt/zz,eq/zz,gt/zz);
}

int main(){
	int T;
    cin>>T;
    while(T--){
        init();
        work();
    }
    return 0;
}