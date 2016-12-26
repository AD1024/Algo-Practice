#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N;

#define lowbit(x) x&(-x)
inline int compare(string str1, string str2){  
      if(str1.size() > str2.size())
            return 1;  
      else if(str1.size() < str2.size())  
            return -1;  
      else  
            return str1.compare(str2);
}  
string fib[100010]={"0","1","1","2"};
inline string add(string s1,string s2){
    int i,j,sum=0;
    if(s1.length()<s2.length())
        swap(s1,s2);
    for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--){
        sum+=s1[i]-'0';
        if(j>=0) sum+=s2[j]-'0';
           s1[i]=sum%10+'0';
        sum/=10;
    }
    if(sum){
        s1='1'+s1;
    }
    return s1;
}
inline string sub(string str1,string str2){
    string str;
    int tmp=str1.length()-str2.length();
    int cf=0;
    for(int i=str2.length()-1;i>=0;i--){
        if(str1[tmp+i]<str2[i]+cf){
            str=char(str1[tmp+i]-str2[i]-cf+'0'+10)+str;
            cf=1;
        }
        else{
            str=char(str1[tmp+i]-str2[i]-cf+'0')+str;
            cf=0;
        }
    }
    for(int i=tmp-1;i>=0;i--){
        if(str1[i]-cf>='0'){
            str=char(str1[i]-cf)+str;
            cf=0;
        }
        else{
            str=char(str1[i]-cf+10)+str;
            cf=1;
        }
    }
    str.erase(0,str.find_first_not_of('0'));
    return str;
}
  
inline string mul(string str1, string str2){ 
     int sign = 1;
     string str;  
     if(str1[0] == '-') {  
           sign *= -1;  
           str1 = str1.erase(0, 1);  
     }  
     if(str2[0] == '-') {  
           sign *= -1;  
           str2 = str2.erase(0, 1);  
     }  
     int i, j;  
     string::size_type l1, l2;  
     l1 = str1.size(); l2 = str2.size();  
     for(i = l2 - 1; i >= 0; i --) {
           string tempstr;  
           int int1 = 0, int2 = 0, int3 = int(str2[i]) - 48;  
           if(int3 != 0) {  
                  for(j = 1; j <= (int)(l2 - 1 - i); j++)  
                        tempstr = "0" + tempstr;  
                  for(j = l1 - 1; j >= 0; j--) {  
                        int1 = (int3 * (int(str1[j]) - 48) + int2) % 10;  
                        int2 = (int3 * (int(str1[j]) - 48) + int2) / 10;  
                        tempstr = char(int1 + 48) + tempstr;  
                  }  
                  if(int2 != 0) tempstr = char(int2 + 48) + tempstr;  
           }  
           add(str, tempstr);  
     }  
     str.erase(0, str.find_first_not_of('0'));  
     if(str.empty()) str = "0";  
     if((sign == -1) && (str[0] != '0'))  
           str = "-" + str;  
     return str;  
}

inline string Div(string str1, string str2, int flag)  
{  
     //flag = 1时,返回商; flag = 0时,返回余数  
     string quotient, residue;
     int sign1 = 1, sign2 = 1;  
     if(str1[0] == '-') {  
           str1 = str1.erase(0, 1);  
           sign1 *= -1;  
           sign2 = -1;  
     }  
     if(str2[0] == '-') {  
           str2 = str2.erase(0, 1);  
           sign1 *= -1;  
     }  
     int res = compare(str1, str2);  
     if(res < 0) {  
           quotient = "0";  
           residue = str1;  
     }else if(res == 0) {  
           quotient = "1";  
           residue = "0";  
     }else {  
           string::size_type l1, l2;  
           l1 = str1.size(); l2 = str2.size();  
           string tempstr;  
           tempstr.append(str1, 0, l2 - 1);   
           for(int i = l2 - 1; i < l1; i++) {  
                 tempstr = tempstr + str1[i];  
                 for(char ch = '9'; ch >= '0'; ch --) {
                       string str;  
                       str = str + ch;  
                       if(compare(mul(str2, str), tempstr) <= 0) {  
                              quotient = quotient + ch;  
                              tempstr = sub(tempstr, mul(str2, str));  
                              break;  
                       }  
                 }  
           }  
           residue = tempstr;  
     }    
     quotient.erase(0, quotient.find_first_not_of('0'));  
     if(quotient.empty()) quotient = "0";  
     if((sign1 == -1) && (quotient[0] != '0'))  
     quotient = "-" + quotient;  
     if((sign2 == -1) && (residue[0] != '0'))  
     residue = "-" + residue;  
     if(flag == 1) return quotient;  
     else return residue;  
}

string T[100010];


inline void add(int k,string num){
    while(k<=N){
        T[k]=add(T[k],num);
        k+=lowbit(k);
    }
}

inline string sum(int x){
    string sum="0";
    while(x>0){
        sum=add(sum,T[x]);
        x-=lowbit(x);
    }
    return sum;
}

inline string query(int l,int r){
    return sub(sum(r),sum(l-1));
}
int q;
int main(){
    ios::sync_with_stdio(false);
    string MOD = "1000000009";
    cin>>N>>q;
    string k;
    for(int i=0;i<=N;++i) T[i]="0";
    for(int i=1;i<=N;++i){
        cin>>k;
        add(i,k);
    }
    for(int i=3;i<=N;++i){
    	fib[i]=add(fib[i-1],fib[i-2]);
    }
    int cmd;
    int a,b;
    while(q--){
        scanf("%d%d%d",&cmd,&a,&b);
        if(cmd==1){
            for(int i=a;i<=b;++i){
                add(i,fib[i-a+1]);
            }
        }else{
            cout<<Div(query(a,b),MOD,0)<<"\n";
        }
    }
    return 0;
}