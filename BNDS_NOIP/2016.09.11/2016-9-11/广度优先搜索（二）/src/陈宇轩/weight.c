#include<stdio.h>
int k,sum=0;
int f[6]={1,2,3,5,10,20};

int main()
{
    int i;
    
    freopen("weight.in","r",stdin); 
    freopen("weight.out","w",stdout);
    
    scanf("%d",&k);
    
    for(i=5;i>=0;i--)
      sum+=k/f[i],k=k%f[i];
    
    printf("%d",sum);
    
    fclose(stdin);
    fclose(stdout);
    return 0;    
}
