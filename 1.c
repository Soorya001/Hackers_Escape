# include <stdio.h>
# include <stdlib.h>
# include<string.h>


# define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
# define clear() printf("\e[1;1H\e[2J")
# define push() printf("\n\n\n\n\n\n")


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
clear() ;
gotoxy(25,5) ;
printf("You are inside the game now") ;
gotoxy(23,6) ; printf("--------------------------------") ;


gotoxy(28,10) ; printf("PRESS ENTER TO CONTINUE") ;
char ch ;
scanf("%c" , &ch) ;
if (ch=='\n')
celeb() ;

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
//scanf("%c" , &ch) ;

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
