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
    char dataToBeReadq[100];       // quesetion
    q = fopen("q.txt","r");

    FILE *o;
    char dataToBeReado[100];       //options
    o = fopen("o.txt","r");

    FILE *a;
    char dataToBeReada[100];      //answers
    a = fopen("a.txt","r");

    char ch[50];
    int i,j;

    char ch2 ;
    char ch3 ;


    clear() ;
    gotoxy(25,5) ;
    printf("You are inside the game now") ;
    gotoxy(23,6) ; printf("--------------------------------") ;
    srand(time(0));
    int num = 0;
    printf("%d",num);

    gotoxy(20,8);
    if (q!=NULL && o!=NULL && a!=NULL)
    {
        i=10;
        j=0;
        while(fgets(dataToBeReadq,100,q)!=NULL){
            if (num==j){
            printf( "%s" , dataToBeReadq ) ;
            gotoxy(16,i);
            //i++;
            break;
            }
            else
            j++;
        }
        j=0;

          while((ch2 = getc(o))!='\n') {
            if (num==j){

                if (ch2 == '-') { i++ ; gotoxy(16,i) ;}
                else
                printf("%c" , ch2) ;

            }
            else
            j++;
    }

        fclose(q);
        fclose(o);

        gotoxy(20,15) ; printf("ENTER THE RIGHT OPTION TO GO TO THE NEXT ROUND!!") ;
        gotoxy(30,17) ; printf("ANSWER: ") ;


        scanf("%c" , &ch3) ;


        j=0;
        while((ch2 = getc(a))!='\n'){

              if (num==j && ch2 == ch3 ) {
                celeb() ;
                //continue ;
                }
            else {
                printf("\n\n\t\t\t WRONG ANSWER !!!") ;
                push() ;
                j++;   }
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

