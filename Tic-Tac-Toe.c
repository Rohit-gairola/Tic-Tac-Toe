
// TIC-TAC-TOE mini project

#include<stdio.h>
#include<string.h>
#include<process.h>
void display(char index[]);
void ind(char X[],char O[]);
void pak(char X[],char O[]);
int check_for_X(char *index,char A[],int *p1,int *p2);
int check_for_O(char *index,char B[],int *p1,int *p2);
int main()
{
    system("COLOR 0E");
   char X[20],O[20],p[20],count;
   int n;
   printf("Enter the name of player X\n");
   gets(X);
   printf("Enter the name of player O\n");
   gets(O);
   printf("Enter the name of the player Who will play first in the game :Player %s or %s ?\n",X,O);
   gets(p);
   if(strlen(X)<20 || strlen(O)<20 || strlen(p)<20)
   {
        if(strcmp(p,X)==0)
        {
            printf("\n%s will start first\n",X);
            ind(X,O);
        }
        else if(strcmp(p,O)==0)
        {
            printf("%s will start first\n",O);
            pak(X,O);
        }
        else
        {
            printf("Error! Wrong input. This name dosen't matches the name of any players\n");
            exit(0);
        }

   }
   else
   {
       exit(0);
   }
    return 0;
}


void display(char index[])
{
    printf("\t\t\t\t\t      TIC--TAC--TOE");
    printf("\n\n\n");
    printf("\n\t\t\t\t\t       |        |");
    printf("\n\t\t\t\t\t     %c |      %c |      %c",index[0],index[1],index[2]);
    printf("\n\t\t\t\t\t_______|________|________");
    printf("\n\t\t\t\t\t       |        |");
    printf("\n\t\t\t\t\t     %c |      %c |      %c",index[3],index[4],index[5]);
    printf("\n\t\t\t\t\t_______|________|________");
    printf("\n\t\t\t\t\t       |        |");
    printf("\n\t\t\t\t\t     %c |      %c |      %c",index[6],index[7],index[8]);
    printf("\n\t\t\t\t\t       |        |");
    printf("\n\n\n\n");
}




void ind(char X[],char O[])
{
    int pos,i,c1=0,c2=0,*p1,*p2;
    p1=&c1;
    p2=&c2;
    char A[20],B[20],*rip;
    strcpy(A,X);
    strcpy(B,O);
    char index[9]={'0','1','2','3','4','5','6','7','8'};
    rip=&index;
    display(index);
    for(i=0;i<5;i++)
    {
        if(i==0||i==1)
        {
            printf("Player %s , Enter the position you want to mark \n",X);
            scanf("%d",&pos);
            index[pos]='X';
            display(index);
            printf("Player %s , Enter the position you want to mark \n",O);
            scanf("%d",&pos);
            index[pos]='O';
            display(index);
        }
        else if(i==2||i==3)
        {
            printf("Player %s , Enter the position you want to mark \n",X);
            scanf("%d",&pos);
            index[pos]='X';
            display(index);
            check_for_X(rip,A,p1,p2);
            if(*p1==1)
            {
                exit(0);
            }
            printf("Player %s , Enter the position you want to mark \n",O);
            scanf("%d",&pos);
            index[pos]='O';
            display(index);
            check_for_O(rip,B,p1,p2);
            if(*p2==1)
            {
                exit(0);
            }
        }
        else
        {
            printf("Player %s , Enter the position you want to mark \n",X);
            scanf("%d",&pos);
            index[pos]='X';
            display(index);
            check_for_X(rip,A,p1,p2);
        }
    }
    if(*p1==*p2)
    {
        printf("The match is a tie\n GAME OVER \n");
    }
}


