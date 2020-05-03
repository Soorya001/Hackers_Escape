# include <stdio.h>
# include <stdlib.h>
# include<string.h>
#include <unistd.h>
#include<time.h>


# define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
# define clear() printf("\e[1;1H\e[2J")
# define push() printf("\n\n\n\n\n\n")

int roundCount = 0;

void timer()
{
    int s=30;
    // you can print the seconds integer here using printf()
    printf("%d..",s);
    while(1)
    {
        sleep(1);
        printf("%d..",s);
        s--;
        if(s==0)
        {
            printf("Time's Up!!!");
            exit(0);
        }
    }
}


void celeb()
{
    clear() ;
    gotoxy(35,5) ;
    printf("CONGRATS") ;
    gotoxy(33,6) ; printf("------------") ;

    push() ; push() ;

}

void game()
{
    FILE *q;
    char dataToBeReadq[100];
    q = fopen("q.txt","r");
    FILE *o;
    char dataToBeReado[100];
    o = fopen("o.txt","r");
    FILE *a;
    char dataToBeReada[100];
    a = fopen("a.txt","r");
    char ch[50];
    int i,j;




    clear() ;
    gotoxy(25,5) ;
    printf("You are inside the game now") ;
    gotoxy(23,6) ; printf("--------------------------------") ;
    srand(time(0));
    int num = 0; 
    printf("%d",num);

    gotoxy(25,8);
    if (q!=NULL && o!=NULL && a!=NULL)
    {
        i=9;
        j=0;
        while(fgets(dataToBeReadq,100,q)!=NULL){
            if (num==j){
            printf( "%s" , dataToBeReadq ) ;
            gotoxy(25,i);
            i++;
            break;
            }
            else
            j++;
        }
        j=0;
        while(fgets(dataToBeReado,100,o)!=NULL){
            if (num==j){
                printf("%s",dataToBeReado);
                break;
            }
            else
            j++;
    }


        fclose(q);
        fclose(o);


        gotoxy(20,15) ; printf("ENTER THE RIGHT ANSWER TO GO TO THE NEXT ROUND!!") ;

        gotoxy(30,16) ; ;
        scanf("%[^\n]%*c" , ch) ;


        
        j=0;
        while(fgets(dataToBeReada,50,a)!=NULL){
            printf("%s ",dataToBeReada);
            if (num==j && strcmp(ch,dataToBeReada)==0){
                celeb() ;
                break;
            }
            else
                j++;
        }
    }

}



void home()
{


    char ch ;

    ch = '\n' ;
    printf("\e[1;1H\e[2J") ;
    gotoxy(30,5) ;              // x and y respectively
    printf("WELCOME TO THE GAME" ) ;
    gotoxy(28,6) ;
    printf("-----------------------\n\n\n\n\n") ;


    printf("\tThis is a questionnaire and trivia game , The Rules: \n\n\n\t 1. Each players gets 10 rounds \n\t 2. Each round contains one question along with options ,\n\t    one  of them will be the answer \n\t 3. The user gets 30 seconds to lock the answer \n\t 4. Each round has it own prize") ;

    printf("\n\n\n\t\t") ;


    printf("     PRESS ENTER TO CONTINUE ") ;
    scanf("%c" , &ch) ;

    if (ch=='\n')
    game() ;

    //push() ;

}


int main()
{
    // used to clear the screen

    home() ;

    return 0 ;
}

