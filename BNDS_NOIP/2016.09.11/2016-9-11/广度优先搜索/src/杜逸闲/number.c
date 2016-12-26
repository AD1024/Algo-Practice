#include <stdio.h>
#include <stdlib.h>

#define swap(a,b,k) {(k)=(a),(a)=(b),(b)=(k);}
#define end {fclose(stdin);fclose(stdout);return 0;}

char space[100000]={"\0"},last[10]={"\0"},seat[100000][10]={"\0"};
int step=0,now=0,k,sum=0;

int check(int i,int location)
{
    sum++;
    switch(i)
    {
      case 1:
        if(location>=3)
          return 1;
      case 2:
        if(location<=5)
          return 1; 
      case 3:      
        if(location%3!=0)
          return 1;
      case 4:
        if(location%3!=2)
          return 1;  
    } 
    return 0;
}

void go(int i)
{
     now++;
     strcpy(seat[now],seat[now-1]);
     space[now]=space[now-1];
     switch(i)
     {
       case 1:
         swap(seat[now][space[now]],seat[now][space[now]=space[now]-3],k);
         break;
       case 2:
         swap(seat[now][space[now]],seat[now][space[now]=space[now]+3],k);
         break;
       case 3:
         swap(seat[now][space[now]],seat[now][space[now]=space[now]-1],k);
         break;
       case 4:
         swap(seat[now][space[now]],seat[now][space[now]=space[now]+1],k);  
         break;
     }
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i,j;
    for(i=0;i<=8;i++)
    {
      scanf("%d",&seat[0][i]);
      seat[0][i]+='0';
      if(seat[0][i]=='0')
        space[0]=i;
    }
    for(i=0;i<=8;i++)
    {
      scanf("%d",&last[i]);
      last[i]+='0';
    }
    while(step<=30)
    {
      step++;
      for(i=1;i<=4;i++)
        if(check(i,space[now]))
        {
          go(i);
          if(strcmp(seat[now],last)==0)
          {
            printf("%d",sum);
            end;
          }
          for(j=1;j<now;j++)
            if(strcmp(seat[now],seat[j])==0)
            {
              sum--;
              now--;
            }
        }
    }
    printf("No answer!");
    end;
}
