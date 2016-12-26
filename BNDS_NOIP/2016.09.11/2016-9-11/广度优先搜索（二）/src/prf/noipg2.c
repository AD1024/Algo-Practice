#include<stdio.h>
#include<string.h>
char a[7][45]={'\0'},b[7][45]={'\0'},s[1000000][45]={'\0'};
int flag=1,n;
int q[1000000]={0},f=0,r=1,point=1,step[1000000]={0};
int check(int i,int t)
{
    int j,k;
    char stl[24]={'\0'};
    for(j=0;j<strlen(s[t]);j++)
       for(k=0;k<strlen(a[i]);k++)
          if(s[t][j]==a[i][k])
          {
              if(k==strlen(a[i])-1) return j-k;
              else j++;
          }
          else {j=j-k;break;}
    return -1;
}
void exchange(int i,int t,int p,char stl[])
{
    int j,l1=strlen(a[i]),l2=strlen(b[i]),l=strlen(stl); 
    if(l1>=l2) 
    {
        for(j=p+l1;j<l;j++) stl[j-l2+1]=stl[j];
        for(j=j-l2+1;j<45;j++) stl[j]='\0';
    }
    else 
    {
        for(j=p+l1;j<l;j++) stl[j]=stl[j+l2-1];
        for(j=j+l2;j<45;j++) stl[j]='\0';
    }
    for(j=p;j<p+l2;j++) stl[j]=b[i][j-p];
}
int check1(char stl[])
{
    int i;
    for(i=0;i<point;i++)
       if(strcmp(stl,s[i])==0) return 0;
    return 1;
}
void bfs()
{
    int i,t,k;
    char stl[45]={'\0'};
    while(f!=r&&step[r-1]<=10)
    {
         t=q[f];f++;
         for(i=1;i<n;i++)
         {
            k=check(i,t);
            if(k!=-1)
            {
                 strcpy(stl,s[t]);
                 exchange(i,t,k,stl);
                 if(strcmp(b[0],stl)==0)
                 {flag=0;printf("%d",step[t]+1);return;}
                 if(check1(stl))
                 {
                     strcpy(s[point],stl);
                     q[r]=point++;
                     step[r++]=step[t]+1;
                 }
            }
         }
            
    }
}
int main()
{
    int i;
    char x[24],y[24];
    freopen("noipg2.in","r",stdin);
    freopen("noipg2.out","w",stdout);
    scanf("%s %s",a[0],b[0]);
    for(i=1;scanf("%s %s",x,y)!=EOF;strcpy(a[i],x),strcpy(b[i],y),i++);
    n=i;
    strcpy(s[0],a[0]);
    bfs();
    if(flag) printf("NO ANSWER!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