void pak(char X[],char O[])
{
    int pos,i,c1=0,c2=0,*p1,*p2;
    char A[20],B[20],*rip;
    strcpy(A,X);
    strcpy(B,O);
    p1=&c1;
    p2=&c2;
    char index[9]={'0','1','2','3','4','5','6','7','8'};
    rip=&index;
    display(index);
    for(i=0;i<5;i++)
    {
        if(i==0||i==1)
        {
            printf("Player %s , Enter the position you want to mark \n",O);
            scanf("%d",&pos);
            index[pos]='O';
            display(index);
            printf("Player %s , Enter the position you want to mark \n",X);
            scanf("%d",&pos);
            index[pos]='X';
            display(index);
        }
        else if(i==2||i==3)
        {
            printf("Player %s , Enter the position you want to mark \n",O);
            scanf("%d",&pos);
            index[pos]='O';
            display(index);
            check_for_O(rip,B,p1,p2);
            if(*p2==1)
            {
                exit(0);
            }
            printf("Player %s , Enter the position you want to mark \n",X);
            scanf("%d",&pos);
            index[pos]='X';
            display(index);
            check_for_X(rip,A,p1,p2);
            if(*p1==1)
            {
                exit(0);
            }
        }
        else
        {
            printf("Player %s , Enter the position you want to mark \n",O);
            scanf("%d",&pos);
            index[pos]='O';
            display(index);
            check_for_O(rip,B,p1,p2);
        }
    }
    if(*p1==*p2||*p2==*p1)
    {
        printf("The match is a tie\n GAME OVER \n");
    }
}


int check_for_X(char *index,char A[],int *p1,int *p2)
{
    int i;
    for(i=0;i<7;i=i+3)
    {
        if(index[i]=='X' && index[i+1]=='X' && index[i+2]=='X')
        {
          printf("CONGRATULATIONS!  %s, you win the game\n GAME OVER ",A);
          *p1=1;
          *p2=0;
        }
    }
    for(i=0;i<3;i++)
    {
        if(index[i]=='X' && index[i+3]=='X' && index[i+6]=='X')
        {
            printf("CONGRATULATIONS!  %s, you win the game\n GAME OVER ",A);
            *p1=1;
            *p2=0;
        }
    }
    for(i=0;i<3;i=i+2)
    {
        if(i==0)
        {
            if(index[i]=='X' && index[i+4]=='X' && index[i+8]=='X')
            {
                printf("CONGRATULATIONS!  %s, you win the game\n GAME OVER ",A);
                *p1=1;
                *p2=0;
            }
        }
        else
        {
            if(index[i]=='X' && index[i+2]=='X' && index[i+4]=='X')
            {
                printf("CONGRATULATIONS!  %s, you win the game\n GAME OVER ",A);
                *p1=1;
                *p2=0;
            }
        }
    }
}



int check_for_O(char *index,char B[],int *p1,int *p2)
{
    int i;
    for(i=0;i<7;i=i+3)
    {
        if(index[i]=='O' && index[i+1]=='O' && index[i+2]=='O')
        {
            printf("CONGRATULATIONS!  %s, you win the game\n GAME OVER ",B);
            *p1=0;
            *p2=1;
        }
    }
    for(i=0;i<3;i++)
    {
        if(index[i]=='O' && index[i+3]=='O' && index[i+6]=='O')
        {
            printf("CONGRATULATIONS!  %s, you win the game\n GAME OVER ",B);
            *p1=0;
            *p2=1;
        }
    }
    for(i=0;i<3;i=i+2)
    {
        if(i==0)
        {
            if(index[i]=='O' && index[i+4]=='O' && index[i+8]=='O')
            {

                printf("CONGRATULATIONS!  %s, you win the game\n GAME OVER ",B);
                *p1=0;
                *p2=1;
            }
        }
        else
        {
            if(index[i]=='O' && index[i+2]=='O' && index[i+4]=='O')
            {

                printf("CONGRATULATIONS!  %s, you win the game\n GAME OVER ",B);
                *p1=0;
                *p2=1;
            }
        }
    }
}

