#include <stdio.h>
int a[11]={0},num[20]={0},t=0;
void prt()
{
  printf("   %d%d%d\n",num[1],num[2],num[3]);
  printf("  ¡Á%d%d\n",num[4],num[5]);
  printf("--------\n");
  printf("   %d%d%d\n",num[6],num[7],num[8]);
  printf("  %d%d%d\n",num[9],num[10],num[11]);
  printf("--------\n");
  printf("  %d%d%d%d\n",num[12],num[13],num[14],num[15]);
  printf("\n");
  t++;
}
int pan()
{
  num[16]=num[17]=num[18]=0;
  num[12]=num[9]=num[1]*num[4];
  num[15]=num[8]=num[3]*num[5];
  num[6]=num[1]*num[5];
  num[7]=num[2]*num[5];
  num[10]=num[2]*num[4];
  num[11]=num[3]*num[4];
  num[13]=num[6]+num[10];
  num[14]=num[7]+num[11];
  num[7]+=num[8]/10;
  num[8]%=10;
  num[6]+=num[7]/10;
  num[7]%=10;
  num[16]=num[6]/10;
  num[10]+=num[11]/10;
  num[11]%=10;
  num[9]+=num[10]/10;
  num[10]%=10;
  num[17]=num[9]/10;
  num[14]+=num[15]/10;
  num[15]%=10;
  num[13]+=num[14]/10;
  num[14]%=10;
  num[12]+=num[13]/10;
  num[13]%=10;
  num[18]=num[12]/10;
  if (a[num[6]]==1 && a[num[7]]==1 && a[num[8]]==1 && a[num[9]]==1)
    if(a[num[10]]==1 && a[num[11]]==1 && a[num[12]]==1 && a[num[13]]==1)
      if(a[num[14]]==1 && a[num[15]]==1 && num[16]==0 && num[17]==0 && num[18]==0)
          return 1;
  return 0;
} 
void eat(int i)
{
  int j;
  for (j=1;j<=9;j++)
  if (a[j]==1)
  {
    num[i]=j;
    if (i==5)
      if (pan())
        t++;
      else;
    else
      eat(i+1);
    num[i]=0;
  }
}
int main()
{
  int j,k,n;
  freopen("alpha2.in","r",stdin);
  freopen("alpha2.out","w",stdout);
  scanf("%d",&n);
  for (j=1;j<=n;j++)
  {
    scanf("%d",&k);
    a[k]=1;
  }
  eat(1);
  printf("%d\n",t);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
