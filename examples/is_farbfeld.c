#include <stdio.h>
#include <string.h>
#include <stdint.h>

int
main(int argc, char *argv[])
{
    FILE *a;
    char buf[9];
    a = fopen(argv[1], "r");

    fgets(buf, 9, a);
    printf("%s\n", buf);

    if (strcmp("farbfeld", buf)) {
        printf("yes\n");
        return 0;
    }
    else {
        printf("no\n");
        return 1;
    }
}
