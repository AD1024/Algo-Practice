#include <stdio.h>
int temps,tempz,tempf,i,n,m,k,count=0,now=2,coinz[4005],coinf[4005],hash[4005][4005]={0},sum[4005]={0};
int main()
{
   freopen("coin.in","r",stdin);
   freopen("coin.out","w",stdout);
   scanf("%d %d %d",&n,&m,&k);   
   coinz[1]=m;
   coinf[1]=n-coinz[1];
   while(count!=now)
   {
     count++;
     for(i=1;i<=k;i++)
     {
       tempz=coinz[count];
       tempf=coinf[count];
       if(coinf[count]>=k-i && coinz[count]>=i)
       {
         tempz+=k-i-i;
         tempf+=i+i-k;
         temps=sum[count]+1;
         if(tempz==0) 
         {
           printf("%d",temps);
           fclose(stdin);
           fclose(stdout);
           return 0;
         }
         if(hash[tempz][tempf]==0)  
         {      
           hash[tempz][tempf]=1;
           coinz[now]=tempz;
           coinf[now]=tempf;
           sum[now]=temps;
           now++;
         }
       }                 
     }  
    }   
    printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
