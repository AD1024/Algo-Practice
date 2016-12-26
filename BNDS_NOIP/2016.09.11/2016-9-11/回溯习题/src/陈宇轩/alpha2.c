#include<stdio.h>
int a[10]={0},sum=0;
int calcu[6]={0};

int check()
{
    int i,calcu_1,calcu_2,calcu_3;
    int n= calcu[1]*100 + calcu[2]*10+ calcu[3];    
    
    calcu_1=n*calcu[5];
    if(calcu_1>=1000)return 0;
    calcu_2=n*calcu[4];
    if(calcu_2>=1000)return 0;
    calcu_3=calcu_1+calcu_2*10;
    if(calcu_3>=10000)return 0;
    
    for(i=1;i<=3;i++)
    {
      int flag,t1,t2,t3,j;
      t1=calcu_1%10;
      t2=calcu_2%10;
      t3=calcu_3%10;
      
      if(a[t1]==0)return 0;
      if(a[t2]==0)return 0;
      if(a[t3]==0)return 0;
           
      calcu_1/=10;
      calcu_2/=10;
      calcu_3/=10;     
                     }
                     
      
      if(a[calcu_3]==0)return 0;
                             
      return 1;
}

void catch(int step)
{
     int i,j;
     
     for(i=1;i<=9;i++)
      if(a[i]==1)
      {
         calcu[step]=i;        
         
         if(step==5)
           {
           if(check())
             sum++;
             }
         else
           catch(step+1);        
      }
}

int main()
{
    int t,i,n;
    
    freopen("alpha2.in","r",stdin);
    freopen("alpha2.out","w",stdout);
    
    scanf("%d",&n);
    
    for(i=1;i<=n;i++)
   {
     scanf("%d",&t);
     a[t]=1;                
   }
   
    catch(1);
    
    printf("%d",sum);
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
