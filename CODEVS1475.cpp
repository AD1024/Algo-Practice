#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int list[200];

int po(int n,int t){
    if(t==0){return 1;}
    int rt=1;
    for(int i=1;i<=t;i++){
        rt*=n;
    }
    return rt;
}

int main(){
    char str[10001];
    int n;
    scanf("%s",str);cin>>n;
    stack<char> s;
    for(char i='0';i<='9';i++){
        list[i]=i-'0';
    }
    for(char i='A',j='a';i<='F'&&j<='f';i++,j++){
        list[i]=i-'A'+10;
        list[j]=j-'a'+10;
    }
    int len = strlen(str);
    for(int i=0;i<len;i++){
        s.push(str[i]);
    }
    int res=0,cur=0;
    while(!s.empty()){
        res+=list[s.top()]*po(n,cur);
        cur++;
        s.pop();
    }
    cout<<res;
    return 0;
}
