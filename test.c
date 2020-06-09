#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *str;
} Strings;

int main()
{
    FILE *p1 = fopen("a.txt", "w");
    Strings s1;

    // s1.str = "Who is the founder of C language?\n";
    // fwrite(&s1, sizeof(Strings), 1, p1);

    // s1.str = "Who is the founder of C++ language?\n";
    // fwrite(&s1, sizeof(Strings), 1, p1);

    // s1.str = "Who is the founder of Linux language?\n";
    // fwrite(&s1, sizeof(Strings), 1, p1);

    // s1.str = "Who is the founder of Go language?\n";
    // fwrite(&s1, sizeof(Strings), 1, p1);

    // fread(&s1, sizeof(Strings), 1, p1);
    fprintf(p1, "%s", "1\n");
    fprintf(p1, "%s", "3\n");
    fprintf(p1, "%s", "2\n");
    fprintf(p1, "%s", "4\n");

    fclose(p1);
    // fclose(p2);
    return 0;
}

// Who is the founder of C language?
// Who is the founder of C++ language?
// Who is the founder of Linux language?
// Who is the founder of Go language?
