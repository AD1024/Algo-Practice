#include<stdio.h>

int a[21]={0},road[21][21]={0},n,sum=0,max=0;

void try(int step)
{
     int i=step,j,t;
     
     sum+=a[step];
     t=a[step];
     a[step]=0;
    
     
     if(step==n)
        if(sum>max)
           max=sum;
     else
     {
     for(j=1;j<=n;j++)
       if(road[i][j])
        {
        road[i][j]=0;
        try(j);
        road[i][j]=1;
        }
    }
    
     a[step]=t; 
}

int main()
{
    int i,j;
    
    freopen("dig.in","r",stdin);
    freopen("dig.out","w",stdout);
    
    scanf("%d",&n);
    
    for(i=1;i<=n;i++)
     scanf("%d",&a[i]);
    
    for(i=1;i<=n;i++)
     for(j=i+1;j<=n;j++)
      {
       scanf("%d",&road[i][j]);
       road[j][i]=road[i][j];
      }
      
    for(i=1;i<=n;i++)
     try(i);
    
    printf("%d",max);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
