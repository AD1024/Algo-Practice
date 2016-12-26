#include<stdio.h>
#include<stdlib.h>
int a[20][20]={0},b[101]={0},n,t=0;
void prt()
{
int p,q;
for(p=1;p<=n;p++)
{
for(q=1;q<=n;q++)
printf("%d ",a[p][q]);
printf("\n");
}
printf("\n");                      
}
void check1()
{
int flag=0,p,q,s=0;
for(p=1;p<=n;p++)
{
s=0;
for(q=1;q<=n;q++)
s+=a[q][p];
if(s!=t)
{
flag=1;
break;        
}                 
}     
s=0;
for(p=1;p<=n;p++)
s+=a[p][p];
if(s!=t) flag=1;
s=0;
for(p=1;p<=n;p++)
s+=a[p][n-p+1];
if(s!=t) flag=1;
if(flag==0) prt();
else return ;
}
int check2(int i)
{
int s=0,p;
for(p=1;p<=n;p++)
s+=a[i][p];
if(s!=t) return 0;
else return 1;    
}
void f(int i,int j)
{
    int m;
    for(m=1;m<=n*n;m++)
    if(b[m]==0)
    {
        b[m]=1;
        a[i][j]=m;
        if(i==n&&j==n) check1();
        else
        {
            if(j==n)
            {
               if(check2(i)) f(i+1,1);
            }
            else f(i,j+1);
        }
        a[i][j]=0;
        b[m]=0;
    } 
}
int main()
{
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
scanf("%d",&n);
t=n*(n*n+1)/2;
f(1,1);
fclose(stdin);
fclose(stdout);
return 0;    
}
