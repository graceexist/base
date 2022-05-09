#include<bits/stdc++.h>
using namespace std;

struct productions
{
    char lhs[20];
    char rhs[20];
}prod[10];

int main()
{
    //variable declaration
    int f,i,j,k,l,m,o,p,r;
    int np,tspos,stpos,cr;

    //take input
    cout<<"Enter no. of prod: ";
    cin>>np;

    char ts[10];

    cout<<"Enter the prod: \n";
    for(i=0;i<np;i++)
    {
        cin>>ts;
        strncpy(prod[i].lhs,ts,1);
        strcpy(prod[i].rhs,&ts[3]);
    }

    char ip[10];
    cout<<"Enter input: ";
    cin>>ip;

    int lip=strlen(ip);

    //initialise stack with 1st letter of input
    char stack[10],sc;

    stpos=0;
    i=0;

    sc=ip[i];
    stack[stpos]=sc;

    i++;
    stpos++;

    cout<<"\n\n Stack\tInput\tAction";
    cout<<"\n$\t"<<ip<<"$";

    do
    {
        r=1;
        while(r!=0)
        {
            //print stack
            cout<<"\n$";
            for(p=0;p<stpos;p++)
            {
                cout<<stack[p];
            }
            cout<<"\t";

            //print input
            for(p=i;p<lip;p++)
            {
                cout<<ip[p];
            }
            cout<<"$";

            //print action
            if(r==2)
            {
                cout<<"\t Reduced";
            }
            else
            cout<<"\t Shifted";

            r=0;

            //do reduce
            for(k=0;k<stpos;k++)
            {
                
                //set ts to \0
                for(l=0;l<10;l++)
                ts[l]='\0';

                tspos=0;

                //ts=stack
                for(l=k;l<stpos;l++)
                {
                    ts[tspos]=stack[l];
                    tspos++;
                }

                //compare ts and rhs of prod
                for(m=0;m<np;m++)
                {
                    cr=strcmp(ts,prod[m].rhs);

                    //if same prod found,then reduce
                    if(cr==0)
                    {
                        //remove rhs from stack
                        for(l=k;l<10;l++)
                        {
                            stack[l]='\0';
                            stpos--;
                        }
                        //reset stpos
                        stpos=k;
                        //add lhs to stack
                        strcat(stack,prod[m].lhs);
                        stpos++;
                        r=2;
                    }
                }

            }
        }
        //shift
        sc=ip[i];
        stack[stpos]=sc;
        i++;
        stpos++;

    }while(strlen(stack)!=1 && stpos!=lip);

    if(strlen(stack)==1)
    cout<<"\nAccepted";

    else
    cout<<"\nRejected";




    return 0;
}
