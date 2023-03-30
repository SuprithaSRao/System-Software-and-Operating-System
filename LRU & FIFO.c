#include<stdio.h>
int main()
{
  int ch,yn=1,i,l,f;
  char F[10],s[25];
  printf("\n\n\tEnter the no of empty frames: ");
  scanf("%d",&f);
  printf("\n\n\tEnter the length of the string: ");
  scanf("%d",&l);
  printf("\n\n\tEnter the string: ");
  scanf("%s",s);
  do
  {
    printf("\n\n\t1:FIFO\n\n\t2:LRU \n\n\t3:EXIT");
    printf("\n\n\tEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: for(i=0;i<f;i++)
                F[i]=-1;
              fifo(s,F,l,f);
              break;
      case 2: for(i=0;i<f;i++)
              F[i]=-1;
              lru(s,F,l,f);
              break;
      case 3: exit(0);
}
printf("\n\n\tDo u want to continue \n\n\tIF YES PRESS 1\n\n\tIF NO PRESS 0 : ");
scanf("%d",&yn);
}while(yn==1);
}
void fifo(char s[],char F[],int l,int f)
{
  int i=0,j=0,k=0,flag=0,count=0;
  printf("\n\tPAGE\t FRAMES\t FAULTS");
  for(i=0;i<l;i++)
  {
    for(k=0;k<f;k++)
    {
      if(F[k]==s[i])
      flag=1;
    }
    if(flag==0)
    {
      printf("\n\t%c\t",s[i]);
      F[j]=s[i];
      j++;
      for(k=0;k<f;k++)
          printf(" %c",F[k]);
      printf("\tPage-fault%d",count);
      count++;
     }
    else
    {
      flag=0;
      printf("\n\t%c\t",s[i]);
      for(k=0;k<f;k++)
      printf(" %c",F[k]);
      printf("\tNo page-fault");
    }
    if(j==f)
      j=0;
  } //end of for
}
void lru(char s[],char F[],int l,int f)
{
  int i=0,j=0,k=0,flag=0,count=0,top=0,m;
  printf("\n\tPAGE\t FRAMES\t FAULTS");
  for(i=0;i<l;i++)
  {
    for(k=0;k<f;k++)
    {
      if(F[k]==s[i])
      {
        flag=1;
        break; } }
    printf("\n\t%c\t",s[i]);
    if(j!=f && flag!=1)
    {
      F[top]=s[i];
      j++;
      if(j!=f)
        top++;
    }
    else
    {
      if(flag!=1)
      {
        for(k=0;k<top;k++)
        {
          F[k]=F[k+1];
        }
        F[top]=s[i];
      }
      if(flag==1)
      {
        for(m=k;m<top;m++)
        {
          F[m]=F[m+1];
         }
        F[top]=s[i];
      }
  } //endof else
  for(k=0;k<f;k++)
  {
    printf(" %c",F[k]);
  }
  if(flag==0)
  {
    printf("\tPage-fault%d",count);
    count++;
  }
  else
  printf("\tNo page fault");
  flag=0;
  } //endof for
}
