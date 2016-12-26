#include <stdio.h>
int count=0,now=2,sum[100005]={0},num[100005][8]={0},temp[8]={0},hash[9][9][9][9][9][9][9][9]={0};
int change(int i)
{
  int temp1,temp2,j;
  if(i==1)
  {
    temp1=temp[0];temp[0]=temp[4];temp[4]=temp1;
    temp1=temp[1];temp[1]=temp[5];temp[5]=temp1;
    temp1=temp[2];temp[2]=temp[6];temp[6]=temp1;
    temp1=temp[3];temp[3]=temp[7];temp[7]=temp1;
  }
  if(i==2)
  {
    temp1=temp[1];
    temp[1]=temp[5];
    temp[5]=temp[6];
    temp[6]=temp[2];
    temp[2]=temp1;
  }
  if(i==3)
  {
     temp1=temp[3];
	 temp2=temp[7];
     for(j=2;j>=0;j--)
     {
      temp[j+1]=temp[j];
      temp[j+5]=temp[j+4];
      }
     temp[0]=temp1;
	 temp[4]=temp2;
     return 0;
  }
}
int main()
{
    freopen("act.in","r",stdin);
    freopen("act.out","w",stdout);
    int i,j,k;
    for(i=0;i<8;i++)
      scanf("%d",&num[1][i]);
    hash[num[1][0]][num[1][1]][num[1][2]][num[1][3]][num[1][4]][num[1][5]][num[1][6]][num[1][7]]=1;
    hash[1][2][3][4][8][7][6][5]=2;
    while(count!=now)
    {
      count++;
      for(i=1;i<=3;i++)
      {
        for(j=0;j<8;j++)temp[j]=num[count][j];
        change(i);
        sum[now]=sum[count]+1;
        if(hash[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]]==2)
        {
          printf("%d",sum[now]);
          fclose(stdin);
          fclose(stdout);
          return 0;
        } 
        if(hash[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]]==0)
        {
          hash[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]][temp[7]]=1;
          for(j=0;j<8;j++)num[now][j]=temp[j];
          now++;
        }
      }
    }
    printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
