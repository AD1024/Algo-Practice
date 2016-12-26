#include<stdio.h>
int n,q[10]={0},p[10]={0},a[5]={0},t=0,t1=0,t2=0,t3=0;

int check()
{   
    int s,x1,x2,x3;
    if(t1>=1000)return 0;
    if(t2>=1000)return 0;
    if(t3>=10000)return 0;
    
    for(s=0;s<3;s++)
       {
            x1=t1%10;
            if(p[x1]==0)return 0;
            else t1/=10;
            
            x2=t2%10;
            if(p[x2]==0)return 0;
            else t2/=10;
       }
    for(s=0;s<=3;s++)
       {
            x3=t3%10;
            if(p[x3]==0)return 0;
            else t3/=10;
       }
    return 1;
}

void try(int i)
{
     int j,m,x;
        if(i==5)
          {
                m=100*a[0]+10*a[1]+a[2];
                t1=m*a[3];
                t2=m*a[4];
                t3=10*t2+t1;
                
                x=check();
                if(x==1)
                  t++;
          }
        else
          {     
                for(j=0;j<n;j++)
                  {
                      a[i]=q[j];
                       try(i+1);
                  }    
          }
}

int main()
{
    int f,x;
    freopen("alpha2.in","r",stdin);
    freopen("alpha2.out","w",stdout);
    
    scanf("%d",&n);
    
    for(f=0;f<n;f++)
        {
             scanf("%d",&q[f]);
             x=q[f];
             p[x]=1;
        }
    try(0);
    printf("%d",t);
    fclose(stdin);
    fclose(stdout);
    return 0;    
    
}
