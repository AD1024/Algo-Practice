#include<stdio.h>
int fl[50000]={0},flag=1;
int q[1000000]={0},f=0,r=1,step[1000000]={0},point=1;
int jc[10]={0,1,2,6,24,120,720,5040,40320};
char s1[9]="12348765\0",s[1000000][9]={'\0'};
int tm(char a[])
{
    int ans=0,i,j,x=0;
    for(i=0;i<7;i++)
    {
       for(j=i+1,x=0;j<8;j++) 
          if(a[i]>a[j]) x++;
       ans+=x*jc[8-i];
    }
    return ans+1;
}
void exchange(int i,char a[],int t)
{
    char x,y;
    int j;
    if(i==0) for(j=0;j<4;j++) {x=a[j];a[j]=a[j+4];a[j+4]=x;}
    if(i==1)
    {
        x=a[3];y=a[7];
        for(j=2;j>=0;j--) {a[j+1]=a[j];a[j+5]=a[j+4];}
        a[0]=x;a[4]=y;
    }
    if(i==2) {x=a[1];a[1]=a[5];a[5]=a[6];a[6]=a[2];a[2]=x;}
}
void bfs()
{
    int i,t,k;
    char stl[9];
    while(step[r-1]<=100000&&f!=r)
    {
        t=q[f];f++;
        for(i=0;i<3;i++)
        {
           strcpy(stl,s[t]);
           exchange(i,stl,t);
           k=tm(stl);
           if(strcmp(stl,s1)==0) {flag=0;printf("%d",step[t]+1);return;}
           if(fl[k]==0)
           {
               fl[k]=1;
               strcpy(s[point],stl);
               q[r]=point++;
               step[r]=step[t]+1;
               r++;
           }
        }
    } 
}
int main()
{
    int i;
    freopen("act.in","r",stdin);
    freopen("act.out","w",stdout);
    for(i=0;i<8;i+=4)
       scanf("%c %c %c %c\n",&s[0][i],&s[0][i+1],&s[0][i+2],&s[0][i+3]);
    step[0]=0;fl[tm(s[0])]=1;q[0]=0;
    bfs();
    if(flag) printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
