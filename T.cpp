#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#define INF 999999999
using namespace std;

const int MAX=100000+10;
char s[MAX*2];
int Next[MAX];

void get_next(char *a,int len){
    int i=-1,j=0;
    Next[0]=-1;
    while(j<len){
        if(i == -1 || a[i] == a[j])Next[++j]=++i;
        else i=Next[i];
    }
}

void get_extend(char *a,int len){
    int k=0,i=1;
    Next[0]=len;
    while(k+1<len && a[k] == a[k+1])++k;
    Next[1]=k;
    k=1;
    while(++i<len/2){//只需要求到原串的长度即可
        int maxr=k+Next[k]-1;
        Next[i]=min(Next[i-k],max(maxr-i+1,0));
        while(i+Next[i]<len && a[Next[i]] == a[i+Next[i]])++Next[i];
        if(i+Next[i]>k+Next[k])k=i;
    }
}

int main(){
    int t,num=0;
    cin>>t;
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        get_next(s,len);
        int temp=len%(len-Next[len]) == 0?len/(len-Next[len]):1;//求循环节循环了几次
        for(int i=0;i<=len;++i)s[i+len]=s[i];
        get_extend(s,len+len);
        int a=0,b=0,c=0;
        for(int i=0;i<len;++i){
            if(Next[i]>=len)++b;//表示等于原串的
            else if(s[Next[i]]<s[i+Next[i]])++c;//表示大于原串的
            else ++a;//表示小于原串的
        }
        cout<<"Case "<<++num<<": "<<a/temp<<' '<<b/temp<<' '<<c/temp<<endl;
    }
    return 0;
}