#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

#define MAXN 100001

stack<char> op;
stack<double> num;
char a[MAXN];

inline bool gt(char a,char b){
    if(a=='#') return true;
    if(b=='(') return false;
    if(a=='(') return false;
    if(b==')') return false;
    if(a==')') return true;
    if((a=='*' || a=='/') && (b=='+' || b=='-')){
        return false;
    }else if((a=='+' || a=='-') && (b=='*' || b=='/')){
        return true;
    }else return true;
}

int main(){
    cin>>a;
    op.push('#');
    a[strlen(a)]='#';
    for(int i=0;i<strlen(a);){
        if(isdigit(a[i])){
            num.push((double)a[i]-'0');
            ++i;
        }else if(op.size()>1){
            if(gt(a[i],op.top())){
                double k=num.top();num.pop();
                double j=num.top();num.pop();
                switch(op.top()){
                    case '+':{
                        num.push(k+j);
                        break;
                    }
                    case '-':{
                        num.push(j-k);break;
                    }
                    case '*':{
                        num.push(j*k);break;
                    }
                    case '/':{
                        num.push(j/k);break;
                    }
                }
                op.pop();
            }else{
                if(op.top()=='(' && a[i]==')'){
                    op.pop();
                }else{
                    op.push(a[i]);
                }
                ++i;
            }
        }else{
            op.push(a[i]);++i;
        }
    }
    printf("%.2f",num.top());
    return 0;
}