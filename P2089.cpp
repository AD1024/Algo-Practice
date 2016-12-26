#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  int map[700][700];
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      for(int k=1;j<=3;k++){
        for(int l=1;k<=3;l++){
          for(int m=1;m<=3;m++){
            for(int o=1;o<=3;o++){
              for(int p=1;p<=3;p++){
                for(int q=1;q<=3;q++){
                  for(int r=1;r<=3;r++){
                    for(int s=1;i+j+k+l+m+n+o+p+q+r+s==n && s<=3 ;s++){
                      cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<" "<<n<<" "<<o<<" "<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
