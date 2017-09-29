#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define pc(x) putchar(x)
int N;

inline void pthd(bool header){
    pc('+');
    for(int i=2;i<=6;++i){
        pc('-');
    }
    pc('+');
    header?pc('\n'):header;
}

int main(){
    cin>>N;
    int K = N / 20;
    pthd(1);
    for(int _=5;_>=1;--_){
        pc('|');
        if(_ == 5){
            int cnt = 4;
            if(N >= 20){
                --cnt;
                pc('-');
            }
            if(N >= 60) --cnt;
            for(int i=1;i<=cnt;++i){
                pc(' ');
            }
            if(N >= 90){
                printf("4G");
            }else if(N >= 60){
                printf("3G");
            }else{
                printf("E");
            }
        }else{
            int cnt = 5;
            if(N >= (6-_)*20){
                for(int i=1;i<=6-_;++i){
                    pc('-');
                    --cnt;
                }
            }
            for(int i=1;i<=cnt;++i){
                pc(' ');
            }
        }
        pc('|');pc('\n');
    }
    pthd(0);
    return 0;
}