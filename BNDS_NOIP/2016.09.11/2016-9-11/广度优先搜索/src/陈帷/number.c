#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[100000][9]={{'\0'}},z[9]={'\0'},z1[9]={'\0'};
int b[100000]={0},i=0,f=0,r=1;
void jh(int c)
{
     char d;
     int e;
     for(e=0;e<9;e++)
       a[r][e]=a[f][e];
     b[r]=b[f];
     if(c==0)
     {
       d=a[r][b[r]-3],a[r][b[r]-3]=a[r][b[r]],a[r][b[r]]=d;
       b[r]-=3;
       for(e=0;e<r;e++)
         if(strstr(a[r],a[e]))
           {strcpy(a[r],z1),b[r]=0,i--;return;}
     }
     else if(c==1)
     {
       d=a[r][b[r]],a[r][b[r]]=a[r][b[r]-1],a[r][b[r]-1]=d;
       b[r]-=1;
       for(e=0;e<r;e++)
         if(strstr(a[r],a[e]))
           {strcpy(a[r],z1),b[r]=0,i--;return;}
     }
     else if(c==2)
     {
       d=a[r][b[r]],a[r][b[r]]=a[r][b[r]+3],a[r][b[r]+3]=d;
       b[r]+=3;
       for(e=0;e<r;e++)
         if(strstr(a[r],a[e]))
           {strcpy(a[r],z1),b[r]=0,i--;return;}
     }
     else if(c==3)
     {
       d=a[r][b[r]],a[r][b[r]]=a[r][b[r]+1],a[r][b[r]+1]=d;
       b[r]+=1;
       for(e=0;e<r;e++)
         if(strstr(a[r],a[e]))
           {strcpy(a[r],z1),b[r]=0,i--;return;}
     }
     if(strstr(a[r],z))
       {printf("%d",i);return;}
     r++;
}
int pd(int c)
{
    int d;
    if(c==0)
      if(b[c]>=6) return 0;
    else if(c==1)
      if(b[c]!=2&&b[c]!=5&&b[c]!=8) return 0;
    else if(c==2)
      if(b[c]>=3) return 0;
    else if(c<=3)
      if(b[c]!=0&&b[c]!=3&&b[c]!=6) return 0;
    return 1;
}
void qwe()
{
     int c,d=0;
     do
     {
       i++;
       for(c=0;c<=3;c++)
         if(pd(c))
           jh(c);
       f++;
       if(i>100)
       {
         printf("-1");
         return;
       }
     }while(f<r);
}
int main()
{
    int c,g;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(c=0;c<9;c++)
    {
      scanf("%d",&g);
      a[0][c]=g+'0';
      if(a[0][c]=='0')
        b[0]=c;
    }
    for(c=0;c<9;c++)
    {
      scanf("%d",&g);
      z[c]=g+'0';
    }
    qwe();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
