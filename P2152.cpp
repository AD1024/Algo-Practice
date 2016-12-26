#include <cstdio>  
#include <cstring>  
#include <algorithm>
#include <iostream>
using namespace std;  
  
  
const int power = 1;      //每次运算的位数为10的power次方，在这里定义为了方便程序实现  
const int base = 10;      //10的power次方。  
  
  
//要压位的时候，只需改power 和 base即可，如压万位高精，那么power = 4, base = 10000  
  
  
const int MAXL = 10001;    //数组的长度。  
  
  
char a[MAXL], b[MAXL];  
struct num  {  
    int a[MAXL];  
    num() { memset(a, 0, sizeof(a)); }                      //初始化  
    num(char *s){
        memset(a, 0, sizeof(a));  
        int len = strlen(s);  
        a[0] = (len+power-1) / power;                       //数的长度  
        for (int i=0, t=0, w; i < len ;w *= 10, ++i)          
        {  
            if (i % power == 0) { w = 1, ++t; }  
            a[t] += w * (s[i]-'0');  
        }   
    }  
    void add(int k) { if (k || a[0]) a[ ++a[0] ] = k; }     //在末尾添加一个数，除法的时候要用到  
    void re() { reverse(a+1, a+a[0]+1); }                   //把数反过来，除法的时候要用到  
    void print(){  
        printf("%d", a[ a[0] ]);        
        //先打印最高位，为了压位 或者 该高精度数为0 考虑  
        for (int i = a[0]-1;i > 0;--i)  
        printf("%0*d", power, a[i]);    
        //这里"%0*d", power的意思是，必须输出power位，不够则前面用0补足  
        printf("\n");  
    }  
} p,q,ans;  
  
  
bool operator < (const num &p, const num &q){  
    if (p.a[0] < q.a[0]) return true;  
    if (p.a[0] > q.a[0]) return false;  
    for (int i = p.a[0];i > 0;--i)  
    {  
        if (p.a[i] != q.a[i]) return p.a[i] < q.a[i];  
    }  
    return false;  
}  
  
  
num operator + (const num &p, const num &q){  
    num c;  
    c.a[0] = max(p.a[0], q.a[0]);  
    for (int i = 1;i <= c.a[0];++i)  
    {  
        c.a[i] += p.a[i] + q.a[i];  
        c.a[i+1] += c.a[i] / base;  
        c.a[i] %= base;  
    }  
    if (c.a[ c.a[0]+1 ]) ++c.a[0];  
    return c;  
}  
  
  
num operator - (const num &p, const num &q){  
    num c = p;  
    for (int i = 1;i <= c.a[0];++i)  
    {  
        c.a[i] -= q.a[i];  
        if (c.a[i] < 0) { c.a[i] += base; --c.a[i+1]; }  
    }  
    while (c.a[0] > 0 && !c.a[ c.a[0] ]) --c.a[0];            
    return c;  
}  
  
  
num operator * (const num &p, const num &q){  
    num c;  
    c.a[0] = p.a[0]+q.a[0]-1;  
    for (int i = 1;i <= p.a[0];++i)  
    for (int j = 1;j <= q.a[0];++j)  
    {  
        c.a[i+j-1] += p.a[i]*q.a[j];  
        c.a[i+j] += c.a[i+j-1] / base;  
        c.a[i+j-1] %= base;  
    }  
    if (c.a[ c.a[0]+1 ]) ++c.a[0];  
    return c;  
}  
  
  
num operator / (const num &p, const num &q)               //除法，这里我稍微讲解一下  
{  
    num x, y;  
    for (int i = p.a[0];i >= 1;--i)                       //从最高位开始取数  
    {  
        y.add(p.a[i]);             //把数添到末尾（最低位），这时候是高位在前，低位在后  
        y.re();                    //把数反过来，变为统一的存储方式：低位在前，高位在后  
        while ( !(y < q) )         //大于等于除数的时候，如果小于的话，其实答案上的该位就是初始的“0”  
            y = y - q, ++x.a[i];   //看能减几个除数，减几次，答案上该位就加几次。  
        y.re();                    //将数反过来，为下一次添数做准备  
    }  
    x.a[0] = p.a[0];  
    while (x.a[0] > 0 && !x.a[x.a[0]]) --x.a[0];  
    return x;  
}

num operator % (const num& a,const num& b){
  num c=a/b;
  return a-b*c;
} 

bool operator ==(const num& a,char str[]){
  if(a.a[0]!=strlen(str)) return false;
  int cur=a.a[0]-1;
  for(int i=cur;i>=1;++i){
    if(a.a[i]!=str[i]-'0') return false;
  }
  return true;
}

int main(){
  char str1[10001];
  char str2[10001];
  gets(str1);
  gets(str2);
  num a=num(str1);
  num b=num(str2);
  num r;
  char zero[2]={'0','0'};
  while(!(b==zero)){
    r=a%b;
    a=b;
    b=r;
  }
  a.print();
  return 0;
}