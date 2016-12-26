#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
  char a[100];
  char bc;      
}s[1000000];
struct way
{
  char a[21];
  char b[21];       
}change[7];
char end[21];
int f=1,r=1,n;
void open()
{
  freopen("noipg2.in","r",stdin);
  freopen("noipg2.out","w",stdout);     
}
void close()
{
  fclose(stdin);
  fclose(stdout);     
}
void init()
{
  int i;
  scanf("%s%s",s[f].a,end);
  for (i=1;scanf("%s%s",change[i].a,change[i].b)!=EOF;i++);
  n=i-1;   
}
int check(int way)
{
  return strstr(s[f].a,change[way].a)>0;
}
void changes(int way)
{
  int flag,len,len1,j=0,i;
  char l[100]={0};
  flag=strstr(s[f].a,change[way].a)-s[f].a;   
  len=strlen(change[way].a);
  len1=strlen(s[f].a);
  for (i=flag+len;i<len1;i++,j++)
    l[j]=s[f].a[i];
  strcpy(s[r].a,s[f].a);
  s[r].a[flag]=0;
  strcat(s[r].a,change[way].b);
  strcat(s[r].a,l);
  s[r].bc=s[f].bc+1;
}
int pd()
{
  int i;
  if (strcmp(s[r].a,end)==0) return 2;
  for (i=1;i<r;i++)
    if (strcmp(s[r].a,s[i].a)==0) return 1;
  return 0;    
}
void bfs()
{
  int i,b;
  do
  {
    for(i=1;i<=n;i++)
      if (check(i)==1)
      {
        r++;
        changes(i);
        b=pd();
        if (b==2)
        {
          printf("%d",s[r].bc);
          return ;         
        }         
        else if (b==1)
        {
          r--;
        }      
      }      
    f++;
  }while(f<=r && s[f].bc<=9);   
  printf("NO ANSWER!");  
}
int main()
{
  open();
  init();
  bfs();
  close();
  return 0;    
}
