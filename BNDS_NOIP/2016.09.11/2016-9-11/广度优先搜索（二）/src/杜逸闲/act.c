#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define end {fclose(stdin);fclose(stdout);return 0;}
#define MAX_SIZE 100000
#define swap(a,b,c) {(c)=(a),(a)=(b),(b)=(c);}

char last[9]="12348765",arrange[MAX_SIZE][9]={'\0'},temp[9]={'\0'};
int step[MAX_SIZE]={0},r=1,f=0,t=0,q[MAX_SIZE]={0};

void go(int i)
{
     int j,k;
     char temp1,temp2;
	 strcpy(temp,arrange[q[f]]);
     
     switch(i)
     {
     case 1:
       for(j=0;j<=3;j++)
         swap(temp[j],temp[j+4],k);
       break;
     case 2:
       temp1=temp[3];
       temp2=temp[7];
       for(j=2;j>=0;j--)
       {
         temp[j+1]=temp[j];
         temp[j+5]=temp[j+4];
       }
       temp[0]=temp1;
       temp[4]=temp2;
       break;
     case 3:
       temp1=temp[1];
       temp[1]=temp[5];
       temp[5]=temp[6];
       temp[6]=temp[2];
       temp[2]=temp1;
       break;
     }
}

int check()
{
    int i;
    for(i=0;i<=t;i++)
      if(strcmp(arrange[i],temp)==0)
        return 0;
    return 1;
}

int bfs()
{
    int i,j;
    f++;
    for(i=1;i<=3;i++)
    {
      go(i);
      if(check())
      {
        strcpy(arrange[++t],temp);
        q[++r]=t;
        step[q[r]]=step[q[f]]+1;
      
      if(strcmp(arrange[q[r]],last)==0)
      {
        printf("%d",step[q[r]]);
        return 1;
      }
      }
    }
    return 0;
}

int main()
{
    int tempa;
    int i;
	freopen("act.in","r",stdin);
    freopen("act.out","w",stdout);
    
    for(i=0;i<8;i++)
    {
      
      scanf("%d",&tempa);
      tempa+='0';
      arrange[0][i]=tempa;                    
    }
    q[1]=0;
    while(bfs()==0);
    end;
}
