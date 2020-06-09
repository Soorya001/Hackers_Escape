#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))
#define clear() printf("\e[1;1H\e[2J")
#define push() printf("\n\n\n\n\n\n")

int roundCount = 0;

void timer()
{
    int s = 30;
    // you can print the seconds integer here using printf()
    printf("%d..", s);
    while (1)
    {
        sleep(1);
        printf("%d..", s);
        s--;
        if (s == 0)
        {
            printf("Time's Up!!!");
            exit(0);
        }
    }
}

void celeb()
{
    clear();
    gotoxy(35, 5);
    printf("CONGRATS");
    gotoxy(33, 6);
    printf("------------");

    push();
    push();
}

void game()
{

    FILE *q;
    char dataToBeReadq[100]; //quesetion
    q = fopen("q.txt", "r");

    FILE *o;
    char dataToBeReado[100]; //options
    o = fopen("o.txt", "r");

    FILE *a;
    char dataToBeReada[100]; //answers
    a = fopen("a.txt", "r");

    int num = 0;
    int j = 0;
    while (j < 4)
    {

        int i, j;
        char cho, cha;
        char ans;
        int flag = 1;
        clear();
        gotoxy(25, 5);
        if (flag)
        {
            if (j == 0)
            {
                printf("You are inside the game now");
                gotoxy(23, 6);
                // fseek(o, 0, SEEK_SET);
            }
            printf("--------------------------------");

            //printf("%d",num);

            gotoxy(20, 8);

            i = 10;

            fgets(dataToBeReadq, 100, q); // printing question

            printf("%s", dataToBeReadq);

            gotoxy(16, i);
            //i++;
            int k = 0;
            char options[70];
            // while ((cho = getc(o)) != '\n') // printing options
            // {

            //     if (cho == '-')
            //     {
            //         i++;
            //         gotoxy(16, i);
            //     }
            //     else if (k == 100)
            //     {
            //         break;
            //     }
            //     else
            //         printf("%c", cho);
            //     k++;
            // )

            fscanf(o, "%[^\n]%*c", options);
            fseek(o, j + strlen(options), SEEK_SET);
            for (k = 0; k < strlen(options); k++)
            {
                if (options[k] == '-')
                {
                    i++;
                    gotoxy(16, i);
                }
                else
                    printf("%c", options[k]);
            }

            // //sleep(2) ;

            gotoxy(20, 15);
            printf("ENTER THE RIGHT OPTION TO GO TO THE NEXT ROUND!!");

            gotoxy(30, 17);
            printf("ANSWER: ");
            char optedAnswer;
            scanf("%s", &optedAnswer);
            // printf("%c", cha);

            fscanf(o, "%[^\n]%*c", &cha); // this is not working. thats why the condition below isnt working. if you are free, check this out!
            // sleep(3); // even this sleep function is not working
            push();

            if (optedAnswer == cha)
                printf("\n\n\t\t CORRECT ANSWER !!!");

            else
            {
                printf("\n\n\t\t\t WRONG ANSWER !!!");
                push();
                num = 1;
                flag = 0;
            }
            if (!flag)
            {
                push();
                printf("\t\t\tRETURNING TO HOME!\t\t\t");
                sleep(1);
            }
            // home() ;
            j++;
        }
    }
}

void home()
{

    char ch;

    ch = '\n';
    printf("\e[1;1H\e[2J");
    gotoxy(30, 5); // x and y respectively
    printf("WELCOME TO THE GAME");
    gotoxy(28, 6);
    printf("-----------------------\n\n\n\n\n");

    printf("\tThis is a questionnaire and trivia game , The Rules: \n\n\n\t 1. Each players gets 10 rounds \n\t 2. Each round contains one question along with options ,\n\t    one  of them will be the answer \n\t 3. The user gets 30 seconds to lock the answer \n\t 4. Each round has it own prize");

    printf("\n\n\n\t\t");

    printf("     PRESS ENTER TO CONTINUE ");
    scanf("%c", &ch);

    if (ch == '\n')
        game();

    //push() ;
}

int main()
{
    // used to clear the screen

    home();

    return 0;
}
