#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *str;
} Strings;

int main()
{
    FILE *p1 = fopen("q.dat", "rb");
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

    fclose(p1);
    // fclose(p2);
    return 0;
}

// Who is the founder of C language?
// Who is the founder of C++ language?
// Who is the founder of Linux language?
// Who is the founder of Go language?
