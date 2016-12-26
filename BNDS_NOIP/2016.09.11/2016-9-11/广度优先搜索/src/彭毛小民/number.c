#include <stdio.h>
#include <stdlib.h>
char link[5][10]={"","上","下","左","右"}; 
char start[10]={0},end[10]={0},a[10000000][10]={0},hash[9][9][9][9][9][9][9][9][9]={0};
int f=0,r=1,ans=0,father[10000000]={0},key[10000000]={0};
void open()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);     
}
void close()
{
  fclose(stdin);
  fclose(stdout);     
}
void init()
{
  int i;
  scanf("%d%d%d\n",start+1,start+2,start+3); 
  scanf("%d%d%d\n",start+4,start+5,start+6);
  scanf("%d%d%d\n",start+7,start+8,start+9);
  for (i=1;i<=9;i++)
    if (start[i]==0) break;
  start[0]=i;
  hash[start[1]][start[2]][start[3]][start[4]][start[5]][start[6]][start[7]][start[8]][start[9]]=1;
  scanf("%d%d%d\n",end+1,end+2,end+3);
  scanf("%d%d%d\n",end+4,end+5,end+6);
  scanf("%d%d%d\n",end+7,end+8,end+9);  
  for (i=1;i<=9;i++)
    if (end[i]==0) break;
  end[0]=i;
  if (hash[end[1]][end[2]][end[3]][end[4]][end[5]][end[6]][end[7]][end[8]][end[9]]==1)
  {
    printf("0");
    close();
    exit(0);                                                                                    
  }
  hash[end[1]][end[2]][end[3]][end[4]][end[5]][end[6]][end[7]][end[8]][end[9]]=2;
}
/*
  1-上
  2-下
  3-左
  4-右 
*/
int check(int ways,int p)
{
  if (ways==1)
  {
    if (p-3>0) return 1;           
  }    
  else if (ways==2)
  {
    if (p+3<=9) return 1;   
  }
  else if (ways==3)
  {
    if (p%3!=1) return 1;     
  }
  else if (ways==4)
  {
    if (p%3!=0) return 1;     
  }
  return 0; 
}
void change(char qian[],int ways,char hou[])
{
  int i,p1,p;
  for (i=0;i<=9;i++) hou[i]=qian[i];  
  p=hou[0];
  if (ways==1)
  {
    p1=p-3;
  }   
  else if (ways==2)
  {
    p1=p+3;     
  }
  else if (ways==3)
  {
    p1=p-1;     
  }
  else if (ways==4)
  {
    p1=p+1;    
  }
  hou[p]=hou[p1];
  hou[p1]=0;
  hou[0]=p1;
}
int checks(char ch[])
{
  int i,j,k=1;
  i=hash[ch[1]][ch[2]][ch[3]][ch[4]][ch[5]][ch[6]][ch[7]][ch[8]][ch[9]];    
  /*printf("fa=%d son=%d hash=%d\n",father[r],r,i);
  printf("%d %d %d\n",ch[1],ch[2],ch[3]);
  printf("%d %d %d\n",ch[4],ch[5],ch[6]);
  printf("%d %d %d\n",ch[7],ch[8],ch[9]);
  printf("\n");*/
  if (i==2) return 1;
  else if (i==1) return 2;
  else
  {
    /*printf("fa=%d son=%d\n",father[r],r);
    printf("%d %d %d\n",ch[1],ch[2],ch[3]);
    printf("%d %d %d\n",ch[4],ch[5],ch[6]);
    printf("%d %d %d\n",ch[7],ch[8],ch[9]);
    printf("\n");*/
    hash[ch[1]][ch[2]][ch[3]][ch[4]][ch[5]][ch[6]][ch[7]][ch[8]][ch[9]]=1;  
    return 0;  
  } 
}
void way(int i)
{
  if (father[i]==0) return ;
  way(father[i]);
  //printf("%s ",link[key[i]]);
  ans++;     
}
void print()
{
  int i;
  i=r;
  way(i);   
  printf("%d",ans);
}
void bfs()
{
  int i,b;
  f++;
  for (i=0;i<=9;i++) a[f][i]=start[i];
  do
  {
    for (i=1;i<=4;i++)
      if (check(i,a[f][0])==1)
      {
        r++;
        change(a[f],i,a[r]);
        father[r]=f;
        key[r]=i;
        b=checks(a[r]);
        if (b==1)
        {
          print();
          close();
          exit(0);
          return;         
        } 
        else if (b==2) 
        {
          r--;    
        }                    
      }
      f++;    
  }
  while(f<r);           
}
int main()
{
  open();
  init();
  bfs();
  printf("-1");
  close();
  return 0;    
}
