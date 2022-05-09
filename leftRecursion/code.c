#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

int main()
{
   int x;
   printf("Enter number of productions:");
   scanf("%d",&x);
   while(x>0)
   {
        char c,a[10][10];
        int n=1,i=0,j=0,k=0;


       printf("\nEnter the production:\n");
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
            
        c=a[0][0];
        if(a[0][2] == c)
        { 
        printf("Left recursion found: \n");
        printf("%c' -> ",c);
        for(k=3;k<strlen(a[0]) && a[0][k] != '|';k++)
        { 
            printf("%c",a[0][k]);
        } 
        printf("%c' | e",c);
        n=k; i=0;
        printf("\n%c ->",c);
        for(k=n+1; k<strlen(a[0]) && a[0][k]!='\0'; k++)
        {
            printf("%c",a[0][k]);
        }
        printf("%c'",c);
        }
        else{
            printf("No left recursion!!");
        } 
        x--;
   }

     
      return 0;
   }
