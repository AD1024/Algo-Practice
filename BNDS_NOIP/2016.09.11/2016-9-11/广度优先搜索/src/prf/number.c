#include<stdio.h>
char s[10001][10]={'\0'},s1[10]={'\0'};
int p[10001]={0},fl[400000]={0},step[10001]={0},flag=1,point=0,q[10001]={0};
int jc(int n)
{
    if(n==1) return 1;
    return n*jc(n-1);
}
int tm(char a[])
{
    int ans=0,i,j,x=0;
    for(i=0;i<8;i++)
    {
       for(j=i+1,x=0;j<9;j++) 
          if(a[i]>a[j]) x++;
       ans+=x*jc(8-i);
    }
    return ans+1;
}
int check(int i,int t)
{
    if(i==0)
    {
        if(t>=3) return 1;
        return 0;
    }
    if(i==1)
    {
        if(t<=5) return 1;
        return 0;
    }
    if(i==2)
    {
        if(t%3==0) return 0;
        return 1;    
    }
    if(i==3)
    {
        if(t%3==2) return 0;
        return 1;
    }
}
int exchange(int i,char a[],int t)
{
    if(i==0) {a[t]=a[t-3];a[t-3]='0';return t-3;} 
    if(i==1) {a[t]=a[t+3];a[t+3]='0';return t+3;} 
    if(i==2) {a[t]=a[t-1];a[t-1]='0';return t-1;} 
    if(i==3) {a[t]=a[t+1];a[t+1]='0';return t+1;}     
}
void bfs()
{
    int i,j,f=0,r=1,t=0,k=0,x;
    char stl[10]={'\0'};
    fl[tm(s[0])]=1;
    while(f!=r&&step[r-1]<=100)
    {
        t=q[f];f++;
        for(i=0;i<4;i++)
           if(check(i,p[t]))
           {   
               strcpy(stl,s[t]);
               k=exchange(i,stl,p[t]);               
               if(strcmp(stl,s1)==0) 
               {flag=0;printf("%d",step[t]+1);return;}
               x=tm(stl);          
               if(fl[x]==0)
               {            
                   point++;
                   q[r++]=point;
                   strcpy(s[point],stl);
                   p[point]=k;
                   fl[x]=1;
                   step[point]=step[t]+1;
               }               
           }
    }
}
int main()
{    
    int i;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(i=0;i<9;i+=3) scanf("%c %c %c\n",&s[0][i],&s[0][i+1],&s[0][i+2]);
    for(i=0;i<9;i+=3) scanf("%c %c %c\n",&s1[i],&s1[i+1],&s1[i+2]);
    for(i=0;i<9;i++) if(s[0][i]=='0') p[0]=i;
    step[0]=0;
    q[0]=0;
    bfs();
    if(flag) printf("-1");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
