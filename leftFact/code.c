#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	char lhs[20][20],rhs[20][20][20],temp[20],temp1[20];
	int n,n1,count[20],x,y,i,j,k,c[20];
	printf("\nEnter the no. of nonterminals : ");
	scanf("%d",&n);
	n1=n;
	for(i=0;i<n;i++)
	{
		printf("\nNonterminal %d \nEnter the no. of productions : ",i+1);
		scanf("%d",&c[i]);
        //c[i]=no. of prod for each non terminal
		printf("\nEnter LHS : ");
		scanf("%s",lhs[i]);
		for(j=0;j<c[i];j++)
		{
			printf("%s->",lhs[i]);
			scanf("%s",rhs[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		count[i]=1;
        //comparing the count of elements with same alpha
		while(memcmp(rhs[i][0],rhs[i][1],count[i])==0)
			count[i]++;
	}
	for(i=0;i<n;i++)
	{
		count[i]--;
		if(count[i]>0)
		{
            //lhs n1 stores A prod and [i] store A'
			strcpy(lhs[n1],lhs[i]);
			strcat(lhs[i],"'");
			for(k=0;k<count[i];k++)
            {
                //temp1[k] stores alpha
                temp1[k] = rhs[i][0][k];
               // printf("%c",temp1[k]);

            }
				
			temp1[k++] = '\0';
			for(j=0;j<c[i];j++)
			{
				for(k=count[i],x=0;k<strlen(rhs[i][j]);x++,k++)
                {
                    temp[x] = rhs[i][j][k];
                   //temp[X] stores beta1,beta2
                //printf("%c",temp[x]);
                }
					
				temp[x++] = '\0';
                
				if(strlen(rhs[i][j])==1)
					strcpy(rhs[n1][1],rhs[i][j]);
                    //rhs[n1][1]= A->B where b has no left fact - rhs for A
                    //rhs[i][j] = rhs of A'
                // printf("\nnewline1:%s",rhs[n1][1]);
				strcpy(rhs[i][j],temp);
                // printf("\nnewline2:%s",rhs[i][j]);
			}
			c[n1]=2;
            
			strcpy(rhs[n1][0],temp1);
            //rhs[n1][0]=alpha
           
			strcat(rhs[n1][0],lhs[n1]);
             //rhs[n1][0]=alphaA
            
			strcat(rhs[n1][0],"'");
            //rhs[n1][0]=alphaA'
			n1++;
		}
	}
	printf("\n\nThe resulting productions are : \n");
	for(i=0;i<n1;i++)
	{
		
			printf("\n %s -> ",lhs[i]);
		for(j=0;j<c[i];j++)
		{
			printf(" %s ",rhs[i][j]);
			if((j+1)!=c[i])
				printf("|");
		}
		printf("\b\b\b\n");
	}
    return 0;
}
