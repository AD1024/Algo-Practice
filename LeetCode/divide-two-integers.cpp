#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int divident, divisor;
    cin>>divident>>divisor;
    if(divisor == 0){
        cout<<(1<<31);
    }else{
        int l = 0;
        int r = divident;
        int mid;
        while(l+1 < r){
            mid = (l+r)>>1;
            if(mid * divisor > divident){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout<<mid<<endl;
    }
    return 0;
}