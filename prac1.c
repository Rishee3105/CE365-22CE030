#include<stdio.h>
#include<string.h>

int solve(char arr[],int n)
{
    if(arr[0]!='a')
    {
      return 0;
    }

    int count=0;
    for(int i=0;i<n;i++)
    {
      if(arr[i]=='b')
      {
        count++;
      }
    }
    
    if(count!=2 || arr[n-1]!='b' || (arr[n-1]=='b' && arr[n-2]!='b') || arr[n-3]=='b')
    {
      return 0;
    }
    return 1;
}


int main()
{
  char arr[100];
  printf("Enter string:");
  gets(arr);
 
  int flag=0;
  int n=strlen(arr);
  flag=solve(arr,n);

  if(flag)
  {
    printf("String is valid");
  }
  else
  {
    printf("String is Invalid");
  }
}